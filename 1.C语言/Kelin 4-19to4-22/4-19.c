#include <stdio.h>


//�ṹ��

//struct AA 
//{
//	int id;
//	char* name;
//	char* number;
//};

/*
typedef struct AA
{
	int id;
	char* name;
	char* number;
}BB;
//typedefΪ���ӵ���������򵥵ı������ṹ��Ķ�����ʽ������ʾ��BBΪ�����

int main()
{
	struct AA a = { 1,"xin","13532805647" };
	a.name = "bb";
	printf("%d\t%s\t%s\n", a.id, a.name, a.number);
	
	BB* p = &a;//pָ����a�ĵ�ַ��*pָ����a
	p->number = "15367842563";
	printf("%d\t%s\t%s\n", p->id, p->name, p->number);

	//*p.number = "17825345864";
	//.�����ȼ��ܸߣ������p.number��*��p.number��
	//��ʱ���p���ǽṹ����ǽṹ��ָ�룬����޷�����number������
	(*p).number = "17825345864";
	printf("%d\t%s\t%s\n", (*p).id, (*p).name, (*p).number);

	return 0;
}
*/



//�ṹ����룺�����Ļ������Ͷ��루������ڲ����ǣ�
/*
struct AA
{
	char a;
	short b;
	int c;
};
//    |a1   |b1 b2|
//    |c1 c2|c3 c4|
//��������Ϊ�����͵ĵڼ����ֽڣ�2*4=8

struct BB
{
	char a;
	int b;
	short c;
};
//    |a1   |     |
//    |b1 b2 b3 b4|
//    |c1 c2|     |
//��������Ϊ�����͵ĵڼ����ֽڣ�3*4=12

int main() 
{
	printf("%d\n", sizeof(struct AA));   //8���ֽ�
	printf("%d\n", sizeof(struct BB));   //12���ֽ�

	return 0;
}
*/

/*
struct DD//    24���ֽ�
{
	char a;
	short* b;
	double c;
	float d;
	short e;
	char f;
};
//    |a1         |b1 b2 b3 b4|
//    |c1 c2 c3 c4 c5 c6 c7 c8|
//    |d1 d2 d3 d4|e1 e2|f1   |

struct EE//		3���ֽ�
{
	char a;
	char b;
	char c;
};
//    |a1|
//	  |b1|
//    |b3|

struct FF//		12���ֽ�
{
	int a;
	char b[7];
};
//    |a1 a2 a3 a4|
//    |b1|b2|b3|b4|
//    |b5|b6|b7|  |
*/



//����
#include <stdio.h>


/*
//�Լ����һ����������
typedef struct Node
{
	int id;
	char* name;
	char* tel;
	struct Node* pNext;//������ÿ����Ա�ڳ��˴�Ŷ������⻹��Ҫ�����һ����Ա�ĵ�ַ
}List;//��structNode��������typedefһ������

int main()
{
	List a = { 1,"����","111",NULL };
	List b = { 2,"����","222",NULL };
	List c = { 3,"����","333",NULL };
	List d = { 4,"�𱴿�","444",NULL };
	List e = { 5,"�����","555",NULL };

	a.pNext = &b;
	b.pNext = &c;
	c.pNext = &d;
	d.pNext = &e;//��ÿ����Ա������


	//��������
	List* p = &a;
	while (p != NULL)
	{
		printf("%d  %s  %s\n", p->id, p->name, p->tel);
		p = p->pNext;
	}

	return 0;
}
*/