#include "Standard.h"

Standard::Standard(string id)
{
	ID = id;
	freeDel = 50000;
}

int Standard::getDeliveryFee()
{
	if (getTotalPrice() < freeDel) {
		return 2500;
	}
	else return 0;
}

void Standard::printShoppingList()
{
	cout << "��ǰ�� \t ���� \t ����" << endl;
	map<Item, int>::iterator it = shoppingCart.begin();
	for (it; it != shoppingCart.end(); it++) {
		cout << it->first.name << "\t" << it->second << "��" << "\t" << it->first.price*it->second <<  endl;
	}
}

int Standard::getTotalPrice()
{	
	int sum = 0;

	map<Item, int>::iterator it = shoppingCart.begin();
	for (it; it != shoppingCart.end(); it++) {
		sum += it->first.price*it->second;
	}
	return sum;
}
