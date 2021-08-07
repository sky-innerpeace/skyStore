#ifndef __ARRANGEEXCEPTION__
#define __ARRANGEEXCEPTION__
#include <iostream>
class ArrangeException {
private:
	int number;

public:
	ArrangeException(int n) :number(n) {}
	int getNumber() { return number; }
	void printWarning() { std::cout << "잘못된 숫자 혹은 문자 " << getNumber() << "를 입력하셨습니다." << std::endl; }
};
#endif