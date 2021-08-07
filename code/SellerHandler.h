#pragma once
#ifndef __SELLERHANDLER_H__
#define __SELLERHANDLER_H__
#include "item.h"
#include "receipt.h"
#include "Manager.h"
#include <vector>
#include <iostream>
using namespace std;
class SellerHandler
{
private:
	vector<Item> *itemList;			// �Ǹ� ��ǰ ���
	vector<Receipt> *receiptList;	// �Һ��� ������ ���
	shared_ptr<int> totalSales;
	Manager manager;
public:
	// �⺻ ������
	SellerHandler()
	{
		this->itemList = NULL;
		this->receiptList = NULL;
	}
	// ������
	SellerHandler(vector<Item>* itemList, vector<Receipt>* receiptList, shared_ptr<int> totalSales) {
		this->itemList = itemList;
		this->receiptList = receiptList;
		this->totalSales = totalSales;	//������ ����
		// �Ŵ��� ��ü �����Ͽ� ���� ����
		manager = Manager(receiptList, itemList, totalSales);
	}

	void Mainmenu();					// ���� �޴�

	void showAllReceipt();				// ��ü ������(�Һ��� ����) Ȯ��
	void showList(map<Item, int> List);		// �ֹ����� ��µ� '���� ��ٱ���' ���
	void confirmSell();						// ���� Ȯ��

	void addItem();					// ������ �߰�
	void subItem();					// ������ ����
	void showItem();				// ������ ���
	void sortItem();					// ������ ����, algorithm�� sort �Լ� ���

	void printTotalSales();		// �ؽ�Ʈ ���Ͽ� �Ϸ� ���� ����ϱ�

	friend ostream& operator<<(ostream&, const Item& );	// << ������ �����ε�
	friend istream& operator >>(istream&, vector<string, int>&); // >> ������ �����ε�
};


#endif

