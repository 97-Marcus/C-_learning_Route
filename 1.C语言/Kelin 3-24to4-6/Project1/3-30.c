#include <stdio.h>


//区分左++和右++，a的值都会发生改变，但他们的返回值不一样。
/*
int main()
{
	int a = 1;
	//printf("%d\n", a++);
	//右++，返回a之前的值
	printf("%d\n", ++a);
	//左++，返回a之后的值
	return 0;
}
*/



//短路求值
/*
int main()
{
	int a = 0;
	int b = 1;

	a++ && b++;//a=1，但是a++返回0，而&&的执行逻辑，如果一个假，后面真假对前者无影响，最终结果均为假，所以后者不执行
	a++ || b++;//a=2，但是a++返回1，而||的执行逻辑，如果一个真，后面真假对前者无影响，最终结果均为真，所以后者不执行

	printf("a=%d\t b=%d\n", a, b);
	return 0;
}
*/



//地址：八个十六进制的数组成
/*
int main()
{
	int a = 1;
	&a;
	//& ＋ 变量名即为取地址操作；
	//取地址取到的是首字节的地址
	printf("%p\n", &a);
	//注意%p
	*&a = 100;
	//间接引用：* + 地址;实际上，*&a == a
	printf("%d\n", a);
	//地址不额外占用空间
	return 0;
}
*/



//指针：存地址的变量
//要指向的类型 + * + 变量名
//如何判断一个变量的类型：去掉变量名，剩下的就是类型
/*
int main()
{
	int a = 1;
	int* p = &a;
	printf("%p\n", &a);
	printf("%p\n", p);
	printf("%d\n", *p);
	//p == &a;*p == *&a == a;

	printf("%d\n", sizeof(p));
	char* pp;
	printf("%d\n", sizeof(pp));
	//指针大小不取决于指向类型的大小，因为指针是存地址的变量，所以大小由地址决定,。地址由八个十六进制数，十六对于二进制是4位，4*8是三十二位，也就是4个字节。
	//32位程序是4个字节，64位是8个字节，指针大小由程序的位数决定。
	return 0;
}
*/



//指针2
/*
int main()
{
	int a = 10;
	int *p = &a;

	char b = 'c';
	char* p1 = &b;
	//char* p2 = &a；
	//弱类型语言（c）可以两端类型不一致，强类型语言（c++和java）必须一致

	//地址偏移
	printf("%p\n", p);
	printf("%p\n", p + 1);
	//向前或向右偏移一个单位（即四个字节）

	printf("%p\n", p1);
	printf("%p\n", p1 + 1);
	//地址偏移的偏移量由指向的类型决定，因此此处为一个字节（char）
	//如何判断一个指针指向的类型：去掉变量名再去掉一个*，剩下的就是指向类型

	return 0;
}
*/