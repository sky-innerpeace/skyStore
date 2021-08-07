#pragma once
#ifndef __STANDARD_H__
#define __STANDARD_H__
#include "consumer.h"
#include "receipt.h"
#include <iostream>
using namespace std;

class Standard : public consumer
{
public:
	Standard(string id="");

	int getDeliveryFee();					// 무료배송 여부 출력
	void printShoppingList();			// 장바구니 출력(ID, shoppingCart, freeDel 출력)
	int getTotalPrice();						// 총 금액 출력(할인, 쿠폰 적용한 금액)
};

#endif

