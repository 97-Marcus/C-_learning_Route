#include<iostream>
#include<string>
using namespace std;

//// ˽�б������ü���ȡֵ
//
//class CPeople {  
//private:
//	int m_nAge;		
//protected:
//	bool m_bSex;
//public:
//	string m_strName;
//	void show() {	
//		cout << m_strName << endl;
//		cout << m_bSex << endl;
//		cout << m_nAge << endl;
//	}
//
//	//����˽�б����������ṩһ���ӿڣ�����һ�����еĺ�����ȥ���ü���ȡֵ��
//	void SetAge(int age) {
//		m_nAge = age;
//	}
//	int GetAge() {
//		return m_nAge;
//	}
//	//���˽�б����ڶ࣬ÿ����Ҫ������������ȥ���úͻ�ȡ����鷳��������Ҫ���캯�����������е�һ�����⺯����������в�д������������ṩһ��Ĭ�ϵ��޲εĹ��캯��(�������ǵ�ǰ������û�з���ֵ)�����д�Ļ���д����Ϊ���캯���������������ṩ�ˡ�
//};
//
//
//int main() {
//
//	//CPeople people;	
//	////people.m_nAge = 10;
//	////people.m_bSex = true;
//	//people.m_strName = "С��";
//	//people.show();
//
//	CPeople* pPeo = new CPeople;
//	pPeo->m_strName = "С��";
//
//	pPeo->SetAge(18);
//	cout << pPeo->GetAge() << endl;
//
//	pPeo->show();
//
//	system("pause");
//	return 0;
//}


////������Ϊ��ǰ������û�з���ֵ������������Ҳ����û��
////���캯��:������ʼ�����Ա�������������ʱ���Զ����á������ж�����캯�����Ǻ������صĹ�ϵ�������������ִֻ��ĳһ�����캯����
////�������������ڻ��տռ䣩���͹��캯���Ƕ�Ӧ��ϵ���������ͷų�Ա����ռ�ģ�������Ϊ~��������������ֻ����һ�������������޲������޷���ֵ��
//
//class CTest
//{
//public:
//	int m_nAge;
//	int m_nSex;
//	int* m_p;
//	CTest() {//�޲εĹ��캯��
//		m_nAge = 10;
//		m_p = new int(10);
//	}
//	CTest(int age) {//�вεĹ��캯��
//		m_nAge = age;
//	}
//	CTest(int age, int sex)
//	{
//		m_nAge = age;
//		m_nSex = sex;
//	}
//	//��������
//	~CTest() 
//	{
//		cout << "~CTest" << endl;
//		if (m_p) {
//			delete m_p;
//			m_p = NULL;
//		}//�����������ڽ���ʱ����ִ���������������ͷŶ����ջ���Ŀռ�
//	}
//protected:
//private:
//};
//
//int main() {
//	//CTest tst;//�����޲εĹ��캯��
//	//cout << tst.m_nAge << endl;
//
//	//CTest tst2(12);//�����вεĹ��캯��
//	//cout << tst2.m_nAge << endl;
//
//	//CTest* pTst = new CTest(12, 1);
//	//cout << pTst->m_nAge << endl;
//	//cout << pTst->m_nSex << endl;
//
//	//delete pTst; //new�˾�Ҫdelete �ͷ�ʱ���Զ�������������
//	//pTst = NULL;
//
//	{
//		CTest tst;
//	}//�������Զ��ͷ� �ͷ�ʱҲ���Զ�������������
//
//	system("pause");
//	return 0;
//}



///*
//��ϰ��
//��װһ��CDate�ࣺ
//��Ա����Ϊ�ꡢ�¡���
//��Ա����Ϊ���졢��������ʾ���ڣ�Display�����������ڲSetDate������
//һ��CDate�������������������ʾ�ꡢ�¡��գ�2021.3.3������ʼ�������ҿ��Զ����ڵ����ý��кϷ���У�飬Ҫ��ʵ��CDate��ĳ�Ա��
//*/
//
//
//class CDate {
//public:
//	int m_nYear;
//	int m_nMonth;
//	int m_nDay;
//public:
//	CDate() {
//		m_nYear = 1970;
//		m_nMonth = 1;
//		m_nDay = 1;
//	}
//	~CDate() {
//		m_nYear = 0;//��ָ��Ļ�����д��û��ָ����Բ�д�������ϸ��϶�Ҫд���óɵ�ǰ���͵ĳ�ʼֵ
//		m_nMonth = 0;
//		m_nDay = 0;
//	}
//public:
//	void Display() {
//		cout << m_nYear << "-" << m_nMonth << "-" << m_nDay << endl;
//	}
//	void SetDate(int year, int month, int day) {
//		if (year >= 1970 && year <= 2099)
//		{
//			m_nYear = year;
//		}
//		if (month >= 1 && month <= 12)
//		{
//			m_nMonth = month;
//		}
//		if (day >= 1 && day <= 30)
//		{
//			m_nDay = day;
//		}
//	}
//};
//
//int main() {
//	CDate date;
//
//	date.Display();
//
//	date.SetDate(2021, 5, 21); 
//	
//	date.Display();
//
//	system("pause");
//	return 0;
//}



////��װ����
//
///*
//C++��struct�ṹ���class�������
//1.���Ĭ�Ϸ������η���˽��private�� �ṹ���Ĭ�Ϸ������η��ǹ���public��
//2.���Ĭ�ϼ̳з�ʽ��˽��privat�� �ṹ���Ĭ�ϼ̳з�ʽ�ǹ���public��
//*/
//
//struct Node {
//	int val;
//	Node* pNext;
//	Node(int v) {
//		val = v;
//		pNext = NULL;
//	}
//};
//
//class MyList
//{
//public:
//	Node* m_pHead;
//	Node* m_pEnd;
//	int m_nLen;//������ �ڵ����
//public:
//	MyList() {
//		m_pHead = NULL;
//		m_pEnd = NULL;
//		m_nLen = 0;
//	}
//	~MyList() {//�������������ڽ�������������Ӧ�ñ�������ɾ���ڵ�
//		Node* pTemp = NULL;
//		while (m_pHead) {
//			pTemp = m_pHead;
//			m_pHead = m_pHead->pNext;
//			delete pTemp;
//			pTemp = NULL;
//		}
//		m_pHead = NULL;
//		m_pEnd = NULL;
//		m_nLen = 0;
//	}
//public:
//	void PushBack(int v) {
//		//Node* pTemp = new Node;//����û��Ĭ�ϵĹ��캯����ԭ���ǽṹ����д�˹��캯�������ϵͳ�����ṩĬ�ϵĹ��캯�������ǲ���д���вεĹ��캯��
//		Node* pTemp = new Node(v);
//
//		if (m_pHead){
//			m_pEnd->pNext = pTemp;
//			m_pEnd = m_pEnd->pNext;
//		}
//		else {
//			m_pHead = pTemp;
//			m_pEnd = pTemp;
//		}
//		m_nLen++;
//
//	}
//
//	void show() {
//		Node* pTemp = m_pHead;
//		while (pTemp) {
//			cout << pTemp->val << "	";
//			pTemp = pTemp->pNext;
//		}
//		cout << endl;
//	}
//
//	void PopFront() {//ͷɾ��
//		if (m_pHead)
//		{
//			Node* pTemp = m_pHead;
//			if (m_pHead == m_pEnd) 
//			{
//				//delete pTemp;
//				//pTemp = NULL;
//				m_pHead = NULL;
//				m_pEnd = NULL;
//			} 
//			else
//			{
//				m_pHead = m_pHead->pNext;
//				//delete pTemp;
//				//pTemp = NULL;
//			}
//			delete pTemp;
//			pTemp = NULL;
//			m_nLen--;
//		}
//	}
//
//protected:
//private:
//};
//
//
//
//int main() {
//	MyList lst;
//
//	lst.PushBack(1);
//	lst.PushBack(2);
//	lst.PushBack(3);
//	lst.PushBack(4);
//
//	lst.show();
//
//	lst.PopFront();
//	lst.show();
//	lst.PopFront();
//	lst.show();	
//
//	system("pause");
//	return 0;
//}