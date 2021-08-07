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

	int getDeliveryFee();					// ������ ���� ���
	void printShoppingList();			// ��ٱ��� ���(ID, shoppingCart, freeDel ���)
	int getTotalPrice();						// �� �ݾ� ���(����, ���� ������ �ݾ�)
};

#endif

