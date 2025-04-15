int a1 = 2;
int a2 = 3;
int a3;

void setup() {
  Serial.begin(115200);
  Serial.println();

  a3 = sum(a1,a2);
  Serial.println(a3);
}

void loop() {
}

int sum(int a, int b){
  int c = a + b;
  return c;
}
