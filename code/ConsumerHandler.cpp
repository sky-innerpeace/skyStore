#include "ConsumerHandler.h"
#include "ArrangeException.cpp"

#include <algorithm>


void ConsumerHandler::MainMenu() {
	// 메인 메뉴

	int cmd;	// 소비자 메뉴
	string id;	// 사용자 ID
	int grade;
	try {
		while (true) {


			cout << "*** 소비자 메뉴 ***" << endl;
			cout << "1.장바구니 생성" << endl;
			cout << "2. 장바구니 접속(ID)" << endl;
			cout << "3. 종료" << endl;
			cout << "구매하지 않고 종료 시 장바구니가 삭제됩니다" << endl;
			cout << "******************" << endl;
			cout << "메뉴 선택 : ";
			cin >> cmd;
			if (!(cmd >= 1 && cmd <= 3)) {
				throw ArrangeException(cmd);
				continue;
			}
			
			switch (cmd)
			{
			case 1:
				id = MakeShoppingCart();
				GoToShppoingCart(id);
				break;
			case 2:
				//id를 입력받고 그에 맞는 GoToShoppingCart 호출
				cout << "id : ";
				cin >> id;
				GoToShppoingCart(id);
				break;
			case 3:
				return;
			default:
				break;
			}

		}
	} catch (ArrangeException e) {
		cout << "잘못 선택하셨습니다. 모드 선택으로 돌아갑니다." << endl;
		
	}

}

// id로 쇼핑카트 찾기
int ConsumerHandler::FindMyShoppingCart(string ID, int * grade)
{

	for (int i = 0; i < 10; i++)
	{
		if (SAList[i] != NULL)
		{
			if (SAList[i]->ID == ID)
			{
				*grade = 1;
				return i;
			}
		}

		if (SVList[i] != NULL)
		{
			if (!SVList[i]->ID.compare(ID))
			{
				*grade = 2;
				return i;
			}
		}

		if (VVList[i] != NULL)
		{
			if (!VVList[i]->ID.compare(ID))
			{
				*grade = 3;
				return i;
			}
		}

	}
	return 11;
}
// 예외 처리 완료
void ConsumerHandler::GoToShppoingCart(string ID)
{
	int grade = 0;
	int indexid = FindMyShoppingCart(ID, &grade);
	if (indexid == 11)
	{
		cout << "유효하지 않은 ID입니다."<<endl;
	}
	else
	{
		shoppingMenuList(indexid, grade);
	}

}


string ConsumerHandler::MakeShoppingCart()		// 계정 등급 결정
{
	int grade =0;
	string id ="";

	try {
		cout << "***************** 등급 종류 [1:기본 2 : SVIP 3 : VVIP] *****************" << endl;
		cout << "** VVIP 혜택 : 할인율 3% 적용, 판매자에게 개인 요청 메시지 작성 가능 **" << endl;
		cout << "*************** SVIP 혜택 : 무료배송, 5000원권 쿠폰 제공 ***************" << endl;

		cin.clear();
		cin.ignore();

		cout << "등급 선택 : ";
		cin >> grade;
		cout << "ID 입력 : ";
		cin >> id;

		if (!(grade >= 1 && grade <= 3)) {
			throw ArrangeException(grade);
		}
		switch (grade) {
		case 1:
			SAList[SAindex++] = new Standard(id);
			break;
		case 2:
			SVList[SVindex++] = new SVIP(id);
			break;
		case 3:
			VVList[VVindex++] = new VVIP(id);
			break;
		}
	}
	catch (ArrangeException e) {
		cout << "등급을 잘못 입력하셨습니다. 이전 메뉴로 돌아갑니다." << endl;
	}

	return id;
}



void ConsumerHandler::shoppingMenuList(int indexid, int grade)		// 장바구니 생성, 추가, 삭제 등의 기능
{
	int cmd = 0;
	try {
		while (cmd != 6)
		{
			cout << "******* [MENU] *******" << endl;
			cout << "1.장바구니에 추가" << endl;
			cout << "2.장바구니에서 삭제" << endl;
			cout << "3. 장바구니 확인     " << endl;
			cout << "4. 장바구니 초기화" << endl;
			cout << "5. 구매 " << endl;
			cout << "6. 종료" << endl;
			cout << "*********************" << endl;

			cin.clear();
			cin.ignore();

			cout << "메뉴 선택 : ";
			cin >> cmd;
			if (!(cmd >= 1 && cmd <= 6)) {
				throw ArrangeException(cmd);
				continue;
			}
			switch (cmd)
			{
			case 1:
				AddItem(indexid, grade);
				break;
			case 2:
				DelItem(indexid, grade);
				break;
			case 3:
				PrintShoppingCart(indexid, grade);
				break;
			case 4:
				ResetShoppingCart(indexid, grade);
				break;
			case 5:
				BuyItem(indexid, grade);
				break;
			case 6:
				break;
			default:
				break;
			}
		}
	}
	catch (ArrangeException e) {
		e.printWarning();
		cout << "장바구니 메뉴를 잘못 선택하셨습니다. 이전 메뉴로 돌아갑니다." << endl;
	}
}

void ConsumerHandler::PrintShoppingCart(int indexid, int grade)
{
	cout << endl;
	cout << "현재 고객님의 장바구니를 조회합니다.." << endl;
	cout << endl;

	if (grade == 1)
	{
		SAList[indexid]->printShoppingList();
	}
	if (grade == 2)
	{
		SVList[indexid]->printShoppingList();
	}
	if (grade == 3)
	{
		VVList[indexid]->printShoppingList();
	}
}

void ConsumerHandler::ShowItemList()
{
	int index = 1; 

	vector<Item>::iterator it = itemList->begin();
	cout << "번호\t " << "이름\t" << "가격\t" << endl;
	// for_each algorithm을 사용한 아이템리스트 출력
	for_each(itemList->begin(), itemList->end(), ([&index, &it](Item v) { cout << index << "\t " << v.name << "\t" << v.price << endl; index++; }));

}

// 장바구니에 제품 추가
void ConsumerHandler::AddItem(int indexid, int grade)
{
	int itemcode;
	int itemnum;
	try {
		cout << endl;
		cout << "장바구니에 추가하실 품목을 선택해주세요." << endl;
		cout << endl;

		ShowItemList();

		cout << "제품 번호 >> ";
		cin >> itemcode;
		if (!(itemcode < itemList->size()+1 && itemcode > 0)) { throw ArrangeException(itemcode); }
		cout << "개수 >> ";
		cin >> itemnum;

		if (grade == 1)
		{
			SAList[indexid]->addToShoppingList(itemList->at(itemcode - 1), itemnum);
		}
		if (grade == 2)
		{
			SVList[indexid]->addToShoppingList(itemList->at(itemcode - 1), itemnum);
		}
		if (grade == 3)
		{
			VVList[indexid]->addToShoppingList(itemList->at(itemcode - 1), itemnum);
		}
	}
	catch (ArrangeException e) {
		cout << "제품 번호가 잘못되었습니다. 이전 메뉴로 돌아갑니다." << endl;
	}
}

// 장바구니에서 제품 삭제
void ConsumerHandler::DelItem(int indexid, int grade)
{
	string name;

	cout << endl;
	cout << "장바구니에서 삭제하실 품목을 선택해주세요." << endl;
	cout << endl;

	PrintShoppingCart(indexid, grade);
	cout << "삭제할 제품명: ";
	
	cin >> name;

	if (grade == 1)
	{
		SAList[indexid]->delToShoppingList(name);
	}
	if (grade == 2)
	{
		SVList[indexid]->delToShoppingList(name);
	}
	if (grade == 3)
	{
		VVList[indexid]->delToShoppingList(name);
	}
}

void ConsumerHandler::BuyItem(int indexid, int grade)
{	
	string id;			// 사용자 ID
	int total;			// 총 금액
	int state = 0;		// 대기 상태
	map<Item, int> cart;		// 장바구니
	string message;			// VVIP만 판매자에게 보낼 수 있는 요청 메시지

	if (grade == 1)
	{
		id = SAList[indexid]->ID;
		total = SAList[indexid]->getTotalPrice() + SAList[indexid]->getDeliveryFee();
		*totalSales += total - SAList[indexid]->getDeliveryFee();		// 총 매출에 추가
		cart = SAList[indexid]->shoppingCart;
		message = "";
	}
	if (grade == 2)
	{
		id = SVList[indexid]->ID;
		total = SVList[indexid]->getTotalPrice()+ SVList[indexid]->getDeliveryFee();
		*totalSales += total - SAList[indexid]->getDeliveryFee();		// 총 매출에 추가
		cart = SVList[indexid]->shoppingCart;
		message = "";
	}
	if (grade == 3)
	{
		id = VVList[indexid]->ID;
		total = VVList[indexid]->getTotalPrice() + VVList[indexid]->getDeliveryFee();
		*totalSales += total - SAList[indexid]->getDeliveryFee();		// 총 매출에 추가
		cart = VVList[indexid]->shoppingCart;
		message = VVList[indexid]->sendMessage();
	}
	
	cout << "사용자 ID : " << id << endl;
	PrintShoppingCart(indexid, grade);
	cout << "총 금액 : " << total << endl;
	switch (state) {
	case 0:
		cout << "상태 : 대기" << endl;
		break;
	case 1:
		cout << "상태 : 확정" << endl;
		break;
	case 2:
		cout << "상태 : 취소" << endl;
		break;
	}
	receiptList->push_back(Receipt(id, total, cart, state, message));
	

}

void ConsumerHandler::ResetShoppingCart(int indexid, int grade)
{
	if (grade == 1)
	{
		SAList[indexid]->resetMyList();
	}
	if (grade == 2)
	{
		SVList[indexid]->resetMyList();
	}
	if (grade == 3)
	{
		VVList[indexid]->resetMyList();
	}
}