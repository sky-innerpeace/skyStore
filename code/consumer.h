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
	string ID;		//����� ID
	map<Item, int> shoppingCart;		// ����� ��ٱ���
	int freeDel;									//���� ��� ���� �ݾ�

	virtual int getDeliveryFee() =0;					// ������ ���� ���
	virtual void printShoppingList() =0;			// ��ٱ��� ���(ID, shoppingCart, freeDel ���)
	virtual int getTotalPrice() =0;						// �� �ݾ� ���(����, ���� ������ �ݾ�)


	void resetMyList();									// ������ ��ٱ��� �ʱ�ȭ
	void addToShoppingList(Item item, int n);	// ��ٱ��Ͽ� ��ǰ �߰�
	void delToShoppingList(string name);

};
#endif


