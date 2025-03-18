int Vo = A0;
int V_LED = 2;

float vo_value = 0;
float voltage = 0;
float dustDensity = 0;

void setup(){
  Serial.begin(9600);
  pinMode(V_LED, OUTPUT);
  pinMode(Vo, INPUT);
}

void loop(){
  digitalWrite(V_LED, LOW);
  delayMicroseconds(280);
  vo_value = analogRead(Vo);
  delayMicroseconds(40);
  digitalWrite(V_LED, HIGH);
  delayMicroseconds(9600);

  voltage = vo_value*5.0 / 1023.0;
  dustDensity = (voltage - 0.3)/0.005;

  Serial.print("dust = ");
  Serial.println(dustDensity);

  delay(1000);
}