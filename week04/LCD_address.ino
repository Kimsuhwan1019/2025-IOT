// I2C LCD 주소 자동 검색 프로그램
// 연결된 I2C 장치들의 주소를 스캔하여 시리얼 모니터에 출력
// 1602 LCD나 기타 I2C 장치의 주소를 찾을 때 사용

#include <Wire.h> //I2C 통신을 위한 라이브러리

void setup() {
  Serial.begin(9600); //시리얼 모니터 시작 (속도: 9600 baud)
  Wire.begin();       //I2C 통신 시작
  Serial.println("I2C Scanner Running...");   //시작 메세지 출력
}

void loop() {
  Serial.println("Scanning...");  //검색 시작 메세지 출력
  
  // I2C 주소 범위 전체 스캔 (0x01 ~ 0x7F, 1~127)
  // 0x00과 0x80~0xFF는 예약된 주소이므로 제외
  
  for (byte address = 1; address < 127; address++){ 
    //특정 주소로 통신 시작
    Wire.beginTransmission(address); 

    // 전송 종료하고 응답 코드 확인
    // 0: 성공 (장치 존재), 기타: 오류 (장치 없음)
    if (Wire.endTransmission() == 0){ 

      // 장치 발견 메시지
      Serial.print("I2C 장치 발견: 0x");  
      
      // 주소를 16진수 형태로 출력
      Serial.println(address, HEX); 
      delay(500); //0.5초 대기(출력 속도 조절)
    }
  }

  Serial.println("Scan Complete! Retrying in 5 seconds...\n");
  delay(5000);  //5초후 다시 검색
}
