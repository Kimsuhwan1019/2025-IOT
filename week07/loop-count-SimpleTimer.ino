// SimpleTimer 라이브러리를 사용한 루프 카운터
// 1초마다 루프 실행 횟수를 출력하고 카운터를 리셋하는 프로그램

#include <SimpleTimer.h>

// SimpleTimer 객체 생성
simpleTimer timerCnt;

// 루프 실행 횟수를 저장할 변수
unsigned long loopCnt;


// 타이머 콜백 함수
// 1초마다 실행되어 루프 카운트를 출력하고 초기화
void timerCntFunc() {

  // 현재까지의 루프 카운트 출력
  Serial.println(loopCnt);

  // 카운터 초기
  loopCnt = 0;
}

void setup() {

  // 시리얼 통신 초기화 (115200 baud rate)
  Serial.begin(115200);
  Serial.println();

  // 1초(1000ms) 간격으로 timerCntFunc 함수 실행하도록 설정
  timerCnt.setInterval(1000, timerCntFunc);
}

void loop(){

  // 타이머 실행 (콜백 함수 처리)
  timerCnt.run();

  // 루프 실행 횟수 증
  loopCnt++;
}
