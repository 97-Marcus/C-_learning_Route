#include "AA.h"

GET_OBJECT(CAA)
CLASS_CONFIG(400, 0, 500, 500, "��Ϣӳ���")

CAA::CAA(void) { }
CAA::~CAA(void) { }

const MessageEntry* CAA::GetMessageMap() {

	static const MessageEntry MessageMap[] = {
		{WM_CREATE,(P_FUN)&CAA::OnCreate},	//typedef void(CGameApp::* P_FUN) ();
		{WM_PAINT,(P_FUN)&CAA::OnPaint},	//�����Ҫǿת
		{WM_AAA,(P_FUN)&CAA::OnAAA},		

		{0,NULL}	//β��������־
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