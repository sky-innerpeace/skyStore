#ifndef __CONSUMER_H__
#define __CONSUMER_H__
#include <map>
#include "item.h"
#include "receipt.h"
#include <iostream>
using namespace std;
class consumer
{

public:
	string ID;		//사용자 ID
	map<Item, int> shoppingCart;		// 사용자 장바구니
	int freeDel;									//무료 배송 기준 금액

	virtual int getDeliveryFee() =0;					// 무료배송 여부 출력
	virtual void printShoppingList() =0;			// 장바구니 출력(ID, shoppingCart, freeDel 출력)
	virtual int getTotalPrice() =0;						// 총 금액 출력(할인, 쿠폰 적용한 금액)


	void resetMyList();									// 본인의 장바구니 초기화
	void addToShoppingList(Item item, int n);	// 장바구니에 제품 추가
	void delToShoppingList(string name);

};
#endif


