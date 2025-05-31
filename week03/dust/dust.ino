// GP2Y1010AU0F 미세먼지 센서를 이용한 먼지 농도 측정
// 적외선 LED 펄스 방식으로 먼지 입자를 감지하여 농도 계산

int Vo = A0;    // 센서 출력 핀(아날로그 입력)
int V_LED = 2;  // 적외선 LED 제어 핀(디지털 출력)

float vo_value = 0;      // 센서 아날로그 읽기 값(0-1023)
float voltage = 0;       // 전압 변환 값 (0-5V)
float dustDensity = 0;   // 계산된 먼지 농도 

void setup(){
  Serial.begin(9600);     // 시리얼 통신 초기화 (9600 baud)
  pinMode(V_LED, OUTPUT); // LED 제어 핀을 출력으로 설정
  pinMode(Vo, INPUT);     // 센서 출력 핀을 입력으로 설정
}

void loop(){
  // === 센서 측정 시퀀스 시작 ===
  digitalWrite(V_LED, LOW);      // LED 켜기 (먼지 입자 조명)
  delayMicroseconds(280);        // // 센서 안정화 대기 (280μs)
  vo_value = analogRead(Vo);     // 센서 값 읽기 (0-1023 범위)
  delayMicroseconds(40);         // 샘플링 지연 시간 (40μs)
  digitalWrite(V_LED, HIGH);     // LED 끄기
  delayMicroseconds(9600);       // 다음 측정까지 대기 (9.6ms)


  // === 데이터 변환 및 계산 ===
  voltage = vo_value*5.0 / 1023.0;     // 아날로그 값을 전압으로 변환
  dustDensity = (voltage - 0.3)/0.005; // 전압을 먼지 농도로 변환

  
  // === 결과 시리얼 출력 ===
  Serial.print("dust = ");
  Serial.println(dustDensity);

  delay(1000);   // 1초 간격으로 측정 반복
}
