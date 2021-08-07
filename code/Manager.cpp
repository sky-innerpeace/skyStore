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
	// ��� �ֹ���(������)�� ����ؼ� ���Ͽ� �Է�
	ofstream file;
	file.open("C:\\Users\\sky\\receipt.txt");    //���� ����(������ ������ �������)
	vector<Receipt>::iterator it = receiptList->begin();
	string receiptStr = "";
	receiptStr += "ID �� ����\t\t����\n";
	for (it; it != receiptList->end(); ++it)
	{   
		receiptStr = receiptStr + it->ID + "    " + to_string(it->Total) + "\t" + to_string(it->State) + "\n";
		receiptStr += "������������������ �ֹ� ����������������\n��";
		map<Item, int>::iterator it2 = it->List.begin();
		for (it2; it2 != it->List.end(); it2++) {
			receiptStr = receiptStr + " " +it2->first.name + "\t" + to_string(it2->second) + "��\t" + to_string(it2->first.price * it2->second)+"\t\t"  + "\n";
		}
		receiptStr += "����������������������������������������\n\n";
	}
	file.write(receiptStr.c_str(), receiptStr.size());
	string str = "��ۺ� ���� �� ����� : ";
	str += to_string(*totalSales);
	file.write(str.c_str(), str.size());

	file.close();    //�� �ݾ��ֱ�

}

void Manager::printAllReceipt()
{	// ��� �ֹ���(������)�� ���
	vector<Receipt>::iterator it = receiptList->begin();
	cout << "ID " << "�� ����\t" << "����\t" << endl;
	for (it; it != receiptList->end(); ++it)
	{
		cout << it->ID << "    " << it->Total << "    " << it->State << endl;
		cout << "������������������ �ֹ� ����������������" << endl;
		map<Item, int>::iterator it2 = it->List.begin();
		for (it2; it2 != it->List.end(); it2++) {
			cout <<" "<< it2->first.name << "\t" << it2->second << "��" << "\t" << it2->first.price * it2->second << endl;
		}
		cout << "����������������������������������������������" << endl;
	}

	for (it=receiptList->begin() ; it != receiptList->end(); ++it) {
		switch (it->State) {
		case 0:
			cout << it->ID << " " << it->Total << "\t���" << endl;
			break;
		case 1:
			cout << it->ID << " " << it->Total << "\tȮ��" << endl;
			break;
		case 2:
			cout << it->ID << " " << it->Total << "\t���" << endl;
			break;
		}

	}
}

void Manager::delItem()
{	// ǰ�� ����
	string name;
	try {
		cout << "������ ǰ�� �̸��� �Է��ϼ��� : ";
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
	catch (NoItemException e) {		// �����Ϸ��� ǰ���� ���� �� ����ó��
		cout << e.getItem() << "�� ǰ�� �����ϴ�." << endl;
	}
}
