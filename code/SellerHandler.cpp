#include "SellerHandler.h"
#include "Manager.h"
#include "ArrangeException.cpp"
#include <iostream>
#include <algorithm>
using namespace std;

// << ������ �����ε�
ostream& operator<<(ostream& ostream, const Item& i) {
	ostream << i.name << "\t\t" << i.price << endl;

	return ostream;

}

// >> ������ �����ε�
istream& operator >>(istream& istream, vector<Item>& item) {
	string name;
	int price;
	cout << "�߰��� ǰ�� �̸��� ������ �Է��ϼ���(�̸� ����) : ";
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
			cout << "**** �Ǹ��ڸ޴� ****" << endl;
			cout << "1.������ �߰�" << endl;
			cout << "2. ������ ����" << endl;
			cout << "3. ������ ��� Ȯ��" << endl;
			cout << "4. ������ ��� Ȯ��" << endl;
			cout << "5. ������ ���� ����" << endl;
			cout << "6. �ؽ�Ʈ ���Ϸ� ���" << endl;
			cout << "7.����" << endl;
			cout << "*******************" << endl;
			cout << "�޴� ���� : ";
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
				return;		//����
				break;
			default:
				cout << "�ٽ� �Է��ϼ���." << endl;
				break;
			}
		}
	}
	catch (ArrangeException e) {
		e.printWarning();
		cout << "�޴��� �߸� �����ϼ̽��ϴ�. ��� �������� ���ư��ϴ�." << endl;
	}
}

void SellerHandler::showAllReceipt()
{	// ��ü ������ Ȯ��
	manager.printAllReceipt();

}

void SellerHandler::showList(map<Item, int> List)
{
	// �ֹ����� ��µ� '���� ��ٱ���' ���
	map<Item, int>::iterator it = List.begin();
	for (it; it != List.end(); it++) {
		cout << it->first.name << "\t" << it->second << "��" << "\t" << it->first.price * it->second << endl;
	}
}


void SellerHandler::confirmSell()
{	
	// �Ǹ��ڰ� ID�� �Է��ϰ� ID�� ������ ��� �� �������� ���� ���� Ȯ�� ���θ� ����
	// ���, Ȯ��, ��� ���·� ������ �� ����
	string id;
	cout << "Ȯ���� ������ ID :";
	cin >> id;

	vector<Receipt>::iterator it = receiptList->begin();
	for (it; it != receiptList->end(); it++) {
		if (it->ID == id) {
			break;
		}
		// ID�� �´� �������� ���� ��� ���� ó��
		if (it == receiptList->end()) {		
			cout << "ID�� �´� �������� �����ϴ�." << endl;
			return;		
		}
	}
	// ID�� �ش��ϴ� �ֹ��� ���
	cout << "<�ֹ���>" << endl;
	showList(it->List);
	cout << "�� �ݾ� : " << it->Total;

	int state = 1;
	// ������ ���� ���� �� ���� Ŭ������ �̿��� ���� ó��
	try {
		cout << "���� ���� ( 0:��� / 1:Ȯ�� / 2:��� ): ";
		cin >> state;

		switch (state)
		{
		case 0:
			it->State = 0;
			cout << id << "�� �ֹ����� " << "��� ���°� �Ǿ����ϴ�." << endl;
		case 1:
			manager.confirmBuy(*it);
			cout << id << "�� �ֹ����� " << "Ȯ���Ǿ����ϴ�." << endl;
			break;
		case 2:
			manager.cancelBuy(*it);
			cout << id << "�� �ֹ����� " << "��ҵǾ����ϴ�." << endl;
			break;
		default:
			throw ArrangeException(state);
			break;
		}
	}
	catch (ArrangeException e) {
		e.printWarning();
		cout << "���� �ܰ�� ���ư��ϴ�." << endl;
	}
}


void SellerHandler::addItem()
{
	cin >> *itemList;		// >> ������ �����ε�
	sortItem();
}

void SellerHandler::subItem()
{
	showItem();
	manager.delItem();
}

void SellerHandler::showItem() {
	sortItem();	// �̸� ������ ����
	// �Ǹ� ǰ�� �����ֱ�
	cout << "��ȣ\t" << "�̸�\t" << "����\t" << endl;

	int index = 1;

	for (int i = 0; i < itemList->size(); i++) {
		// << ������ �����ε�
		cout << index << "\t";
		cout << itemList->at(index-1);
		index++;
	}
	
}

void SellerHandler::sortItem() {
	// �˰��� sort ����Ͽ� ������(�̸� ������) ����
	sort(itemList->begin(), itemList->end());
}

void SellerHandler::printTotalSales()
{
	//�� �ֹ����� �Ǹž� �ؽ�Ʈ ���Ͽ� ���
	manager.printTotalSalesToFile();
}
