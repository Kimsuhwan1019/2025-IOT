// I2C LCD 1602 디스플레이 제어 프로그램
// "Hello World!" 메시지를 좌우로 스크롤하여 표시

#include <Wire.h>					     	// IC2 통신을 위한 기본 라이브러리
#include <LiquidCrystal_I2C.h>  // I2C LCD 라이브러리

// LCD 객체 생성 (주소: 0x27, 크기: 16x2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup(){
  // === LCD 초기화 과정 ===
  lcd.init();							    // I2C LCD 초기화 및 설정
  lcd.backlight();						// 백라이트 켜기

  // 초기화 완료 메시지 표시
  lcd.print("LCD init");
  delay (2000);               // 2초간 메시지 표시
  lcd.clear();                // 화면 지우기
}

void loop(){
  // === 스크롤 텍스트 표시 ===

  // 커서를 우측 끝(16번째 위치, 첫 번째 줄)으로 이동
  // 좌측으로 스크롤할 준비
  lcd.setCursor(16, 0);
  lcd.print("Hello World!");   // 텍스트 출력 (화면 밖에서 시작)

  // 16칸만큼 좌측으로 스크롤 (텍스트가 완전히 지나갈 때까지)
  for (int position = 0; position < 16; position++)
  {
    lcd.scrollDisplayLeft();    // 화면 전체를 왼쪽으로 한 칸 이동
    delay(150);                 // 스크롤 속도 조절 (150ms 간격)
  }  

  // 스크롤이 끝나면 다시 처음부터 반복
  // 텍스트가 우측에서 나타나 좌측으로 사라지는 효과
}
