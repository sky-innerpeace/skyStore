#ifndef __ARRANGEEXCEPTION__
#define __ARRANGEEXCEPTION__
#include <iostream>
class ArrangeException {
private:
	int number;

public:
	ArrangeException(int n) :number(n) {}
	int getNumber() { return number; }
	void printWarning() { std::cout << "�߸��� ���� Ȥ�� ���� " << getNumber() << "�� �Է��ϼ̽��ϴ�." << std::endl; }
};
#endif