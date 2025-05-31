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


## 🚀 설치 및 실행

### 1. 환경 설정

#### Python 패키지 설치
```bash
pip install influxdb-client pyserial
```

#### InfluxDB 2.x 설치 및 설정
1. InfluxDB 2.x를 로컬에 설치
2. 조직(Organization) 생성: `test`
3. 버킷(Bucket) 생성: `dust`
4. API 토큰 생성 및 복사

### 2. 설정 파일 수정

`dust.py`에서 다음 설정을 환경에 맞게 수정:

```python
# InfluxDB 설정
influxdb_url = "http://localhost:8086"
influxdb_token = "YOUR_TOKEN_HERE"  # 생성한 토큰으로 변경
influxdb_org = "test"
influxdb_bucket = "dust"

# 시리얼 포트 설정
serial_port = "com16"  # 실제 Arduino 포트로 변경 (Linux: /dev/ttyUSB0)
```

### 3. 실행

1. **Arduino 코드 업로드**
   ```bash
   # Arduino IDE에서 dust.ino 업로드
   ```

2. **Python 스크립트 실행**
   ```bash
   python dust.py
   ```

## 📊 데이터 형식

### Arduino 시리얼 출력
```
dust = 45.2
dust = 38.7
dust = 52.1
```

### InfluxDB 저장 형식
```
sensor_data,device=arduino dust=45.2
```

## 📈 측정 원리

1. **LED 펄스 생성**: 적외선 LED를 280μs 동안 켜서 먼지 입자 조명
2. **센서 값 읽기**: 40μs 후 포토다이오드에서 반사광 강도 측정
3. **전압 변환**: 아날로그 값(0-1023)을 전압(0-5V)으로 변환
4. **농도 계산**: `dustDensity = (voltage - 0.3) / 0.005` 공식 적용

## ⚙️ 기술 사양

- **측정 범위**: 0-500 μg/m³
- **측정 주기**: 1초
- **동작 전압**: 5V
- **인터페이스**: 아날로그 출력
- **응답 시간**: 10초
  

## 📊 데이터 시각화

InfluxDB에 저장된 데이터는 다음 도구들로 시각화 가능:
- **InfluxDB UI**: 웹 브라우저에서 `http://localhost:8086` 접속
- **Grafana**: 대시보드 생성으로 실시간 모니터링
- **Chronograf**: InfluxDB 전용 시각화 도구
