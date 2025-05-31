// 센서 데이터 수집 및 전송 메인 모듈
module TestC
{
  uses {
    interface Boot;
    interface Leds;
    interface Timer<TMilli> as MilliTimer;

    interface SplitControl as RadioControl;
    interface AMSend as RadioSend;

    interface Read<uint16_t> as Temp;
    interface Read<uint16_t> as Humi;
    interface Read<uint16_t> as Illu;

    interface Battery;
  }
}
implementation
{
  message_t testMsgBffr;    // 메세지 버퍼
  test_data_msg_t *testMsg; // 센서 데이터 메시지

  uint32_t seqNo;           // 순차 번호
  uint8_t step;             // 센서 읽기 단계(0:온도, 1:습도, 2:조도, 3:배터리)

  task void startTimer();

// 시스템 부팅 완료 - 초기화 및 타이머 시작
  event void Boot.booted() {
    testMsg = (test_data_msg_t *)call RadioSend.getPayload(
       &testMsgBffr, sizeof(test_data_msg_t));
    testMsg->srcID = TOS_NODE_ID;

    seqNo = 0;

    post startTimer();
  }

// 주기적 타이머 시작 (10.24초 간격)
  task void startTimer() {
    call MilliTimer.startPeriodic(TEST_PERIOD);
  }

  task void radioOn();

// 타이머 만료 - 라디오 켜기
  event void MilliTimer.fired() {
    post radioOn();
  }
  void startDone();

// 라디오 활성화
  task void radioOn() {
    if ((call RadioControl.start() != SUCCESS)) startDone();
  }

// 라디오 시작 완료 - 센서 읽기 시작
  event void RadioControl.startDone(error_t error) {
    startDone();
  }

  task void readTask();

// 센서 읽기 시작 (LED0 토글)
  void startDone() {
    step = 0;
    post readTask();
    call Leds.led0Toggle();
  }

  void sendDone();

// 센서 데이터 전송 (브로드캐스트)
  task void sendTask() {
    testMsg->seqNo = seqNo++;
    testMsg->type = 2; //THL type 2

    if ((call RadioSend.send(AM_BROADCAST_ADDR, &testMsgBffr,
                           sizeof(test_data_msg_t)) != SUCCESS)) sendDone();
    call Leds.led2Toggle();
  }

// 전송 완료 - 정리 작업
  event void RadioSend.sendDone(message_t* msg, error_t error) {
    sendDone();
  }

  task void radioOff();

// 전송 완료 후 LED 끄고 라디오 비활성화
  void sendDone() {
    call Leds.led0Off();
    call Leds.led1Off();
    call Leds.led2Off();
    post radioOff();
  }

  void stopDone();

// 라디오 비활성화 (전력 절약)
  task void radioOff() {
    if ((call RadioControl.stop() != SUCCESS)) stopDone();
  }

// 라디오 정지 완료
  event void RadioControl.stopDone(error_t error) {
    stopDone();
  }

  void stopDone() {
  }

// 센서 순차 읽기 (온도→습도→조도→배터리)
  task void readTask() {
    switch(step) {
      case 0:
        call Temp.read();
        break;
      case 1:
        call Humi.read();
        break;
      case 2:
        call Illu.read();
        break;
      default:
        testMsg->battery = call Battery.getVoltage();
        post sendTask();
        break;
    }
    step += 1;
  }

// 온도 센서 읽기 완료
  event void Temp.readDone(error_t error, uint16_t val) {
    //if (error != SUCCESS) call Leds.led0On();
    testMsg->Temp = error == SUCCESS ? val : 0xFFFA;
    post readTask();
  }

// 습도 센서 읽기 완료
  event void Humi.readDone(error_t error, uint16_t val) {
    //if (error != SUCCESS) call Leds.led1On();
    testMsg->Humi = error == SUCCESS ? val : 0xFFFB;
    post readTask();
  }

// 조도 센서 읽기 완료
  event void Illu.readDone(error_t error, uint16_t val){
    testMsg->Illu = error == SUCCESS ? val : 0xFFFC;
    post readTask();
  }
}
