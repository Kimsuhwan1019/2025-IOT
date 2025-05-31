// 두 정수의 합을 계산하는 간단한 프로그램
// 사용자 정의 함수를 사용하여 덧셈 연산 수행

// 전역 변수 선언
int a1 = 2;    // 첫번째 숫자
int a2 = 3;    // 두번째 숫자
int a3;        // 결과를 저장할 변

void setup() {

  // 시리얼 통신 초기화 (115200 baud rate)
  Serial.begin(115200);
  Serial.println();

  // sum 함수를 호출하여 a1과 a2의 합을 계산
  a3 = sum(a1,a2);
  // 결과를 시리얼 모니터에 출력
  Serial.println(a3);
}

void loop() {
  // 반복 실행할 코드 없음
}

int sum(int a, int b){
  int c = a + b;    // 두 수를 더함
  return c;         // 결과 반환
}
