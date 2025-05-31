#ifndef TEST_H
#define TEST_H
#include "message.h"    // 메시지 통신을 위한 TinyOS 기본 헤더

// 테스트 주기 (단위: 밀리초)
enum {
  TEST_PERIOD = 10240LU,
};

// 기본값 정의 (예: 초기 센서 값 등)
enum {
  DFLT_VAL = 0x11,
};

// 송신할 데이터 길이 (전체 패킷 크기에서 헤더 공간 제외한 값)
enum {
  TEST_DATA_LENGTH = TOSH_DATA_LENGTH - 6,
};

// 메시지 ID 정의 (AM: Active Message ID)
enum {
  AM_TEST_DATA_MSG = 0xA4,
};

// 센서 데이터 메시지 구조체 정의
typedef nx_struct test_data_msg {
  nx_am_addr_t srcID;    // 송신 노드 ID
  nx_uint32_t seqNo;     // 시퀸스 번호 (패킷 순서 확인용)
  nx_uint16_t type;      // 메시지 유형 (확장용)
  nx_uint16_t Temp;      // 온도
  nx_uint16_t Humi;      // 습도
  nx_uint16_t Illu;      // 조도
  nx_uint16_t battery;   // 배터리 상태
  //nx_uint8_t testData[TEST_DATA_LENGTH];  // 추가 데이터
} test_data_msg_t;

#endif // TEST_H
