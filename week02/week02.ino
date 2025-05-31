// 초음파 센서(HC-SR04)를 이용한 거리 측정 및 LED 제어
// 거리를 측정하고 빨간색/녹색 LED를 번갈아 깜빡임

#define TRIG 13 //TRIG 핀
#define ECHO 12 //ECHO 핀

int led_r = 7; // 빨간색 LED핀
int led_g = 10; // 녹색 LED

void setup()
{
  Serial.begin(9600);        // 시리얼 통신 초기화
  pinMode(led_r, OUTPUT);    // 빨간색 LED를 출력으로 설정
  pinMode(led_g, OUTPUT);    // 녹색 LED를 출력으로 설정
  pinMode(TRIG, OUTPUT);     // TRIG 핀을 출력으로 설정
  pinMode(ECHO,INPUT);       // ECHO 핀을 입력으로 설정
}

void loop()
{
  long duration, distance;   // 초음파 왕복 시간, 거리 변수
  
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2); //delay(2)  // 신호 안정화
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);            // 10us 펄스 생성
  digitalWrite(TRIG,LOW);  

  // 초음파 반사 시간 측정
  duration = pulseIn(ECHO, HIGH);

   // 거리 계산 (왕복 시간 고려)
  distance = duration * 17/ 1000;

  // 측정 결과 시리얼 출력
  Serial.println(duration );
  Serial.print("\nDIstance : ");
  Serial.print(distance);
  Serial.println(" Cm");

  // LED 번갈아 깜빡임 (빨간색 → 녹색)
  digitalWrite(led_r, HIGH);  // 빨간색 LED 켜기
  digitalWrite(led_g, LOW);   // 녹색 LED 끄기
  delay(1000);                // Wait for 1000 millisecond(s)   
  
  digitalWrite(led_r, LOW);   // 빨간색 LED 끄기
  digitalWrite(led_g, HIGH);  // 녹색 LED 켜기
  delay(1000);                // Wait for 1000 millisecond(s)
}
