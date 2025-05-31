// LedToggle 클래스 구현 파일
// LED의 토글 기능을 제공하는 라이브러리


#include "LedToggle.h"

// 생성자 1: 핀 번호만 지정
LedToggle::LedToggle(int pin){
	_pin = pin;         // 핀 번호 저장
	_state = false;     // 초기 상태는 OFF (LOW)
	_delayTime = 0;     // 지연 시간 없음
	pinMode(_pin, OUTPUT);      // 핀을 출력 모드로 설정
	digitalWrite(_pin, LOW);    // 초기값 LOW로 설정
} 


//생성자 2: 핀 번호와 지연 시간 지정
LedToggle::LedToggle(int pin, unsigned long delayTime){
	_pin = pin;         // 핀 번호 저장
	_state = false;     // 초기 상태는 OFF (LOW)
	_delayTime = delayTime; // 지연 시간 설정
	pinMode(_pin, OUTPUT);      // 핀을 출력 모드로 설정
	digitalWrite(_pin, LOW);    // 초기값 LOW로 설정
}

// LED 상태를 토글하는 함수
// 현재 상태와 반대로 변경 (ON->OFF, OFF->ON)

void LedToggle::toggle(){
	// 설정된 지연 시간이 있으면 대기
	if (_delayTime > 0){
		delay(_delayTime);
	}
	
	// 상태를 반전
	_state = !_state;
	// 핀에 새로운 상태 출력 (true면 HIGH, false면 LOW)
	digitalWrite(_pin, _state ? HIGH : LOW);
}
