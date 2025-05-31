// LedToggle 클래스 헤더 파일
// LED의 토글 기능을 제공하는 라이브러리

#ifndef LedToggle_h
#define LedToggle_h
#include "Arduino.h"

// LedToggle 클래스
// LED의 상태를 토글(켜기/끄기)하는 기능을 제공
class LedToggle{
public:
	// 생성자 1: 핀 번호만 지정
	LedToggle(int pin);
	
	// 생성자 2: 핀 번호와 지연 시간 지정
	LedToggle(int pin, unsigned long delayTime);
	
        // LED 상태 토글 함수
        // 현재 상태와 반대로 변경 (ON->OFF, OFF->ON)
	void toggle();
	
private:
	int _pin;                    // LED가 연결된 핀 번호 (private 변수는 _ 접두사 사용)
	bool _state;                 // 현재 LED 상태 (true: ON, false: OFF)
	unsigned long _delayTime;    // 토글 시 지연 시간 (밀리초)
};

#endif
