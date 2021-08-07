#ifndef __ITEM_H__
#define __ITEM_H__
#include <string>
using namespace std;

struct Item {
	string name;
	int price;

	Item(string n, int p) {
		// 판매품명, 가격
		name = n;
		price = p;
	}

	// sort 알고리즘 사용 시에 필요한 정렬 기준을
	// < 연산자 오버로딩으로 구현
	bool operator<(const Item& other) const {
		return name < other.name;
	}

};
#endif