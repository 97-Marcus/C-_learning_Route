//#include <iostream>
//using namespace std;



////���ز�������
////�������Ǻ���,���߱������������������ʱȥ���ö�Ӧ������ִ�в������Ĺ��ܣ�һ����Ҫ�з���ֵ������ͺ���������������������56��
//
////�������أ�һ������¶����ڲ�������ߣ��������������ȥ���ò���������
//
//class CTest
//{
//public:
//	int m_a;
//	CTest() {
//		m_a = 10;
//	}
//
//	//void operator+(int a) {
//	//	m_a + a;
//	//}
//	//tst + 10;		����+�������
//	//�������أ���һ��Ĭ�ϵ����ز���this����Ӧtst�����滹��Ҫһ��int���͵Ĳ�����Ӧ10
//	//ע�⣺Ҳ����˵������+���ز�����ʱ��ʹ��˳��Ҫ�Ͳ���ƥ�䣬tst��int��˳�򲻿��Ե���
//
//	int operator+(int a) {
//		return m_a + a;
//	}
//
//	int operator=(int a) {
//		this->m_a = a;
//		return m_a;
//	}
//
//	int operator+=(int a) {
//		this->m_a += a;
//		return m_a;
//	}
//
//	int operator++() {	//��++���ȼӺ󷵻�
//		return ++this->m_a;
//	}
//
//	int operator++(int) {	//��++������+֮ǰ��
//		return this->m_a++;
//	}
//
//protected:
//private:
//};
//
//int main() {
//	CTest tst;
//	CTest tst1;
//	tst + 10;	//	CTest���ͺ�int���ͣ����Ͳ�ƥ���޷���ӡ�
//				//	ʵ�ʴ˴�����еĲ����ǽ�m_a+10����ô�˴������õ����ز�����
//	int a = tst1 + (tst + 10);	//tst+10����int���Ͷ���һ��void��Ҳ����˵��Ҫ������+�����ز�����������18-20�б�ע�Ͳ��֣����÷���ֵ
//
//	cout << a << endl;
//
//	CTest tst2;
//	tst2 = tst1 + (tst + 10);   // =������Ҳ��Ҫ���أ�������ɸ�tst2����ำֵΪ30�Ĳ���
//	cout << tst2.m_a << endl;
//
//	//����ʹ��+��=ȥ���ã�Ҳ�����ֶ�ȥ���ú��������£�
//	//tst1.operator+(12);
//
//	CTest tst3;
//	tst3 = tst1.operator+(12);
//	cout << tst3.m_a << endl;
//
//	CTest tst4;
//	CTest tst5;
//	tst5 = tst4 += 20;
//	cout << tst4.m_a << endl;	
//	cout << tst5.m_a << endl;
//
//	CTest tst6;
//	CTest tst7;
//	tst7 = ++tst6;
//	cout << tst7.m_a << endl;
//
//	CTest tst8;
//	CTest tst9;
//	tst9 = tst8++;
//	cout << tst9.m_a << endl;//��++�Ƿ���+֮ǰ�ģ�������10
//
//	system("pause");
//	return 0;
//}


//�������أ���Ҫע�����������صĳ�ͻ����

//tst + 10����ʹ���������أ��������10 + tst����ô�������ں���thisĬ��ָ��ӵ�һλ���������������޷���ɣ���ʱ����Ҫ����������
//
//class CTest
//{
//public:
//	int m_a;
//	CTest() {
//		m_a = 10;
//	}
//};
//
//int operator+(int a, CTest& tst) {
//	return a + tst.m_a;
//}
//
////int operator+(CTest& tst, int a) {
////	return a + tst.m_a;
////}	
//
////	����������ⶼ�����������غ�������ômain���õ���Ӧ���ط�ʱ�ᱨ������������+����Щ������ƥ�䡱��Ҳ����˵������غ���������Ҫ��ϵͳ��֪��Ӧ�õ����ĸ�����ʱ��Ҫ������һ������������ɾ������
//
//int operator++(CTest& tst) {	//��++���ȼӺ󷵻�
//	return ++tst.m_a;
//	}
//
//int operator++(CTest& tst,int) {	//��++������+֮ǰ��ֵ
//	return tst.m_a++;
//}
//
//ostream& operator<<(ostream& os, CTest& tst) {
//	os << tst.m_a;
//	return os;
//}	//���
//
//istream& operator>>(istream& is, CTest& tst) {
//	is >> tst.m_a;
//	return is;
//}	//����
//
//int main() {
//	CTest tst;
//	int a = 10 + tst;
//	cout << a << endl;
//
//	cout << ++tst.m_a << endl;
//	cout << tst.m_a++ << endl;
//
//	cout << tst << endl;	
//	//<<Ҳ�����ط������������ص���int���ͣ�������CTest�������Իᱨ����ô�Լ������ֶ�дһ�����������CTest���͵Ĳ�����
//	//cout��ostream���͵ģ��������غ���Ӧ�þ߱�����������һ����ostream��һ����CTest���͵ģ�ͬʱӦ��ʹ���������أ���Ϊ���ڵ����غ�����Ҫ�ö��������ã����˴�ʹ��cout���е���
//
//	cin >> tst;
//	cout << tst << endl;
//
//	system("pause");
//	return 0;
//}


//���ز�����������
//�����Ըı�ԭ�в�����ʹ�÷�����
// //���磺+��a+b�����Ҹ�һ��������������ز����������в������趨��ֻ��������������������ص�thisָ����Ϊ��������ô�����趨��ֻ������һ������18-20�У�
//��������ָ��Ĭ��ֵ��
// //���磺int operator+(int a = 10)
//Ҳ�����Ըı����ȼ��ͽ���ԣ�



////��������������
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
//// ������
//class CMyIterator {
//public:
//	Node* pTemp;
//public:
//	CMyIterator() {
//		pTemp = NULL;
//	}
//	CMyIterator(Node* pH) {
//		pTemp = pH;
//	}
//public:
//	bool operator==(Node* pNode) {
//		return pTemp == pNode ? true : false;
//	}
//	bool operator!=(Node* pNode) {
//		return pTemp != pNode ? true : false;
//	}
//	Node* operator=(Node* pNode) {
//		pTemp = pNode;
//		return pTemp;
//	}
//	int operator*() {
//		if (pTemp) {
//			return pTemp->val;
//		}
//		return -1;
//	}
//	Node* operator++() {		//��++
//		pTemp = pTemp->pNext;
//		return pTemp;
//	}
//	Node* operator++(int) {		//��++
//		Node* pT = pTemp;
//		pTemp = pTemp->pNext;
//		return pT;
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
//		if (m_pHead) {
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
//		//Node* pTemp = m_pHead;
//		//	//Node* pTemp = NULL;
//		//	//pTemp = m_pHead;
//		//while (pTemp) {
//		//	cout << pTemp->val << "	";
//		//	pTemp = pTemp->pNext;
//		//}
//
//		CMyIterator ite;
//		ite = m_pHead;
//
//		while (ite != NULL) {
//			cout << *ite << "   ";
//			++ite;	//�˴�����++������++��һ������Ϊû���õ���������ֵ
//					//�����int a = ++ite����int a = ite++��ͬ���ǰѲ�ͬ�ķ���ֵ��ֵ����a����ite��ֵ����+1��
//		}
//		cout << endl;
//	}
//};
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
//	system("pause");
//	return 0;
//}
