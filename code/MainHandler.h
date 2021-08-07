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

	ConsumerHandler ch;			// �Һ��� Handler
	SellerHandler sh;					// �Ǹ��� Handler

	vector<Item> itemList;			// �Ǹ� ��ǰ ���
	vector<Receipt> receiptList;	// �Һ��� ������ ���
	shared_ptr<int> totalSales = make_shared<int>(0); // ��ۺ� ������ �� �����

	void showSelectMode() {		// ��� ����
		int choice;
		while (1) {
			
			cout << "��弱��(1:�Һ���, 2:������, 3: ����) : ";
			cin >> choice;
			cout << endl;

			// ���� ���� �������� int���� ����ް� ���� '\n'�� �Է¹��ۿ��� �����ֱ� ���� ����
			cin.clear();
			cin.ignore();

			switch (choice)
			{
			case 1:
				// ������(�Ǹ���) ��� ���� �� ����
				ch = ConsumerHandler(&itemList, &receiptList, totalSales);
				ch.MainMenu();
				// �Է¹��� clear
				cin.clear();
				cin.ignore();
				break;
			case 2:
				// ������(�Ǹ���) ��� ���� �� ����
				sh = SellerHandler(&itemList, &receiptList, totalSales);
				sh.Mainmenu();
				// �Է¹��� clear
				cin.clear();
				cin.ignore();
				break;
			case 3:
				// ����
				cout << "�̿����ּż� �����մϴ�. ���α׷��� �����մϴ�." << endl;
				return;
				break;
			default:
				// 1~3 �̿��� �ٸ� ���� ���� �� ���� ó��
				cout << "��带 �ٽ� �����ϼ���" << endl;
			}
		}
	}
	void showMessage() {		// ȯ�� ����
		cout << "********************************************" << endl;
		cout << "** �ϴ��̳� ��ȭ���� ���� ���� ȯ���մϴ� **" << endl;
		cout << "********************************************" << endl;
	}
	
	
};
#endif