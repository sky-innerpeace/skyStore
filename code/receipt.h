#pragma once
#ifndef __RECEIPT_H__
#define __RECEIPT_H__
#include <map>
#include <string>
#include "item.h"
using namespace std;

struct Receipt {

	string ID;
	map<Item, int> List;
	int Total;
	int State; //0=��� 1=Ȯ�� 2=���
	string message;

	// �������� ���� �ϴ� ����
	// ������� ������ id, �� ����, ����ǰ��, ����Ȯ�� ����, VVIP ���� ��û�޽���
	Receipt(string id, int total, map<Item, int> list, int state, string message = "")
		:ID(id), Total(total), List(list), State(state) {}

	// < ������ �����ε�
	// ���� ������ ID�� ����
	bool operator<(const Receipt& other) const {
		return ID < other.ID;
	}
};
#endif