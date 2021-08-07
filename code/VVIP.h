#pragma once
#ifndef __VVIP_H__
#define __VVIP_H__

#include "Standard.h"
class VVIP : public Standard
{
	double saleRate = 0.05;	// 할인율 5퍼센트
public:
	VVIP(string id = "");

	string sendMessage();	// 판매자에게 요청 메시지 전송

	int getDeliveryFee();					// 무료배송 여부 출력
	void printShoppingList();			// 장바구니 출력(ID, shoppingCart, freeDel 출력)
	int getTotalPrice();						// 총 금액 출력(할인, 쿠폰 적용한 금액)
};
#endif
