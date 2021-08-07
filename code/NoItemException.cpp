#ifndef __NOITEMEXCEPTION__
#define __NOITEMEXCEPTION__
#include <iostream>

class NoItemException {
private:
	std::string item;
public:
	NoItemException(std::string n) : item(n) {}
	NoItemException() {}
	std::string getItem() { return item;  }
};
#endif