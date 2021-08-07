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
	if (shoppingCart.find(item) == shoppingCart.end())	// ������
	{
		shoppingCart.insert(make_pair(item, n));
	}
	else
	{
		shoppingCart[item] += n;
	}
}

// ���� ó�� �Ϸ�
void consumer::delToShoppingList(string name) {
	try {
		if (shoppingCart.empty()) {
			throw NoItemException("��ٱ��Ͽ� ��� ǰ��");
			return;
		}
		map<Item, int>::iterator it = shoppingCart.begin();
		for (it; it != shoppingCart.end(); it++) {
			if (it->first == name) {	// == ������ �����ε�
				shoppingCart.erase(it->first);
				break;
			}
			if (it == shoppingCart.end()) {
				throw NoItemException("�����Ϸ��� ǰ��");
			}
		}
	}
	catch (NoItemException e) {
		cout << e.getItem() << "�� �����ϴ�." << endl;
	}
}

