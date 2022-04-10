#include <iostream>
using namespace std;

//struct AA 
//{
//};

////new-detele
//int main()
//{
//
//	/*
//
//	// C语言中的malloc动态申请空间，是在堆区申请的空间，返回是*void，需要别的类型的话用强制转换
//	int* p1 = (int*)malloc(sizeof(int));
//	*p1 = 10;
//	cout << *p1 << endl;
//
//	free(p1);
//	p1 = NULL;
//
//	// C++中的new，也是在堆区申请的空间，new用什么类型则返回什么类型的指针
//	int* p2 = new int;
//	*p2 = 20;
//	cout << *p2 << endl;
//
//	delete p2;
//	p2 = NULL;
//
//	//new数组时
//	int i = 0;
//	int* p1 = new int[4];	//返回的是数组首元素的地址而不是整个数组的地址
//	for (i = 0; i < 4; i++)
//	{
//		p1[i] = i;
//	}
//
//	for (i = 0; i < 4; i++)
//	{
//		cout << p1[i] << endl;
//	}
//
//	delete []p1;	//删除数组时要加上[]
//
//	*/
//
//	/*
//
//	//练习：
//	//	1. new 整形指针
//		int* (*p1) = new int*;
//	//	2. new 整形指针 数组
//		int* (*p2) = new int* [4];
//	//	3. new 整形数组指针
//		int(*(*p3))[4] = new (int(*)[4]);
//		//解析例子
//		//int arr[4] = { 0,1,2,3 };
//		//int(*p4)[4] = &arr;
//		//p3 = &p4;
//
//		//cout << (*(*p3))[0] << endl;
//		//cout << (*(*p3))[1] << endl;
//		//cout << (*(*p3))[2] << endl;
//		//cout << (*(*p3))[3] << endl;
//
//	//	4. new 二维数组
//		int(*p5)[2] = new int[4][2];
//	//	5. new 结构体
//		AA* p6 = new AA;
//
//	*/
//
//
//
//	/*
//	
//	int a = 10;
//	cout << a << endl;
//
//	int b = 20;
//	cout << b << endl;
//
//	//int i = 0;
//	for (int i = 0; i < 10; i++)//局部的变量i，只在该for循环内有效
//	{
//		cout << i << endl;
//	}
//
//	int arr[4] = { 0,1,2,3 };
//	for (int i = 0; i < 4; i++)	//局部的变量i，只在该for循环内有效
//	{
//		cout << arr[i] << endl;
//	}
//
//	for (int val : arr) //for 循环的优化
//	{ 
//		cout << val << endl;
//	}
//
//
//	/*
//	
//	BOOL b = TRUE;  //别名：typedef int TRUE/FALSE 
//					//宏 #define TRUE  1
//	cout << sizeof(b) << endl;//4个字节(int类型)
//
//	bool c = true;  //bool true false 均为关键字
//	cout << sizeof(c) << endl;//1个字节
//
//	*/
//
//	system("pause");
//	return 0;
//}



////string函数
//
//#include<iostream>
//#include<string>
//using namespace std;
//
//void show(const char* p) 
//{
//	cout << p << endl;
//}
//
//int main() {
//
//	/*
//	//字符串的两种初始化方法
//	char szChar[10] = "123123123";
//	char* pChar = "123123123";
//
//	//szChar = "asdasdasd";
//	//szChar实际上指的是字符串的地址，不能够直接对地址进行赋值，可以利用字符串复制函数（安全的）
//	strcpy_s(szChar, 10, "asdasdads");
//	pChar = "asdasdasd";
//	//pChar指向了一个新的字符串而非原来的
//
//	//new 字符数组
//	char* p2 = new char[10];
//	//p2 = "asdasdasd";
//	//语法上无错误，但是程序在delete new的p2时会崩溃
//	//指向了一个新的字符串而不是刚刚申请的字符数组，删除时也是删除的新的字符串而不是申请时的字符数组
//	strcpy_s(p2, 10, "asdasdads");
//
//	delete []p2;
//	*/
//
//	//cout<<szChar<<"     "<<pChar<<endl;
//
//
//	
//	
//	string str = "asdasd";
//	cout << str << endl;
//
//	//string str;
//
//	str = "123123";		//可以直接修改
//	cout << str << endl;
//
//	string str2 = str;	//可以直接使用
//	cout << str2 << endl;
//
//	string str3 = str2 + "00000" + str;		//可以利用加号进行拼接
//	cout << str3 << endl;
//	str3 = str2 + "00000" + str;			//修改时也可以进行拼接
//	cout << str3 << endl;
//	str3 += "11111";
//	cout << str3 << endl;
//
//	string str4 = str3.substr(2, 6);
//	cout << str4 << endl;
//	//字符串的截取(从2开始截取6个字符)	  
//	//substr函数的两个参数（下标，截取数量）
//
//	//string str4;
//	//str4.c_str();
//
//	show(str4.c_str());  //将str4转换成const char *
//
//	
//
//
//	/*
//	
//	//C++中可以直接用str1==str2对字符串内容进行判断但C语言不行（C中判断是地址而不是字符串内容）
//	string str1 = "123";
//	string str2 = "456";
//	string str3 = "456";
//
//	if (str1 == str2) {
//		cout << "str1 == str2" << endl;
//	}
//	else {
//		cout << "str1 != str2" << endl;
//
//	}
//	if (str3 == str2) {
//		cout << "str3 == str2" << endl;
//	}
//	else {
//		cout << "str3 != str2" << endl;
//
//	}
//	*/
//
//	system("pause");
//		return 0;
//}

//
//#include <iostream>
//using namespace std;
//
////函数的默认值，必须从右向左依次指定，不能间断
//
////声明:声明和定义分开时，函数的默认值只在声明中写，不要在定义中写，如果不分开的话直接写就行
//void show(int a, int c = 10, int b = 20);
//
////定义
//void show(int a, int c, int b) {
//	cout << a << endl;
//}
//
////定义和声明需要分开的情况
//void show();
//void play() 
//{
//	show();
//}
//
//void show() 
//{
//	play();
//}
//
////函数重载：在相同的作用域之下，函数名相同，参数列表不同（参数的类型及其个数）
//
//int Add(int a, int b) 
//{
//	return a + b;
//}
//
//int Add(int a, int b, int c) 
//{
//	return a + b + c;
//}
//
//namespace AA 
//{
//	double Add(double a, double b) //和上述两个Add不在同一作用域
//	{
//		return a + b;
//	}
//}
//
//int main() {
//
//	show(2, 30, 40);
//
//	system("pause");
//	return 0;
//}