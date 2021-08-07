#pragma once
#ifndef __SVIP_H__
#define __SVIP_H__
#include "Standard.h"
class SVIP : public Standard
{
	int coupon = 2;			// 월별로 지급되는 쿠폰 개수
	int couponPrice = 5000;		// 쿠폰 할인 가격

public:
	SVIP(string id = "");

	// 사은품 고르는 함수는 consumer의 addToShoppingList()를 활용

	int getDeliveryFee();					// 무료배송 여부 출력
	void printShoppingList();			// 장바구니 출력(ID, shoppingCart, freeDel 출력)
	int getTotalPrice();						// 총 금액 출력(할인, 쿠폰 적용한 금액)

};
#endif

