#include "Manager.h"
#include "NoItemException.cpp"
#include <iostream>
#include <fstream>
using namespace std;

void Manager::confirmBuy(Receipt& r)
{
	r.State = 1;
}

void Manager::cancelBuy(Receipt& r)
{
	r.State = 2;
}

void Manager::printTotalSalesToFile()
{	
	// 모든 주문서(영수증)를 출력해서 파일에 입력
	ofstream file;
	file.open("C:\\Users\\sky\\receipt.txt");    //파일 열기(파일이 없으면 만들어짐)
	vector<Receipt>::iterator it = receiptList->begin();
	string receiptStr = "";
	receiptStr += "ID 총 가격\t\t상태\n";
	for (it; it != receiptList->end(); ++it)
	{   
		receiptStr = receiptStr + it->ID + "    " + to_string(it->Total) + "\t" + to_string(it->State) + "\n";
		receiptStr += "┌──────── 주문 ───────┐\n│";
		map<Item, int>::iterator it2 = it->List.begin();
		for (it2; it2 != it->List.end(); it2++) {
			receiptStr = receiptStr + " " +it2->first.name + "\t" + to_string(it2->second) + "개\t" + to_string(it2->first.price * it2->second)+"\t\t"  + "\n";
		}
		receiptStr += "└──────────────────┘\n\n";
	}
	file.write(receiptStr.c_str(), receiptStr.size());
	string str = "배송비 제외 순 매출액 : ";
	str += to_string(*totalSales);
	file.write(str.c_str(), str.size());

	file.close();    //꼭 닫아주기

}

void Manager::printAllReceipt()
{	// 모든 주문서(영수증)를 출력
	vector<Receipt>::iterator it = receiptList->begin();
	cout << "ID " << "총 가격\t" << "상태\t" << endl;
	for (it; it != receiptList->end(); ++it)
	{
		cout << it->ID << "    " << it->Total << "    " << it->State << endl;
		cout << "┌──────── 주문 ───────┐" << endl;
		map<Item, int>::iterator it2 = it->List.begin();
		for (it2; it2 != it->List.end(); it2++) {
			cout <<" "<< it2->first.name << "\t" << it2->second << "개" << "\t" << it2->first.price * it2->second << endl;
		}
		cout << "└─────────────────────┘" << endl;
	}

	for (it=receiptList->begin() ; it != receiptList->end(); ++it) {
		switch (it->State) {
		case 0:
			cout << it->ID << " " << it->Total << "\t대기" << endl;
			break;
		case 1:
			cout << it->ID << " " << it->Total << "\t확정" << endl;
			break;
		case 2:
			cout << it->ID << " " << it->Total << "\t취소" << endl;
			break;
		}

	}
}

void Manager::delItem()
{	// 품목 삭제
	string name;
	try {
		cout << "삭제할 품목 이름을 입력하세요 : ";
		cin >> name;
		vector<Item>::iterator it = itemList->begin();
		for (; it != itemList->end(); it++) {
			if (it->name == name) {
				it = itemList->erase(it);
				break;
			}
		}
		if (it == itemList->end()) {
			throw NoItemException(name);
		}
	}
	catch (NoItemException e) {		// 삭제하려는 품목이 없을 때 예외처리
		cout << e.getItem() << "이 품목에 없습니다." << endl;
	}
}
