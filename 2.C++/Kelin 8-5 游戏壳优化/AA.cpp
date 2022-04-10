#include "AA.h"

GET_OBJECT(CAA)
CLASS_CONFIG(400, 0, 500, 500, "消息映射表")

CAA::CAA(void) { }
CAA::~CAA(void) { }

const MessageEntry* CAA::GetMessageMap() {

	static const MessageEntry MessageMap[] = {
		{WM_CREATE,(P_FUN)&CAA::OnCreate},	//typedef void(CGameApp::* P_FUN) ();
		{WM_PAINT,(P_FUN)&CAA::OnPaint},	//因此需要强转
		{WM_AAA,(P_FUN)&CAA::OnAAA},		

		{0,NULL}	//尾，结束标志
	};

	return MessageMap;
}

void CAA::OnCreate() {
	int a = 1;
}

void CAA::OnPaint() {
	int a = 2;
}

void CAA::OnAAA() {
	int a = 3;
}