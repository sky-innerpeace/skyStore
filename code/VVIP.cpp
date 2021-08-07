#include "VVIP.h"

VVIP::VVIP(string id)
{
	ID = id;
	freeDel = 50000;
}

string VVIP::sendMessage()
{
	string str;
	cout << "��û �޽����� �Է��ϼ��� : ";
	cin >> str;
	return str;
}

int VVIP::getDeliveryFee()
{
	return 0;
}

void VVIP::printShoppingList()
{
	cout << "��ǰ�� \t ���� \t ����" << endl;
	map<Item, int>::iterator it = shoppingCart.begin();
	for (it; it != shoppingCart.end(); it++) {
		cout << it->first.name << "\t" << it->second << "��" << "\t" << it->first.price * it->second << endl;
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
