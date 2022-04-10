#include <stdio.h>




//值传递：如果不需要修改实参，只需要将其传递进某个函数中，那么可以选用值传递
//地址传递：如果需要通过函数去修改main中的实参，那么选择地址传递
//注意：不是函数参数中出现指针就是地址传递，因为有可能实参就是一个指针，直接把指针的值传进来也是值传递

/*

void change(int *a, int *b);

int main()
{
	int a = 1;
	int b = 2;

	change(&a, &b);

	return 0;
}

//void change(int a,int b)
//main中的ab和change中的ab不一样，main中的ab将其数值赋给了change中ab，change中ab进行交换后，main中的ab没有变化
//解决方法：变量名一样但实际不一样，没法交换ab内容，但地址是唯一的，可以通过地址进行内容的交换

void change(int *a,int *b) 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

*/



//函数练习题
//1.编写一个函数，功能为返回两个int类型参数的最大值
//2.编写一个函数，返回一个数和另一个数之间所有整数相加的和
//3.编写一个函数，返回一个int数组中最大的元素的值
//4.编写一个函数，返回double数组中最大元素的下标
//5.编写一个函数，返回double数组中最大元素的数值和下标


/*
int T1(int a, int b);
int T2(int a, int b);
int T3(int len , int arr[]);
int T4(int len, double arr[]);
int T5(int len, double arr[],double *p);

int main()
{
	//printf("%d\n", T1(11, 2));
	//printf("%d\n", T2(1, 10));

	//int arr[] = { 1,5,4,1,8 };
	//printf("%d\n", T3(sizeof(arr) / sizeof(arr[0]), arr));
	
	double arr1[] = { 1.23,4.34,3.78,2.01 };
	double a;
	printf("%f\n%d\n", a, T5(sizeof(arr1) / sizeof(arr1[0]), arr1,&a));
	//不可以先输出下标再输出数值，原因需要学习到栈才可以解释
	return 0;
}


int T1(int a, int b)
{
	if (a > b)
	{
		return b;
	}
}

int T2(int a, int b) 
{
	int i;
	int sum = 0;
	for (i = a; i <= b; i++)
	{
		sum += i;
		//即sum = sum + i
	}
	return sum;
}

int T3(int len, int arr[])
{
	int i;
	int max = arr[0];
	for (i=0;i<=len;i++)
	{
		if (max < arr[i]) 
		{
			max = arr[i];
		}
	}
	return max;
}


int T4(int len, double arr[])
{
	int i;
	double max = arr[0];
	int index = 0;

	for (i = 0; i <= len; i++)  
	{
		if (max < arr[i])
		{
			max = arr[i];
			index = i;
		}
	}
	return index;
}


int T5(int len, double arr[], double* p) 
//因为返回值只可以有一个，所以需要修改多个实参时，可以通过地址来传递内容~
{
	int i;
	*p = arr[0];
	int index = 0;

	for (i = 0; i <= len; i++)
	{
		if (*p < arr[i])
		{
			*p = arr[i];
			index = i;
		}
	}
	return index;
}

*/



//函数指针(具体查阅OneNote~)
/*
void AA();//AA是void（）类型的
int add(int a, int b);

//typedef int(*) (int, int) PFUN;//写法错位，类比数组，也要按照格式写
typedef int(*PFUN)(int, int);

int main() 
{
	//void* pfun() = &AA;//void * 是泛型，没有类型的地址，本条式子不成立的原因是，左边不是指针而是函数
	void(*pfun) = &AA;
	
	AA();
	//&AA();//取的是函数返回值的地址，应该先取地址，再和括号结合；
	(&AA)();

	//int(*pfun1)(int a, int b) = &add;	//一般说类型不带名字，所以ab是要删掉的，但是不影响程序编译结果
	//int(*pfun1)(int , int ) = &add;	//太麻烦，可以使用typedef进行改善
	PFUN pfun1 = &add;
	printf("%d\n", pfun1(1, 2));
	return 0;
}

void AA()
{
	printf("AA\n");
}

int add(int a, int b) 
{
	return a + b;
}
*/

/*typedef void (*pfun)(void)
概念理解：
typedef 只对已有的类型进行别名定义，不产生新的类型；
#define 只是在预处理过程对代码进行简单的替换。
清晰了解两个概念后，发现它们就是两个不同的概念，并没有太多的联系。

类比理解：
typedef  unsigned int  UINT32;  // UINT32 类型是unsigned int
UINT32 sum;                     // 定义一个变量：int sum;
typedef  int  arr[3];           // arr 类型是 int[3];（存放int型数据的数组）
arr a;							// 定义一个数组：int a[3];

同理：
typedef  void (*pfun)(void);    // pfun 类型是 void(*)(void)
pfun main;                      // 定义一个函数：void (*main)(void);
*/