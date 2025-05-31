# 미세먼지 센서 데이터 수집 및 InfluxDB 저장 스크립트
# Arduino에서 시리얼 통신으로 받은 센서 데이터를 InfluxDB에 실시간 저장

from influxdb_client import InfluxDBClient
import time
import serial
#=== InfluxDB 2.x 설정 ===
influxdb_url="http://localhost.8086" # InfluxDB 서버 URL (기본 포트 8086)
influxdb_token = "RYBWiuhjkiSeCd0vltX6kywAzYntxTalj7oxUw2_80JhP20dkwa12gPv2nn0_UJbLh6BKOiXPEpOm8GCQC6r2Q=="
influxdb_org = "test"	       # InfluxDB에서 설정한 조직 이름
influxdb_bucket = "dust"       # 데이터가 저장될 버킷 이름

# === (1) Arduino 시리얼 포트 설정 ===
serial_port = "com16" # 아두이노 포트 (Windows 기준)
baudrate = 9600       # 통신 속도 (Arduino와 동일하게 설정)
timeout = 2           # 시리얼 읽기 타임아웃 (초)

# InfluxDB 2.0 클라이언트 생성
client = InfluxDBClient(url=influxdb_url, token=influxdb_token, org=influxdb_org)  # 데이터 쓰기용 API 객체 생성

# ===(3) InfluxDB 클라이언트 설정 ===
write_api = client.write_api()

# ===(4) 시리얼 포트 열기 ===
try:
	ser = serial.Serial(serial_port, baudrate, timeout=timeout)
	print(f"Connectde to {serial_port} at {baudrate} baud")
except serial.SerialException:
	print("Failed to connect to serial port.")
	exit()

# ===(5) 시리얼 데이터 읽기 및 InfluxDB 저장 ===
try:
	while True:
		 # 시리얼 버퍼에 데이터가 있는지 확인
		if ser.in_waiting > 0:
			# 한 줄씩 읽어서 UTF-8로 디코딩하고 공백 제거
			line = ser.readline().decode('UTF-8').strip() #시리얼 데이터 읽기
			print(f"Received: {line}")

			# 데이터가 "temperature=25.3" 같은 형식이라고 가정
			if "=" in line:
				# "=" 기준으로 키와 값 분리
				key, value = line.split("=")  # 키&값에서 공백 제
				try:
					# 문자열을 실수로 변환
					value = float(value) #숫자로 변환
					
					# InfluxDB 2.x 데이터 포맷
					data = f"sensor_data,device=arduino {key}={value}"

					# InfluxDB에 데이터 쓰기
					write_api.write(bucket=influxdb_bucket,record=data)
					print(f"Data written to InfluxDB: {key}={value}")
				except ValueError:
					# 숫자 변환 실패 시 에러 메시지 출력
					print("Invalid data format")
		time.sleep(1) #1초 대기
except KeyboardInterrupt:
	# Ctrl+C 키 입력 시 프로그램 종료
	print("Stopping data collection...")

finally:
	# 프로그램 종료 시 시리얼 포트 연결 해제
	ser.close()

