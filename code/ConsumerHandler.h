#pragma once
#ifndef __CONSUMERHANDLER_H__
#define __CONSUMERHANDLER_H__
#include "item.h"
#include "receipt.h"
#include "consumer.h"

#include "StoreCommonDecl.h"

#include "Standard.h"
#include "SVIP.h"
#include "VVIP.h"

#include <iostream>
#include <vector>

using namespace std;

class ConsumerHandler
{
public:
	vector<Item>* itemList;			// �Ǹ� ��ǰ ���
	vector<Receipt>* receiptList;	// �Һ��� ������ ���
	shared_ptr<int> totalSales;	// ��ۺ� ������ �� ����

	Standard* SAList[10] = { NULL, };		//Standard ȸ�� 10��
	int SAindex = 0;
	SVIP* SVList[10] = { NULL, };				// SVIP ȸ�� 10��
	int SVindex = 0;
	VVIP* VVList[10] = { NULL, };			// VVIP ȸ�� 10��
	int VVindex = 0;


	ConsumerHandler() {
		itemList = NULL;
		receiptList = NULL;

	}
	ConsumerHandler(vector<Item>* itemList, vector<Receipt>* receiptList, shared_ptr<int> totalSales)
	{
		this->itemList = itemList;
		this->receiptList = receiptList;
		this->totalSales = totalSales;
	}




	int FindMyShoppingCart(string ID, int* grade);

	string MakeShoppingCart();					// ��� �����ϰ� ID ����
	void GoToShppoingCart(string ID);		// ID�� ������ ��ٱ��Ͽ� ����
	void MainMenu();									// ��ٱ��� ���� �޴�



	void AddItem(int indexid, int grade);						// ��ǰ �߰�
	void DelItem(int indexid, int grade);						// ��ǰ ����
	void shoppingMenuList(int indexid, int grade);		// ���� ��ٱ��� ����
	void ShowItemList();
	void PrintShoppingCart(int indexid, int grade);		// ���� ��ٱ��� ���
	void BuyItem(int indexid, int grade);						// ����
	void ResetShoppingCart(int indexid, int grade);
	
	friend bool operator==(const Item&, string&);		// == ������ �����ε�
};
#endif

