//#include <iostream>
//using namespace std;
//
//class CTest
//{
//public:
//	int m_a;
//	int* m_p;
//
//public:
//	CTest() {
//		m_a = 10;
//		m_p = NULL;
//	}
//	CTest(int a) {
//		m_a = a;
//		m_p = new int(30);
//	}
//
//	int operator=(int a) {
//		m_a = a;
//		return m_a;
//	}
//
//	//	�������ṩ��Ĭ�ϵ����صȺŲ����� operator= 
//	//	����Ϊconst CTest& tst ����ֵΪconst CTest&
//	/*const CTest& operator=(const CTest& tst) {
//		this->m_a = tst.m_a;
//		return *this;
//	}*/
//	//	��ǰ���һ���������һ������ֵ��ʱ����е���
//	//	�����ж����this�����Ա���θ�ֵ
//	//	Ҳ����ǳ�������⣬��������������
//
//	const CTest& operator=(const CTest& tst) {
//		this->m_a = tst.m_a;
//		if (tst.m_p)	
//		{
//			if (this->m_p) //this->m_p��һ���пռ����Ի�Ҫ���ж�
//			{
//				*this->m_p = *tst.m_p;
//			}
//			else {
//				this->m_p = new int(*tst.m_p);
//			}
//		}
//		else {
//			if (this->m_p)
//			{
//				delete this->m_p;
//				this->m_p = NULL;
//				//��ʵtst.m_pû�пռ�Ҳ��NULL������дthis->m_p = tst.m_pҲ����~
//			}
//			else {
//				this->m_p = tst.m_p;//����û�пռ� �����ǿ�
//			}
//		}
//		return *this;
//	}
//
//	~CTest() {
//		if (m_p) 
//		{
//			delete m_p;
//			m_p = NULL;
//		}
//	}
//};
//
//int main() {
//	//CTest tst1;
//	//CTest tst2;
//	//tst2 = tst1 = 10;
//
//	//CTest tst;
//	//CTest tst3;
//	//CTest tst4;
//	//tst4 = tst3 = tst;
//
//	CTest tst1;
//	CTest tst2;		//������Ĭ���޲εĹ��죬��m_p���ǿգ��ߵ���this->m_p = tst.m_p;
//	tst1 = tst2;
//
//	CTest tst3(20);
//	tst2 = tst3;	//�вεĸ��޲εģ��ߵ���this->m_p = new int(*tst.m_p);
//
//	CTest tst4(40);
//	tst4 = tst3;	//���пռ䣬�ߵ���*this->m_p = *tst.m_p;
//
//	CTest tst5;
//	tst5 = tst4;	//�޿ռ�ĸ��пռ�ĸ�ֵ���ߵ���delete this->m_p;this->m_p = NULL;
//
//	system("pause");
//	return 0;
//}
//
////������Ĭ�ϵĺ�����4����
////1.Ĭ���޲ι��캯��
////2.Ĭ����������
////3.Ĭ�Ͽ������캯��
////4.Ĭ��operator=�����صȺŲ�������