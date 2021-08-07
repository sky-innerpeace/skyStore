#pragma once
#ifndef __MANAGER_H__
#define __MANAGER_H__
#include "receipt.h"
#include <vector>
#include <memory>
using namespace std;

class Manager
{
private:
	vector<Receipt>* receiptList;
	vector<Item>* itemList;
	shared_ptr<int> totalSales;	// �� �Ǹ� �ݾ�
public:
	Manager(vector<Receipt>* r, vector<Item>* i, shared_ptr<int> totalSales) {

		itemList = i;
		receiptList = r;
		this->totalSales = totalSales;
	}
	Manager() {
		itemList = NULL;
		receiptList = NULL;
	}


	void confirmBuy(Receipt& r);		// ���� Ȯ��
	void cancelBuy(Receipt& r);		// ���� ���
	void printTotalSalesToFile();		// �� ����, �ջ� 
	void printAllReceipt();
	void delItem();

};
#endif

