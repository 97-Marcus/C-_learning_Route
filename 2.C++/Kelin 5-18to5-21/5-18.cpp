#include<stdio.h>
#include<windows.h>

//C:更注重程序的实现逻辑（过程）
//C++:更注重程序的整体设计（封装、继承、多态），提升了程序的拓展性和复用性

/*拓展性的例子

int Add(int a, int b)
{
	return a + b;
}

double Add(double a, double b)
{
	return a + b;
}

C文件下该代码报错，Cpp文件下没有问题
C文件编译错误原因：Add重定义
处理方法：更改函数名

说明问题：C语言的程序拓展性较差，增加新需求时需要更改原来的代码程序。

拓展性：如果增加新的功能，对原来封装好的功能没有影响，不需要更改原有代码。
*/

/*
复用性：不是针对某一个功能开发，而是针对某一类功能开发。

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
};//封装了一个类

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
//C++兼容 包含C，因此有此同文件时可不写stdio等头文件，不会影响C语言代码的编译

using namespace std;	//打开标准命名空间
 

int main()
{
	int a = 10;
	char b = 'b';
	


	printf("%d %c \n", a, b);

	cout << a << b << endl;		//函数重载
						//cout 类对象，用于输出
						//<< 重载输出的操作符（特殊的函数）
						//ednl 换行



	//scanf("%d %c \n", &a, &b);

	cin >> a >> b;
	cout << a << b << endl;
	cout << (char)a << (int)b << endl;	//强制转换

	system("pause");
	return 0;
}

*/


/*
//命名空间

#include <iostream>	
using namespace std;

namespace AA {	//定义命名空间
	int A = 20;
}

namespace BB {	//定义命名空间
	int A = 30;
}

//命名空间的使用：			①使用命名空间的名字::
//						②打开命名空间 using namespace 命名空间的名字;
//区分同一作用域的相同的变量

int main() 
{
	int A = 10;
	cout << A << endl;
	//cout << ::A << endl;	//::为作用域运算符(取全局的A（打开的命名空间）)
	cout << AA::A << endl;	//::前面可以指定命名空间
	cout << BB::A << endl;

	system("pause");
	return 0;
}
*/
