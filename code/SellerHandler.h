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
	vector<Item> *itemList;			// 판매 제품 목록
	vector<Receipt> *receiptList;	// 소비자 영수증 목록
	shared_ptr<int> totalSales;
	Manager manager;
public:
	// 기본 생성자
	SellerHandler()
	{
		this->itemList = NULL;
		this->receiptList = NULL;
	}
	// 생성자
	SellerHandler(vector<Item>* itemList, vector<Receipt>* receiptList, shared_ptr<int> totalSales) {
		this->itemList = itemList;
		this->receiptList = receiptList;
		this->totalSales = totalSales;	//소유권 공유
		// 매니저 객체 생성하여 정보 공유
		manager = Manager(receiptList, itemList, totalSales);
	}

	void Mainmenu();					// 메인 메뉴

	void showAllReceipt();				// 전체 영수증(소비자 별로) 확인
	void showList(map<Item, int> List);		// 주문서에 출력될 '개인 장바구니' 출력
	void confirmSell();						// 구매 확정

	void addItem();					// 아이템 추가
	void subItem();					// 아이템 삭제
	void showItem();				// 아이템 출력
	void sortItem();					// 아이템 정렬, algorithm의 sort 함수 사용

	void printTotalSales();		// 텍스트 파일에 하루 매출 기록하기

	friend ostream& operator<<(ostream&, const Item& );	// << 연산자 오버로딩
	friend istream& operator >>(istream&, vector<string, int>&); // >> 연산자 오버로딩
};


#endif

