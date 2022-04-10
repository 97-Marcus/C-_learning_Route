#include <stdio.h>


//结构体

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
//typedef为复杂的声明定义简单的别名，结构体的定义形式如上所示，BB为其别名

int main()
{
	struct AA a = { 1,"xin","13532805647" };
	a.name = "bb";
	printf("%d\t%s\t%s\n", a.id, a.name, a.number);
	
	BB* p = &a;//p指的是a的地址，*p指的是a
	p->number = "15367842563";
	printf("%d\t%s\t%s\n", p->id, p->name, p->number);

	//*p.number = "17825345864";
	//.的优先级很高，因此先p.number再*（p.number）
	//这时候的p并非结构体而是结构体指针，因此无法更改number的内容
	(*p).number = "17825345864";
	printf("%d\t%s\t%s\n", (*p).id, (*p).name, (*p).number);

	return 0;
}
*/



//结构体对齐：以最大的基本类型对齐（整体和内部都是）
/*
struct AA
{
	char a;
	short b;
	int c;
};
//    |a1   |b1 b2|
//    |c1 c2|c3 c4|
//上述数字为该类型的第几个字节，2*4=8

struct BB
{
	char a;
	int b;
	short c;
};
//    |a1   |     |
//    |b1 b2 b3 b4|
//    |c1 c2|     |
//上述数字为该类型的第几个字节，3*4=12

int main() 
{
	printf("%d\n", sizeof(struct AA));   //8个字节
	printf("%d\n", sizeof(struct BB));   //12个字节

	return 0;
}
*/

/*
struct DD//    24个字节
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

struct EE//		3个字节
{
	char a;
	char b;
	char c;
};
//    |a1|
//	  |b1|
//    |b3|

struct FF//		12个字节
{
	int a;
	char b[7];
};
//    |a1 a2 a3 a4|
//    |b1|b2|b3|b4|
//    |b5|b6|b7|  |
*/



//链表
#include <stdio.h>


/*
//自己完成一个简易链表
typedef struct Node
{
	int id;
	char* name;
	char* tel;
	struct Node* pNext;//链表中每个成员内除了存放东西以外还需要存放下一个成员的地址
}List;//将structNode这种类型typedef一个别名

int main()
{
	List a = { 1,"佩奇","111",NULL };
	List b = { 2,"苏西","222",NULL };
	List c = { 3,"丹尼","333",NULL };
	List d = { 4,"瑞贝卡","444",NULL };
	List e = { 5,"佩德罗","555",NULL };

	a.pNext = &b;
	b.pNext = &c;
	c.pNext = &d;
	d.pNext = &e;//将每个成员连起来


	//遍历链表
	List* p = &a;
	while (p != NULL)
	{
		printf("%d  %s  %s\n", p->id, p->name, p->tel);
		p = p->pNext;
	}

	return 0;
}
*/