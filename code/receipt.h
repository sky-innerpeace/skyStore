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
	int State; //0=대기 1=확정 2=취소
	string message;

	// 영수증에 들어가야 하는 정보
	// 순서대로 구매자 id, 총 가격, 구매품목, 구매확정 여부, VVIP 전용 요청메시지
	Receipt(string id, int total, map<Item, int> list, int state, string message = "")
		:ID(id), Total(total), List(list), State(state) {}

	// < 연산자 오버로딩
	// 정렬 기준을 ID로 설정
	bool operator<(const Receipt& other) const {
		return ID < other.ID;
	}
};
#endif