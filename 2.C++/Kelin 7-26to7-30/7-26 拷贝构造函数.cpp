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
//
//	CTest() {
//		m_a = 10;
//		m_p = new int(20);
//	}
//
//	CTest(int a) {
//		m_a = a;
//	}
//
//	//	�����б��������ṩһ��Ĭ�ϵ�����Ĺ��캯�����������캯��
//	//	�������캯�� ������ ��ǰ���� ����const ��ǰ�������
//	// 	�������캯�����õ�ǰ���һ���������һ�������ʼ����ʱ��ʱ������
//	//	�����ж����this�����Ա���γ�ʼ��
//	
//	//	CTest(const CTest& tst) {
//	//		this->m_a = tst.m_a;
//	//	}
//
//
//	~CTest() {
//		if (m_p) {
//			delete m_p;
//			m_p = NULL;
//		}
//		//	Ĭ�Ͽ������캯�����������⣺ǳ��������
//		//	ǳ������������㣺
//		//	1.������г�Ա����ָ�������new����ռ䣬���ÿ������캯����ʱ����ֵ��������ַ�������Ĺ��̣�������������տռ�ʱ��ͬһ����ַ�ռ�ᱻdelete��Σ����³��������
//	}
//
//};
//
//
//int main() {
//
//	//CTest tst(10);
//	//CTest tst1(tst);
//	//cout << tst1.m_a << endl;
//
//	CTest tst;
//	CTest tst1(tst);
//
//	*tst1.m_p = 50;
//	cout << *tst.m_p << endl;	
//					//2.�������ָ��ָ��ͬһ���ռ䣬��һ�������޸������ֵ����������ʹ�ú��ֵ���޸ĺ�ġ�
//					//���ʵ��ȷʵ��Ҫ���������Ҳ������ʹ�ø÷�ʽ������ʹ��static��̬��Ա����
//
//	system("pause");
//	return 0;
//}


////���ǳ�������⣺���
//
//
//#include <iostream>
//using namespace std;
//
//class CTest
//{
//public:
//	int m_a;
//	int* m_p;
//public:
//	CTest() {
//		m_a = 10;
//		m_p = new int(20);
//	}
//	CTest(int a) {
//		m_a = 20;
//		m_p = NULL;
//	}
//	CTest(const CTest& tst) {
//		this->m_a = tst.m_a;
//		if (tst.m_p)
//		{
//			this->m_p = new int(*tst.m_p);
//		}	//���������m_p��new�Ĳ�ͬ��ַ�����ֵ��һ����
//		else {
//			this->m_p = NULL;
//		}
//	}
//	~CTest() {
//		if (m_p) {
//			delete m_p;
//			m_p = NULL;
//	}
//
//};
//
//
//int main() {
//
//	CTest tst1;
//	CTest tst2(tst1);
//
//	CTest tst3(10);
//	CTest tst4(tst3);
//
//	system("pause");
//	return 0;
//}