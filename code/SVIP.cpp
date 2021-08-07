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
	cout << "제품명 \t 개수 \t 가격" << endl;
	map<Item, int>::iterator it = shoppingCart.begin();
	for (it; it != shoppingCart.end(); it++) {
		cout << it->first.name << "\t" << it->second << "개" << "\t" << it->first.price * it->second << endl;
	}
}

int SVIP::getTotalPrice()
{
	int sum = 0;
	int c = 0;	//쿠폰 사용 여부
	map<Item, int>::iterator it = shoppingCart.begin();
	for (it; it != shoppingCart.end(); it++) {
		sum += it->first.price * it->second;
	}
	try {
		if (coupon > 0 && sum > 5000) {
			cout << "5000원 권 쿠폰을 사용하시겠습니까?(사용을 원하면 1, 원하지 않으면 0)" << endl;
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
		cout << "쿠폰을 사용하지 않습니다." << endl;
	}
	return sum;
}
