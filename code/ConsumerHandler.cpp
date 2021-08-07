#include "ConsumerHandler.h"
#include "ArrangeException.cpp"

#include <algorithm>


void ConsumerHandler::MainMenu() {
	// ���� �޴�

	int cmd;	// �Һ��� �޴�
	string id;	// ����� ID
	int grade;
	try {
		while (true) {


			cout << "*** �Һ��� �޴� ***" << endl;
			cout << "1.��ٱ��� ����" << endl;
			cout << "2. ��ٱ��� ����(ID)" << endl;
			cout << "3. ����" << endl;
			cout << "�������� �ʰ� ���� �� ��ٱ��ϰ� �����˴ϴ�" << endl;
			cout << "******************" << endl;
			cout << "�޴� ���� : ";
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
				//id�� �Է¹ް� �׿� �´� GoToShoppingCart ȣ��
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
		cout << "�߸� �����ϼ̽��ϴ�. ��� �������� ���ư��ϴ�." << endl;
		
	}

}

// id�� ����īƮ ã��
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
// ���� ó�� �Ϸ�
void ConsumerHandler::GoToShppoingCart(string ID)
{
	int grade = 0;
	int indexid = FindMyShoppingCart(ID, &grade);
	if (indexid == 11)
	{
		cout << "��ȿ���� ���� ID�Դϴ�."<<endl;
	}
	else
	{
		shoppingMenuList(indexid, grade);
	}

}


string ConsumerHandler::MakeShoppingCart()		// ���� ��� ����
{
	int grade =0;
	string id ="";

	try {
		cout << "***************** ��� ���� [1:�⺻ 2 : SVIP 3 : VVIP] *****************" << endl;
		cout << "** VVIP ���� : ������ 3% ����, �Ǹ��ڿ��� ���� ��û �޽��� �ۼ� ���� **" << endl;
		cout << "*************** SVIP ���� : ������, 5000���� ���� ���� ***************" << endl;

		cin.clear();
		cin.ignore();

		cout << "��� ���� : ";
		cin >> grade;
		cout << "ID �Է� : ";
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
		cout << "����� �߸� �Է��ϼ̽��ϴ�. ���� �޴��� ���ư��ϴ�." << endl;
	}

	return id;
}



void ConsumerHandler::shoppingMenuList(int indexid, int grade)		// ��ٱ��� ����, �߰�, ���� ���� ���
{
	int cmd = 0;
	try {
		while (cmd != 6)
		{
			cout << "******* [MENU] *******" << endl;
			cout << "1.��ٱ��Ͽ� �߰�" << endl;
			cout << "2.��ٱ��Ͽ��� ����" << endl;
			cout << "3. ��ٱ��� Ȯ��     " << endl;
			cout << "4. ��ٱ��� �ʱ�ȭ" << endl;
			cout << "5. ���� " << endl;
			cout << "6. ����" << endl;
			cout << "*********************" << endl;

			cin.clear();
			cin.ignore();

			cout << "�޴� ���� : ";
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
		cout << "��ٱ��� �޴��� �߸� �����ϼ̽��ϴ�. ���� �޴��� ���ư��ϴ�." << endl;
	}
}

void ConsumerHandler::PrintShoppingCart(int indexid, int grade)
{
	cout << endl;
	cout << "���� ������ ��ٱ��ϸ� ��ȸ�մϴ�.." << endl;
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
	cout << "��ȣ\t " << "�̸�\t" << "����\t" << endl;
	// for_each algorithm�� ����� �����۸���Ʈ ���
	for_each(itemList->begin(), itemList->end(), ([&index, &it](Item v) { cout << index << "\t " << v.name << "\t" << v.price << endl; index++; }));

}

// ��ٱ��Ͽ� ��ǰ �߰�
void ConsumerHandler::AddItem(int indexid, int grade)
{
	int itemcode;
	int itemnum;
	try {
		cout << endl;
		cout << "��ٱ��Ͽ� �߰��Ͻ� ǰ���� �������ּ���." << endl;
		cout << endl;

		ShowItemList();

		cout << "��ǰ ��ȣ >> ";
		cin >> itemcode;
		if (!(itemcode < itemList->size()+1 && itemcode > 0)) { throw ArrangeException(itemcode); }
		cout << "���� >> ";
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
		cout << "��ǰ ��ȣ�� �߸��Ǿ����ϴ�. ���� �޴��� ���ư��ϴ�." << endl;
	}
}

// ��ٱ��Ͽ��� ��ǰ ����
void ConsumerHandler::DelItem(int indexid, int grade)
{
	string name;

	cout << endl;
	cout << "��ٱ��Ͽ��� �����Ͻ� ǰ���� �������ּ���." << endl;
	cout << endl;

	PrintShoppingCart(indexid, grade);
	cout << "������ ��ǰ��: ";
	
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
	string id;			// ����� ID
	int total;			// �� �ݾ�
	int state = 0;		// ��� ����
	map<Item, int> cart;		// ��ٱ���
	string message;			// VVIP�� �Ǹ��ڿ��� ���� �� �ִ� ��û �޽���

	if (grade == 1)
	{
		id = SAList[indexid]->ID;
		total = SAList[indexid]->getTotalPrice() + SAList[indexid]->getDeliveryFee();
		*totalSales += total - SAList[indexid]->getDeliveryFee();		// �� ���⿡ �߰�
		cart = SAList[indexid]->shoppingCart;
		message = "";
	}
	if (grade == 2)
	{
		id = SVList[indexid]->ID;
		total = SVList[indexid]->getTotalPrice()+ SVList[indexid]->getDeliveryFee();
		*totalSales += total - SAList[indexid]->getDeliveryFee();		// �� ���⿡ �߰�
		cart = SVList[indexid]->shoppingCart;
		message = "";
	}
	if (grade == 3)
	{
		id = VVList[indexid]->ID;
		total = VVList[indexid]->getTotalPrice() + VVList[indexid]->getDeliveryFee();
		*totalSales += total - SAList[indexid]->getDeliveryFee();		// �� ���⿡ �߰�
		cart = VVList[indexid]->shoppingCart;
		message = VVList[indexid]->sendMessage();
	}
	
	cout << "����� ID : " << id << endl;
	PrintShoppingCart(indexid, grade);
	cout << "�� �ݾ� : " << total << endl;
	switch (state) {
	case 0:
		cout << "���� : ���" << endl;
		break;
	case 1:
		cout << "���� : Ȯ��" << endl;
		break;
	case 2:
		cout << "���� : ���" << endl;
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