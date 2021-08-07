#include "SellerHandler.h"
#include "Manager.h"
#include "ArrangeException.cpp"
#include <iostream>
#include <algorithm>
using namespace std;

// << 연산자 오버로딩
ostream& operator<<(ostream& ostream, const Item& i) {
	ostream << i.name << "\t\t" << i.price << endl;

	return ostream;

}

// >> 연산자 오버로딩
istream& operator >>(istream& istream, vector<Item>& item) {
	string name;
	int price;
	cout << "추가할 품목 이름과 가격을 입력하세요(이름 가격) : ";
	istream >> name >> price;
	item. push_back(Item(name, price));

	return istream;
}

void SellerHandler::Mainmenu()
{
	int cmd = 0;
	try {
		while (true)
		{
			cout << "**** 판매자메뉴 ****" << endl;
			cout << "1.아이템 추가" << endl;
			cout << "2. 아이템 삭제" << endl;
			cout << "3. 아이템 목록 확인" << endl;
			cout << "4. 영수증 목록 확인" << endl;
			cout << "5. 영수증 상태 설정" << endl;
			cout << "6. 텍스트 파일로 출력" << endl;
			cout << "7.종료" << endl;
			cout << "*******************" << endl;
			cout << "메뉴 선택 : ";
			cin >> cmd;
			if (!(cmd>=1 && cmd <=7)) {
				throw ArrangeException(cmd);
			}
			switch (cmd)
			{
			case 1:
				addItem();
				break;
			case 2:
				subItem();
				break;
			case 3:
				showItem();
				break;
			case 4:
				showAllReceipt();
				break;
			case 5:
				confirmSell();
				break;
			case 6:
				printTotalSales();
				break;
			case 7:
				return;		//종료
				break;
			default:
				cout << "다시 입력하세요." << endl;
				break;
			}
		}
	}
	catch (ArrangeException e) {
		e.printWarning();
		cout << "메뉴를 잘못 선택하셨습니다. 모드 선택으로 돌아갑니다." << endl;
	}
}

void SellerHandler::showAllReceipt()
{	// 전체 영수증 확인
	manager.printAllReceipt();

}

void SellerHandler::showList(map<Item, int> List)
{
	// 주문서에 출력될 '개인 장바구니' 출력
	map<Item, int>::iterator it = List.begin();
	for (it; it != List.end(); it++) {
		cout << it->first.name << "\t" << it->second << "개" << "\t" << it->first.price * it->second << endl;
	}
}


void SellerHandler::confirmSell()
{	
	// 판매자가 ID를 입력하고 ID가 존재할 경우 그 영수증에 대한 구매 확정 여부를 결정
	// 대기, 확정, 취소 상태로 설정할 수 있음
	string id;
	cout << "확인할 영수증 ID :";
	cin >> id;

	vector<Receipt>::iterator it = receiptList->begin();
	for (it; it != receiptList->end(); it++) {
		if (it->ID == id) {
			break;
		}
		// ID에 맞는 영수증이 없을 경우 예외 처리
		if (it == receiptList->end()) {		
			cout << "ID에 맞는 영수증이 없습니다." << endl;
			return;		
		}
	}
	// ID에 해당하는 주문서 출력
	cout << "<주문서>" << endl;
	showList(it->List);
	cout << "총 금액 : " << it->Total;

	int state = 1;
	// 영수증 상태 변경 및 예외 클래스를 이용한 예외 처리
	try {
		cout << "상태 설정 ( 0:대기 / 1:확정 / 2:취소 ): ";
		cin >> state;

		switch (state)
		{
		case 0:
			it->State = 0;
			cout << id << "의 주문서가 " << "대기 상태가 되었습니다." << endl;
		case 1:
			manager.confirmBuy(*it);
			cout << id << "의 주문서가 " << "확정되었습니다." << endl;
			break;
		case 2:
			manager.cancelBuy(*it);
			cout << id << "의 주문서가 " << "취소되었습니다." << endl;
			break;
		default:
			throw ArrangeException(state);
			break;
		}
	}
	catch (ArrangeException e) {
		e.printWarning();
		cout << "이전 단계로 돌아갑니다." << endl;
	}
}


void SellerHandler::addItem()
{
	cin >> *itemList;		// >> 연산자 오버로딩
	sortItem();
}

void SellerHandler::subItem()
{
	showItem();
	manager.delItem();
}

void SellerHandler::showItem() {
	sortItem();	// 이름 순으로 정렬
	// 판매 품목 보여주기
	cout << "번호\t" << "이름\t" << "가격\t" << endl;

	int index = 1;

	for (int i = 0; i < itemList->size(); i++) {
		// << 연산자 오버로딩
		cout << index << "\t";
		cout << itemList->at(index-1);
		index++;
	}
	
}

void SellerHandler::sortItem() {
	// 알고리즘 sort 사용하여 아이템(이름 순서로) 정렬
	sort(itemList->begin(), itemList->end());
}

void SellerHandler::printTotalSales()
{
	//총 주문서와 판매액 텍스트 파일에 출력
	manager.printTotalSalesToFile();
}
