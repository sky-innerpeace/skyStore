#pragma once
#ifndef __VVIP_H__
#define __VVIP_H__

#include "Standard.h"
class VVIP : public Standard
{
	double saleRate = 0.05;	// ������ 5�ۼ�Ʈ
public:
	VVIP(string id = "");

	string sendMessage();	// �Ǹ��ڿ��� ��û �޽��� ����

	int getDeliveryFee();					// ������ ���� ���
	void printShoppingList();			// ��ٱ��� ���(ID, shoppingCart, freeDel ���)
	int getTotalPrice();						// �� �ݾ� ���(����, ���� ������ �ݾ�)
};
#endif
