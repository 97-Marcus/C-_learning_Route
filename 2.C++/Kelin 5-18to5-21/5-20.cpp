#include<iostream>
#include<string>
using namespace std;

/*

//const

int main() {
	
	int a = 10;
	a = 20;
	int* p = &a;

	const int b = 20;
	//b = 10;//�ᱨ��bΪ������һ������ͱ����ʼ����֮���޷��ٽ����޸�
	//int* p2 = &b;//const int���͵�ֵ�������ڳ�ʼ��int���͵�ʵ��
	const int* p2 = &b;//const:����ͨ��ָ��ȥ�޸�ָ��Ŀռ����ֵ
	p2 = &a;//������ָ���Ŀռ�
	const int* p3 = &a;
	//*p3 = 4;//const:����ͨ��ָ��ȥ�޸�ָ��Ŀռ����ֵ

	int* const p5 = &a;//p5һ������ͱ����ʼ����֮���޷��ٽ����޸�
	//p5 = &b;//һ��������ָ����һ������Ŀռ䣬�Ͳ�����ָ�������Ŀռ�

	system("pause");
	return 0;
}

*/



//����

/*

int main() {

	int a = 10;
	int& b = a;  //�������ã�b�����֣����õ�������Ҫ�ͱ����õ�һ��

	cout << b << endl;

	a = 12;

	cout << a << endl;
	cout << b << endl;

	//int& c;  //��������ʱ�����ʼ��

	system("pause");
	return 0;
}

*/

/*
1.����ָ�����NULL�������ò�����ΪNULL������ʱ�����ʼ��
2.�пյ�ָ�룬����û�пյ�����
3.ָ��ռ�ÿռ䣬���ò�ռ�ö���Ŀռ�
*/



//���ִ���

/*

//ֵ����
void show(int a) 
{
	cout << a << endl;
}

//��ַ����
void show(int* p) 
{
	cout << *p << endl;
}

//���ô���
void play(int& b) 
{
	 cout << b << endl;
	 b = 12;
}

int main(){

	int a = 10;
	show(a);	//ֵ����
	show(&a);	//��ַ����
	play(a);	//���ô���
	cout << a << endl;

	system("pause");
	return 0;
}

*/

//����

/*

struct Node {
	int val;
	Node* pNext;
};

//void PushBack(Node** pH, Node** pE, int v)  
//{  
//	Node* pNode = new Node;
//	pNode->val = v;
//	pNode->pNext = NULL;
//
//	if (*pH)		 //����Ϊ��
//	{
//		(*pE)->pNext = pNode;
//		(*pE) = pNode;
//	} 
//	else		     //����Ϊ��
//	{
//		(*pH) = pNode;
//		(*pE) = pNode;
//	}

		//shift+Alt ������ѡ��

//}

void PushBack(Node*& pH, Node*& pE, int v)
{
	Node* pNode = new Node;
	pNode->val = v;
	pNode->pNext = NULL;

	if (pH)		 //����Ϊ��
	{
		(pE)->pNext = pNode;
		(pE) = pNode;
	} 
	else		     //����Ϊ��
	{
		(pH) = pNode;
		(pE) = pNode;
	}
}

void Show(Node* pH) 
{
	if (pH)
	{
		while (pH) 
		{
			cout << pH->val << endl;
			pH = pH->pNext;
		}
	}
}

int main() 
{
	Node* pHead = NULL;
	Node* pEnd = NULL;

	//PushBack(&pHead, &pEnd, 1);
	//PushBack(&pHead, &pEnd, 2);
	//PushBack(&pHead, &pEnd, 3);
	//PushBack(&pHead, &pEnd, 4);

	PushBack(pHead, pEnd, 1);
	PushBack(pHead, pEnd, 2);
	PushBack(pHead, pEnd, 3);
	PushBack(pHead, pEnd, 4);

	Show(pHead);

	system("pause");
	return 0;
}

*/


/*
C ���ݺ��㷨 �����Բ�ǿ
C++ �����ĳһ���ܵ����� �㷨 ��װ�����γ�һ���� ������ǿ

�ࣺ���ݺ��㷨�ļ��ϣ��ǳ����(���Ǿ���ģ���ռ���ڴ�ռ䣬ֻ�Ǳ�����һ����)
���󣺶���һ�����ʵ�������������Ǿ���ģ�ռ���ڴ�ռ䣩
*/



//��ĳ�Ա����
//
//class CPeople{  //��Ķ���  ����һ����C��ͷ
//	int m_nAge;		//��Ա����һ����m_��ͷ
//	bool m_bSex; 
//	string m_strName;
//
//	void show() {	//��Ա�����п���ֱ��ʹ����������
//		cout << m_strName << endl;
//		cout << m_bSex << endl;
//		cout << m_nAge << endl;
//	}
//};
//
//
//int main() {
//
//	//CPeople people;	//�������
//	//people.m_nAge = 10;
//	//people.m_bSex = true;
//	//people.m_strName = "С��";
//
//	//�����޷����ʣ������Ҫ�������η�
//
//	system("pause");
//	return 0;
//}
//
//
//�����дstring��ͷ�ļ�,�����������õ�stringʱ���ᱨ��,��Ϊstring��Ϊ�ؼ����Ǵ����ڱ������е�,����������õ���stringͷ�ļ��ĺ���,�ͻᱨ��
//class CPeople{  
//	string m_strName;	//����stringͷ�ļ�������
//
//	void show() {	
//		cout << m_strName << endl;	//����stringͷ�ļ��ᱨ��
//	}
//};



////��ķ������η�
//
///*
//�������η���
//public:������,�������ⶼ������
//protected:������,���ڿ���,����Ҳ����
//private:˽�е�,ֻ��������ʹ��
//*/
//
//class CPeople {  //��Ķ���  ����һ����C��ͷ
//private:
//	int m_nAge;		//��Ա����һ����m_��ͷ
//protected:
//	bool m_bSex;
//public:
//	string m_strName;
//	void show() {	//��Ա�����п���ֱ��ʹ����������
//		cout << m_strName << endl;
//		cout << m_bSex << endl;
//		cout << m_nAge << endl;
//	}
//};
//
//
//int main() {
//
//	//CPeople people;	//�������  ��ı����ͺ���������ͨ����������
//	////people.m_nAge = 10;
//	////people.m_bSex = true;
//	//people.m_strName = "С��";
//	//people.show();
//
//	//����������һ�ַ�ʽ
//	CPeople* pPeo = new CPeople;
//	pPeo->m_strName = "С��";
//	pPeo->show();
//
//	system("pause");
//	return 0;
//}