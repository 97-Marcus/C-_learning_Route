#include<stdio.h>
#include<windows.h>

//C:��ע�س����ʵ���߼������̣�
//C++:��ע�س����������ƣ���װ���̳С���̬���������˳������չ�Ժ͸�����

/*��չ�Ե�����

int Add(int a, int b)
{
	return a + b;
}

double Add(double a, double b)
{
	return a + b;
}

C�ļ��¸ô��뱨��Cpp�ļ���û������
C�ļ��������ԭ��Add�ض���
�����������ĺ�����

˵�����⣺C���Եĳ�����չ�Խϲ����������ʱ��Ҫ����ԭ���Ĵ������

��չ�ԣ���������µĹ��ܣ���ԭ����װ�õĹ���û��Ӱ�죬����Ҫ����ԭ�д��롣
*/

/*
�����ԣ��������ĳһ�����ܿ������������ĳһ�๦�ܿ�����

class CAdd {
public:
	int Add(int a, int b)
	{
		return a + b;
	}

	double Add(double a, double b)
	{
		return a + b;
	}
};//��װ��һ����

int main() 
{
	int a = 10;
	int b = 10;
	int c = 10;
	int d = 10;

	CAdd add;
	add.Add(a, b);
	add.Add(c, d);

	return 0;
}
*/


/*

#include <iostream>		
//C++���� ����C������д�ͬ�ļ�ʱ�ɲ�дstdio��ͷ�ļ�������Ӱ��C���Դ���ı���

using namespace std;	//�򿪱�׼�����ռ�
 

int main()
{
	int a = 10;
	char b = 'b';
	


	printf("%d %c \n", a, b);

	cout << a << b << endl;		//��������
						//cout ������������
						//<< ��������Ĳ�����������ĺ�����
						//ednl ����



	//scanf("%d %c \n", &a, &b);

	cin >> a >> b;
	cout << a << b << endl;
	cout << (char)a << (int)b << endl;	//ǿ��ת��

	system("pause");
	return 0;
}

*/


/*
//�����ռ�

#include <iostream>	
using namespace std;

namespace AA {	//���������ռ�
	int A = 20;
}

namespace BB {	//���������ռ�
	int A = 30;
}

//�����ռ��ʹ�ã�			��ʹ�������ռ������::
//						�ڴ������ռ� using namespace �����ռ������;
//����ͬһ���������ͬ�ı���

int main() 
{
	int A = 10;
	cout << A << endl;
	//cout << ::A << endl;	//::Ϊ�����������(ȡȫ�ֵ�A���򿪵������ռ䣩)
	cout << AA::A << endl;	//::ǰ�����ָ�������ռ�
	cout << BB::A << endl;

	system("pause");
	return 0;
}
*/
