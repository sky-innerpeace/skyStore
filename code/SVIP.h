#pragma once
#ifndef __SVIP_H__
#define __SVIP_H__
#include "Standard.h"
class SVIP : public Standard
{
	int coupon = 2;			// ������ ���޵Ǵ� ���� ����
	int couponPrice = 5000;		// ���� ���� ����

public:
	SVIP(string id = "");

	// ����ǰ ���� �Լ��� consumer�� addToShoppingList()�� Ȱ��

	int getDeliveryFee();					// ������ ���� ���
	void printShoppingList();			// ��ٱ��� ���(ID, shoppingCart, freeDel ���)
	int getTotalPrice();						// �� �ݾ� ���(����, ���� ������ �ݾ�)

};
#endif

