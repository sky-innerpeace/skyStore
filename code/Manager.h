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
	shared_ptr<int> totalSales;	// 총 판매 금액
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


	void confirmBuy(Receipt& r);		// 구매 확정
	void cancelBuy(Receipt& r);		// 구매 취소
	void printTotalSalesToFile();		// 총 매출, 합산 
	void printAllReceipt();
	void delItem();

};
#endif

