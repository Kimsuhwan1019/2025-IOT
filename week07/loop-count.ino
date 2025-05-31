// millis() 함수를 사용한 루프 카운터
// 1초마다 루프 실행 횟수를 출력하고 카운터를 리셋하는 프로그램
// delay() 함수를 사용하지 않는 논블로킹 방식

void setup(){

  // 시리얼 통신 초기화 (115200 baud rate)
  Serial.begin(115200);
  Serial.println();
}

void loop(){

  // static 변수로 함수 호출 간에도 값이 유지됨
  static unsigned long loopCnt = 0;                // 루프 실행 횟수 카운터
  static unsigned long nextMil = millis() + 1000;  // 다음 출력 시

  // 루프 실행 횟수 증가
  loopCnt++;

  // 현재 시간이 다음 출력 시간을 넘었는지 확인
  if ( millis() > nextMil){
    // 다음 출력 시간을 1초 후로 설정
    nextMil = millis() + 1000;
    // 현재까지의 루프 카운트 출력
    Serial.println(loopCnt);
    // 카운터 초기화
    loopCnt = 0;
  }
}
