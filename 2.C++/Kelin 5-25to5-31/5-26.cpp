//#include <iostream>
//using namespace std;

//
//class CTest {
//public:
//	const int m_a;
//	int m_b;
//	//��ʼ�������б������ĳ�ʼ��
//	CTest() :m_a(10), m_b(30) {
//		//m_a = 10;	
//		//���� �˴�Ϊ��ֵ ���ǳ�ʼ�� ��const������ǳ��� ���Բ��ǿ����޸ĵ���ֵ
//		//m_b = 20;//��ͨ��������������ʼ����Ҳ����ͨ����ʼ�������б���������ĳ�ʼ������ô�˴�Ҳ���Ե����Ǹ�ֵ
//	}//�޲����
//
//	//�вεĳ�ʼ�������б�
//	//��ʼ�������б�ĳ�ʼ��˳�򣺲�����д�ڲ����б��е�˳�򣬶��Ǳ��������ж����˳��Ҳ����m_a,m_b
//	//
//
//	//CTest(int a) :m_a(m_b), m_b(a) {	//m_aû�г�ʼ��
//	//	//��m_bȥ��ʼ��m_a,��m_b�Ķ�����m_a������޷���ɸó�ʼ��
//	//}
//
//	//CTest(int a) :m_a(a), m_b(m_a) {
//
//	//}
//
//	//const int show() {//����ֵΪ������const int��
//	//	
//	//}
//
//	void play(/*CTest* const this*/) {
//	
//	}
//
//	//const��Ա����������Ա����):ע��constҪ���ڲ����б����
//	//�������п���ʹ�� �������޸�
//	int show (/* const CTest* const this */)const {
//		//const���ε���thisָ�룬��ͨ������thisָ��ΪCTest* const this������������Ϊconst CTest* const this
//		cout << m_a << endl;
//		cout << m_b << endl;
//
//		//m_a = 20;
//		//m_b = 20;
//		//ͨ������������з��ʣ�����޷��޸�
//
//		return 0;
//	}
//};
//
//int main() {
//
//	//CTest tst(20);
//	//cout << tst.m_a << endl;
//	//cout << tst.m_b << endl;
//
//	CTest tst;
//	tst.show();//��ͨ������Ե�����ͨ�����ͳ�����
//
//	//const CTest* const pp = &tst;	//ָ��İ�ȫ���������������������
//	//pp->m_a = 10;	//m_a�޷��޸ģ���Ϊppָ�뱻const�����ˣ�Ҳ���ǳ�����������const CTest* const this
//
//	const CTest tst1;//��������ֻ�ܵ��ó������������Ե�����ͨ����
//	tst1.show();
//
//	//tst1.play();		//�����޷�����
//	//CTest* const p2 = &tst1;		//����Ϊָ��İ�ȫ���𽵼����������ǲ��������
//
//	system("pause");
//	return 0;
//}
//
//