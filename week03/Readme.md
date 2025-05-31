# 미세먼지 센서 InfluxDB 연동 프로젝트

Arduino 미세먼지 센서(GP2Y1010AU0F)로 측정한 데이터를 Python을 통해 InfluxDB에 실시간으로 저장하는 IoT 데이터 수집 시스템입니다.

## 📋 프로젝트 개요

이 프로젝트는 GP2Y1010AU0F 미세먼지 센서를 Arduino로 제어하여 먼지 농도를 측정하고, Python 스크립트를 통해 시리얼 통신으로 데이터를 수집하여 InfluxDB 시계열 데이터베이스에 저장하는 시스템입니다.

## 🏗️ 시스템 구조

```
Arduino (GP2Y1010AU0F) → Serial → Python Script → InfluxDB
```

## 🔧 하드웨어 구성

### 필요한 부품
- Arduino 보드 (Uno, Nano 등)
- GP2Y1010AU0F 미세먼지 센서
- 150Ω 저항 (LED 구동용)
- 220μF 커패시터 (전원 안정화용)
- 점퍼 와이어
- 브레드보드

### 회로 연결

| GP2Y1010AU0F 핀 | Arduino 핀 | 설명 |
|------------------|------------|------|
| V-LED (Pin 3) | 2번 핀 | LED 제어 (150Ω 저항 경유) |
| LED-GND (Pin 4) | GND | LED 접지 |
| LED-VCC (Pin 5) | 5V | LED 전원 |
| S-GND (Pin 6) | GND | 센서 접지 |
| Vo (Pin 1) | A0 | 센서 출력 |
| Vcc (Pin 2) | 5V | 센서 전원 |

## 💻 소프트웨어 구성

### Arduino 코드 (dust.ino)
- **센서 제어**: GP2Y1010AU0F의 적외선 LED를 펄스 방식으로 제어
- **데이터 측정**: 아날로그 값을 읽어 전압으로 변환 후 먼지 농도 계산
- **시리얼 출력**: `dust = [값]` 형식으로 데이터 전송

### Python 스크립트 (dust.py)
- **시리얼 통신**: Arduino로부터 데이터 수신
- **데이터 파싱**: 수신된 문자열에서 센서 값 추출
- **InfluxDB 연동**: 시계열 데이터베이스에 실시간 저장

