#ifndef __ITEM_H__
#define __ITEM_H__
#include <string>
using namespace std;

struct Item {
	string name;
	int price;

	Item(string n, int p) {
		// �Ǹ�ǰ��, ����
		name = n;
		price = p;
	}

	// sort �˰��� ��� �ÿ� �ʿ��� ���� ������
	// < ������ �����ε����� ����
	bool operator<(const Item& other) const {
		return name < other.name;
	}

};
#endif