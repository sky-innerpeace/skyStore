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
	vector<Item>* itemList;			// 판매 제품 목록
	vector<Receipt>* receiptList;	// 소비자 영수증 목록
	shared_ptr<int> totalSales;	// 배송비 제외한 총 매출

	Standard* SAList[10] = { NULL, };		//Standard 회원 10명
	int SAindex = 0;
	SVIP* SVList[10] = { NULL, };				// SVIP 회원 10명
	int SVindex = 0;
	VVIP* VVList[10] = { NULL, };			// VVIP 회원 10명
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

	string MakeShoppingCart();					// 등급 선택하고 ID 생성
	void GoToShppoingCart(string ID);		// ID로 본인의 장바구니에 접속
	void MainMenu();									// 장바구니 메인 메뉴



	void AddItem(int indexid, int grade);						// 제품 추가
	void DelItem(int indexid, int grade);						// 제품 삭제
	void shoppingMenuList(int indexid, int grade);		// 본인 장바구니 관리
	void ShowItemList();
	void PrintShoppingCart(int indexid, int grade);		// 본인 장바구니 출력
	void BuyItem(int indexid, int grade);						// 구매
	void ResetShoppingCart(int indexid, int grade);
	
	friend bool operator==(const Item&, string&);		// == 연산자 오버로딩
};
#endif

