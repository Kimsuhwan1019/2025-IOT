includes Test;
configuration TestAppC
{
}
implementation
{
// 메인 컴포넌트
  components TestC, MainC;
  components LedsC, new TimerMilliC();

// 무선 통신 컴포넌트
  components ActiveMessageC as AMC;
  components new AMSenderC(AM_TEST_DATA_MSG) as AMSC;

// 기본 인터페이스 연결
  TestC.Boot -> MainC;
  TestC.Leds -> LedsC;
  TestC.MilliTimer -> TimerMilliC;

// 무선 통신 연결
  TestC.RadioControl -> AMC;
  TestC.RadioSend -> AMSC;

// 온도/습도 센서 연결
  components new SensirionSht11C() as Sht11ChOC;
  TestC.Temp -> Sht11ChOC.Temperature;
  TestC.Humi -> Sht11ChOC.Humidity;

// 조도 센서 연결
  components new IlluAdcC() as Illu;
  TestC.Illu -> Illu;

// 배터리 센서 연결
  components BatteryC;
  TestC.Battery -> BatteryC;
}
