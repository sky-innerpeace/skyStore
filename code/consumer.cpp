#include "consumer.h"
#include "NoItemException.cpp"
#include <string>
using namespace std;

bool  operator==(const Item& i, string& str) {
	if (i.name == str) return true;
	return false;

}
void consumer::resetMyList()
{
	shoppingCart.clear();

}

void consumer::addToShoppingList(Item item, int n)
{
	if (shoppingCart.find(item) == shoppingCart.end())	// 없으면
	{
		shoppingCart.insert(make_pair(item, n));
	}
	else
	{
		shoppingCart[item] += n;
	}
}

// 예외 처리 완료
void consumer::delToShoppingList(string name) {
	try {
		if (shoppingCart.empty()) {
			throw NoItemException("장바구니에 담긴 품목");
			return;
		}
		map<Item, int>::iterator it = shoppingCart.begin();
		for (it; it != shoppingCart.end(); it++) {
			if (it->first == name) {	// == 연산자 오버로딩
				shoppingCart.erase(it->first);
				break;
			}
			if (it == shoppingCart.end()) {
				throw NoItemException("삭제하려는 품목");
			}
		}
	}
	catch (NoItemException e) {
		cout << e.getItem() << "이 없습니다." << endl;
	}
}

