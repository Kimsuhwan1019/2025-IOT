# I2C LCD 1602 제어 프로젝트

Arduino를 이용한 I2C LCD 1602 디스플레이 제어 및 주소 검색 도구 모음입니다.

## 📋 프로젝트 개요

이 프로젝트는 Arduino와 I2C LCD 1602 디스플레이를 연동하여 텍스트를 표시하고 제어하는 시스템입니다. I2C 통신을 사용하여 최소한의 핀(SDA, SCL)만으로 LCD를 제어할 수 있습니다.

## 📁 파일 구성

### 1. LCD_address.ino
- **목적**: I2C 장치 주소 자동 검색
- **기능**: 연결된 I2C 장치들의 주소를 스캔하여 시리얼 모니터에 출력
- **사용 시점**: 새로운 I2C LCD 연결 시 주소 확인용

### 2. LCD_display.ino
- **목적**: I2C LCD 기본 제어 및 스크롤 텍스트 표시
- **기능**: "Hello World!" 메시지를 좌우로 스크롤하여 표시
- **사용 시점**: LCD 동작 테스트 및 기본 사용법 학습용

## 🔧 하드웨어 구성

### 필요한 부품
- Arduino 보드 (Uno, Nano, ESP32 등)
- I2C LCD 1602 디스플레이
- I2C 백팩 모듈 (PCF8574 또는 유사)
- 점퍼 와이어 4개
- 브레드보드 (선택사항)

### 회로 연결

| I2C LCD | Arduino Uno | Arduino Nano | ESP32 |
|---------|-------------|--------------|-------|
| VCC | 5V | 5V | 3.3V |
| GND | GND | GND | GND |
| SDA | A4 | A4 | GPIO 21 |
| SCL | A5 | A5 | GPIO 22 |

## 💻 소프트웨어 설정

### 필요한 라이브러리
1. **Wire.h**: Arduino 기본 I2C 라이브러리 (내장)
2. **LiquidCrystal_I2C.h**: I2C LCD 제어 라이브러리

### 라이브러리 설치 방법
```
Arduino IDE → 도구 → 라이브러리 관리 → "LiquidCrystal I2C" 검색 → 설치
```

## 🚀 사용 방법

### 1단계: I2C 주소 확인
1. `LCD_address.ino` 업로드
2. 시리얼 모니터 열기 (9600 baud)
3. 출력된 I2C 주소 확인 (일반적으로 0x27 또는 0x3F)

### 2단계: LCD 제어
1. `LCD_display.ino`에서 주소 수정 (필요시)
   ```cpp
   LiquidCrystal_I2C lcd(0x27, 16, 2); // 0x27을 확인된 주소로 변경
   ```
2. 코드 업로드
3. LCD에서 스크롤 텍스트 확인

## 📊 코드 상세 설명

### LCD_address.ino 동작 원리
```cpp
// I2C 주소 범위 (1~126)를 순차적으로 스캔
for (byte address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0) {
        // 응답이 있으면 해당 주소에 장치 존재
        Serial.println(address, HEX);
    }
}
```

### LCD_display.ino 동작 원리
```cpp
// 화면 우측 끝에서 텍스트 시작
lcd.setCursor(16, 0);
lcd.print("Hello World!");

// 좌측으로 16칸 스크롤 (화면 폭만큼)
for (int i = 0; i < 16; i++) {
    lcd.scrollDisplayLeft();
    delay(150);
}
```

## ⚙️ 기술 사양

- **디스플레이**: 16x2 문자 LCD
- **통신 방식**: I2C (2-wire)
- **동작 전압**: 5V (Arduino Uno 기준)
- **문자 크기**: 5x8 도트
- **백라이트**: LED 백라이트 (조절 가능)
