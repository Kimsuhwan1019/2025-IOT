# Arduino Fundamentals Lab

Arduino 프로그래밍의 핵심 개념들을 학습할 수 있는 실습 예제 모음입니다.

## 📁 프로젝트 구성

### 1. 루프 카운터 예제들
- **loop-count.ino**: `millis()` 함수를 사용한 논블로킹 루프 카운터
- **loop-count-SimpleTimer.ino**: SimpleTimer 라이브러리를 사용한 루프 카운터

### 2. LED 제어 예제
- **myled.ino**: 커스텀 LedToggle 라이브러리를 사용한 LED 깜빡임 예제

### 3. 기본 함수 예제
- **sum.ino**: 사용자 정의 함수를 사용한 덧셈 계산 예제

### 4. 커스텀 라이브러리
- **LedToggle.h**: LED 토글 기능을 제공하는 헤더 파일
- **LedToggle.cpp**: LED 토글 클래스 구현 파일


## 📋 각 예제 설명

### Loop Counter 예제들
두 가지 방식으로 1초마다 루프 실행 횟수를 측정하고 출력합니다.

**millis() 방식 (loop-count.ino)**
- `delay()` 함수를 사용하지 않는 논블로킹 방식
- `millis()` 함수를 사용하여 시간 체크
- 메인 루프가 블로킹되지 않음

**SimpleTimer 방식 (loop-count-SimpleTimer.ino)**
- SimpleTimer 라이브러리 사용
- 콜백 함수를 통한 타이머 처리
- 더 간단하고 직관적인 코드

### LED 제어 예제 (myled.ino)
- 커스텀 LedToggle 클래스 사용
- 내장 LED를 0.5초 간격으로 깜빡임
- 객체지향 프로그래밍 적용

### 기본 함수 예제 (sum.ino)
- 사용자 정의 함수 생성 및 사용법
- 매개변수와 반환값 활용
- 시리얼 통신을 통한 결과 출력

### LedToggle 라이브러리
Arduino LED 제어를 위한 간단한 클래스 라이브러리

**주요 기능:**
- LED 상태 토글 (켜기/끄기)
- 지연 시간 설정 가능한 생성자
- 객체지향적 LED 제어

**사용법:**
```cpp
#include <LedToggle.h>

LedToggle led(13);        // 핀 13에 연결된 LED
// 또는
LedToggle led(13, 100);   // 핀 13, 100ms 지연시간

led.toggle();             // LED 상태 토글
```

## 🛠️ 하드웨어 요구사항

- Arduino 보드 (Uno, Nano, ESP32 등)
- LED (내장 LED 사용 가능)
- USB 케이블

## 📖 학습 목표

이 예제들을 통해 다음을 학습할 수 있습니다:

- Arduino 기본 프로그래밍 구조
- 시리얼 통신 사용법
- 타이머와 논블로킹 프로그래밍
- 사용자 정의 함수 작성
- 클래스와 객체지향 프로그래밍
- 커스텀 라이브러리 개발
