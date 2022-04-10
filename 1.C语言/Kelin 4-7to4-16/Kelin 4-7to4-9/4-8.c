#include <stdio.h>


//函数 对步骤的封装
//返回值 + 函数名 +（参数类型）+ ；
//void 无返回值
//返回值只有一个

/*

void printHello();//函数声明
int Add11();
int ADD(int,int);

int main()
{
	printHello();//函数调用
	Add11();
	int c = Add11();
	printf("%d\n", c);

	int d = 2;
	int a = ADD(1, d);//实参//其实是还有一个隐藏的实参给形参赋值的过程：int a=1；int b=d；
	printf("%d\n", a);
	printf("%d\n", ADD(2, Add11()));
	return 0;
}


void printHello() //函数具体实现
{
	printf("Hello!\n");
	return;
	//函数遇到return就结束
	printf("Hi!");
}

int Add11() 
{
	int a = 1;
	int b = 1;
	int c;
	c = a + b;
	return c;
}

int ADD(int a, int b) //形参
{
	return a + b;
}

*/




//数组传参
/*
void PrintARR();
//void PrintARRPro(int arr[]);
void PrintARRPro(int arr[],int len);

int main() 
{
	//PrintARR();
	int arr[] = { 1,2,3,4,5 };
	//PrintARRPro(arr);	
	//传参过程为：int arr[]=arr，现在赋值的是首元素的地址 ，也就是int arr[] = *arr;
	//数组名字在两种情况下才代表数组本身（即该段连续的空间）1.对数组名进行取地址   2.数组名出现在sizeof之后
	//其余数组名表示首元素的地址:比如：函数传参— > int*

		//int array[] = { 1, 2, 3, 4, 5 };

		//int* p1 = array;
		//int* p2 = array + 0;
		//int* p3 = &array[0];

		//printf("%d\n", p1);
		//printf("%d\n", p2);
		//printf("%d\n", p3);	//三个结果都是一样的
	PrintARRPro(arr,sizeof(arr) / sizeof(arr[0]));

	return 0;
}

void PrintARR()
{
	int arr[] = { 1,2,3,4,5,6,7 };
	int i;
	for (i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}

void PrintARRPro(int arr[],int len) 
{
	int i;
	int n;
	n = sizeof(arr) / sizeof(arr[0]);//结果等于1，原因是：arr其实不是数组名，是*arr，指针大小是4，所以4除以4得到1
	//所以数组传参我们要得到数组的长度，所以需要两个参数（首元素的地址＋数组长度）

	for (i = 0; i < len; i++)
	{
		printf("%d\n", arr[i]);
	}
}
*/