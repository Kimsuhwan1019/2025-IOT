int Vo = A0;                        // 센서 아날로그 출력이 연결된 핀
int V_led = 12;                     // LED를 제어할 핀

float Vo_value = 0;                 // 아날로그를 읽는 값
float Voltage = 0;                  // 전압 변환값
float dustDensity = 0;              // 먼지 농도

void setup() {
  Serial.begin(9600);              // 시리얼 통신 초기화
  pinMode(V_led, OUTPUT);          // LED 핀을 출력으로 설정
  pinMode(Vo, INPUT);              // 센서 핀을 입력으로 설정
}

void loop() {
  // LED 켜기 (먼지 입자 조명)
  digitalWrite(V_led, LOW);
  delayMicroseconds(280);          // 센서 안정화 대기
  
  Vo_value = analogRead(Vo);
  delayMicroseconds(40);           // 샘플링 대기
  
  digitalWrite(V_led, HIGH);
  delayMicroseconds(9680);         // 다음 측정까지 대기

 
  // 전압 및 먼지 농도 계산
 // Voltage = Vo_value * 5.0 / 1023.0;
 // dustDensity = (Voltage - 0.5) / 0.005;

  //Serial.print("dust = ");
  //Serial.println(dustDensity);

  // 원시 센서 값 출력
  Serial.println(Vo_value);
  delay(1000);      // 1초 간격으로 측정
}
