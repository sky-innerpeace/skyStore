#include "SVIP.h"
#include "ArrangeException.cpp"

SVIP::SVIP(string id)
{
	ID = id;
	freeDel = 0;
}


int SVIP::getDeliveryFee()
{
	return 0;
}

void SVIP::printShoppingList()
{
	cout << "��ǰ�� \t ���� \t ����" << endl;
	map<Item, int>::iterator it = shoppingCart.begin();
	for (it; it != shoppingCart.end(); it++) {
		cout << it->first.name << "\t" << it->second << "��" << "\t" << it->first.price * it->second << endl;
	}
}

int SVIP::getTotalPrice()
{
	int sum = 0;
	int c = 0;	//���� ��� ����
	map<Item, int>::iterator it = shoppingCart.begin();
	for (it; it != shoppingCart.end(); it++) {
		sum += it->first.price * it->second;
	}
	try {
		if (coupon > 0 && sum > 5000) {
			cout << "5000�� �� ������ ����Ͻðڽ��ϱ�?(����� ���ϸ� 1, ������ ������ 0)" << endl;
			cin >> c;
			if (c != 1 && c != 0) { throw ArrangeException(c); }
			else if (c == 1) {
				coupon--;
				sum -= couponPrice;
			}
		}
	}
	catch (ArrangeException e) {
		e.printWarning();
		cout << "������ ������� �ʽ��ϴ�." << endl;
	}
	return sum;
}
