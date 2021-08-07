#include "VVIP.h"

VVIP::VVIP(string id)
{
	ID = id;
	freeDel = 50000;
}

string VVIP::sendMessage()
{
	string str;
	cout << "요청 메시지를 입력하세요 : ";
	cin >> str;
	return str;
}

int VVIP::getDeliveryFee()
{
	return 0;
}

void VVIP::printShoppingList()
{
	cout << "제품명 \t 개수 \t 가격" << endl;
	map<Item, int>::iterator it = shoppingCart.begin();
	for (it; it != shoppingCart.end(); it++) {
		cout << it->first.name << "\t" << it->second << "개" << "\t" << it->first.price * it->second << endl;
	}
}

int VVIP::getTotalPrice()
{
	int sum = 0;

	map<Item, int>::iterator it = shoppingCart.begin();
	for (it; it != shoppingCart.end(); it++) {
		sum += it->first.price * it->second;
	}
	sum = sum * (1 - saleRate);

	return sum;
}
