#ifndef LedToggle_h
#define LedToggle_h

#include "Arduino.h"

	class LedToggle{
	public:
		LedToggle(int pin);		//������ 
		LedToggle(int pin, unsigned long delayTime);	//������ 
		vold toggle();			//LED ���� ��� 
		
	private:
		int _pin;				//private ������ ��� _ �ۼ� 
		bool _state;			// '_'�� �ʼ��� X 
		unsigned long _delayTime;
};								//Ŭ������ �Լ��� �ƴ϶� ��ɾ� �̹Ƿ� ���� �����ݷ�[;]�� ���δ�. 

#endif
