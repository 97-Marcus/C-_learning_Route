#include <iostream>
using namespace std;

/*

//	��̬:	��ͬ����Ϊ��ʽ�����˲�ͬ����Ϊ�������Ϊ��̬�ԡ��ڳ����ϣ�Ҳ����ͬһ�����չ���˶��ֲ�ͬ�ı�����̬��
//			����ָ�����ָ���κμ̳��ڸ�������࣬�Ҿ����������Ϊ��ʽ������������ж�����̬���ɸ���ָ�����ͳһ��������ָ����ж�����̬��

//��̬������������1. �����м̳й�ϵ���ڣ����ࡢ���ࣩ��2. �����ָ��ָ������Ķ���3. ���������д������麯��

//��д�������д��ں͸��ຯ��һģһ���������� �����б� ����ֵ ����ͬ�����麯��

class CFather
{
public:
	//void show() {
	//	cout << "void show()" << endl;
	//}

	virtual void show() {//	virtual���麯���Ĺؼ���
		cout << "void show()" << endl;
	}
protected:
private:
};

//class CSon1 :CFather	//Ĭ�ϼ̳���˽�е�
class CSon1 :public CFather
{
public:
	void show() {
		cout << "CSon1 show()" << endl;
	}
protected:
private:
};

class CSon2 :public CFather
{
public:
	void show(int a) {	//����Ͳ���������д ������б�͸��಻һ��
		cout << "CSon2 show()" << endl;
	}
protected:
private:
};

int main() {

	CFather* pFather = new CSon1;
	pFather->show();

	CFather* pFather1 = new CSon2;
	pFather1->show();

	system("pause");
	return 0;
}

*/



//
////��̬ԭ��
//
//
//class CTest {
//public:
//	int m_a;
//	int m_b;
//public:
//	CTest() {
//		cout << "CTest" << endl;
//
//	}
//public:
//	virtual void show() {
//		cout << "void show()" << endl;
//	}
//	virtual void play() {
//		cout << "void play()" << endl;
//	}
//	void code() {
//		cout << "void code()" << endl;
//	}
//};
//
////	һ�����е��麯����һ���麯���б���й������麯���б�Ϊһ�����飬�����ÿ��Ԫ����һ������ָ�룬����ָ��ָ���麯�����麯��ָ�뽫�ڹ����ʼ���б��н��г�ʼ����ָ���麯���б��麯��ָ�������ڶ���ģ�ֻ�ж�������˲Ż���ڡ�
////	�ڵ����麯��ʱ����Ҫʹ���麯��ָ�루ָ���麯���б��������麯���б����в��Ҷ�Ӧ�ĺ���ָ�룬Ȼ���ú���ָ��ȥ���þ�����麯����
////	�麯���б������࣬�����ڱ����
////	__vfptr  �麯��ָ��; vftable	�麯���б�
//
//int main() {
//
//	cout << sizeof(CTest) << endl;
//	//�����С���Ϊռλ1��������1���麯�������4����2���麯��Ҳ���4����2���麯����1�������������������Ȼ��С���Ϊ4
//	//˵������ͨ������Ӱ����Ĵ�С�����д���1�������麯��ʱ���������ʱ����Ŀռ佫���4���ֽڡ�
//
//	/*CTest tst1;
//
//	tst1.play();
//	tst1.code();*/
//
//	CTest* pTst = NULL;	//����ָ��
//	pTst->code();	//ֱ��ͨ����ָ�������ͨ����
//	//pTst->play();	//�þ��޷�����ͨ�� ��Ϊû�ж�����û���麯��ָ�� �޷�ͨ������ָ������麯��
//					
//					//���������޸ģ�
//	CTest tst2;
//	CTest* pTst1 = &tst2;
//	pTst1->play();
//
//	cout << sizeof(CTest) << endl;
//
//	CTest tst;
//	cout << &tst << endl;	
//	cout << &tst.m_a << endl;	//�׵�ַ��m_a�ĵ�ַ��4��ʵ���Ͼ����麯��ָ��Ĵ�С���麯��ָ���ڶ������Ŀռ��ǰ4���ֽڣ�	
//	cout << &tst.m_b << endl;
//
//
//	system("pause");
//	return 0;
//}
