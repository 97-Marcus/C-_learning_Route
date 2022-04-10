#include <stdio.h>



//typedef + 类型 + 别名 ；

/*
typedef unsigned int UINT;
typedef int* AA;
typedef int ARR[5];//使用typedef定义别名时，也要符合原来的格式

int main()
{
	UINT a = 10;
	unsigned d = 10;
	printf("%d\n%d\n", a, d);
	int* p,p0;//此时的p是int*类型，p0是int类型
	AA p1,p2;//此时p1和p2都是AA，也就是int*类型

	int arr[5];
	ARR arr1;

	return 0;
}
*/



//const
/*
int main()
{
	const int a = 1;
	//a = 2;//被const修饰的变量会变成常量，不可以再进行修改
	//const int d;//const修饰的变量必须初始化

	int c;
	const int* p1 = &c;//和int const *是一样的 
					   //const在*左边，p可以改（可以改指向谁的地址），*p不可改（不可以改指向的地址上的内容）
	int* const p2 = &c;//const在*右边，p不可以改，*p可以改；
	int const* constp3 = &c;//两边都有const的时候，都不可以改

	return 0;
}
*/




//1.预处理	2.编译	3.汇编	4.链接
//单纯的替换
//#define + 宏的名字 + 要替换的内容


/*
#define AA printf("hello\n")
#define BB int *   //最好不加分号。
				   //如果加了的话 程序中写BB a；来定义变量的时候会错，因为实际上是int；a；
int main()
{
	AA;
	BB a, b;//此时a是int*类型，b是int类型
	return 0;
}
*/

//有参数的宏
/*
#define ADD(a,b)  a + b
#define MUL(a,b)  a * b
#define ARRLEN(a)	sizeof(a)/sizeof(a[0])
int main()
{
	printf("%d\n", ADD(1, 2));
	printf("%d\n", MUL(2+2, 3+3));
		//输出为11的原因是：2+2*3+3=11,宏定义时加上括号即可：#define MUL(a,b)  (a) * (b)
	
	int arr[5];
	printf("%d\n", ARRLEN(arr));
	
	return 0;
}
*/


//位运算
/*
int main()
{
	//与		&	//都是1为1
	//或		|	//有1就为1
	//取反	~	//1和0互变
	//异或	^	//相同为0 不同为1
	//左移	<<	//左移补0
	//右移	>>	//右移补符号位（若为无符号类型，补0）

	
	int a = -1;
	-1 >>5；//-1为1111 1111，所以不管移动几位，最后补完都是1111 1111

	int a = 1;
	int b = 2;
	//交换a与b的内容
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;

	printf("%d\n%d\n", a, b);
	return 0;
}
*/


