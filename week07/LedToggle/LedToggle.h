#ifndef LedToggle_h
#define LedToggle_h

#include "Arduino.h"

	class LedToggle{
	public:
		LedToggle(int pin);		//생성자 
		LedToggle(int pin, unsigned long delayTime);	//생성자 
		vold toggle();			//LED 상태 토글 
		
	private:
		int _pin;				//private 변수의 경우 _ 작성 
		bool _state;			// '_'가 필수는 X 
		unsigned long _delayTime;
};								//클래스는 함수가 아니라 명령어 이므로 끝에 세미콜론[;]을 붙인다. 

#endif
