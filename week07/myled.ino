// LedToggle 라이브러리를 사용한 LED 깜빡임 제어
// 내장 LED를 0.5초 간격으로 켜고 끄는 프로그램

#include <LedToggle.h>

// 내장 LED 핀을 사용하여 LedToggle 객체 생성
LedToggle led(LED_BUILTIN);

void setup() {
// 초기화 코드 없음 (LedToggle 생성자에서 핀 모드 설정)
}

void loop() {
  // LED 상태 토글 (켜져있으면 끄고, 꺼져있으면 켬)
  led.toggle();
  // 0.5초 대기
  delay(500);
}
