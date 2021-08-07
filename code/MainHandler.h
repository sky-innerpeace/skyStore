#pragma once
#ifndef __MAINHANDLER_H__
#define __MAINHANDLER_H__

#include "item.h"
#include "receipt.h"
#include "StoreCommonDecl.h"
#include "ConsumerHandler.h"
#include "SellerHandler.h"
#include <vector>

class MainHandler
{
public:

	ConsumerHandler ch;			// 소비자 Handler
	SellerHandler sh;					// 판매자 Handler

	vector<Item> itemList;			// 판매 제품 목록
	vector<Receipt> receiptList;	// 소비자 영수증 목록
	shared_ptr<int> totalSales = make_shared<int>(0); // 배송비를 제외한 총 매출액

	void showSelectMode() {		// 모드 선택
		int choice;
		while (1) {
			
			cout << "모드선택(1:소비자, 2:관리자, 3: 종료) : ";
			cin >> choice;
			cout << endl;

			// 세부 선택 과정에서 int형을 선언받고 남은 '\n'을 입력버퍼에서 지워주기 위한 과정
			cin.clear();
			cin.ignore();

			switch (choice)
			{
			case 1:
				// 관리자(판매자) 모드 생성 및 실행
				ch = ConsumerHandler(&itemList, &receiptList, totalSales);
				ch.MainMenu();
				// 입력버퍼 clear
				cin.clear();
				cin.ignore();
				break;
			case 2:
				// 관리자(판매자) 모드 생성 및 실행
				sh = SellerHandler(&itemList, &receiptList, totalSales);
				sh.Mainmenu();
				// 입력버퍼 clear
				cin.clear();
				cin.ignore();
				break;
			case 3:
				// 종료
				cout << "이용해주셔서 감사합니다. 프로그램을 종료합니다." << endl;
				return;
				break;
			default:
				// 1~3 이외의 다른 숫자 선택 시 예외 처리
				cout << "모드를 다시 선택하세요" << endl;
			}
		}
	}
	void showMessage() {		// 환영 문구
		cout << "********************************************" << endl;
		cout << "** 하늘이네 잡화점에 오신 것을 환영합니다 **" << endl;
		cout << "********************************************" << endl;
	}
	
	
};
#endif