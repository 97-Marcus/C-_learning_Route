#include "4-28head.h"	//用双引号
						//如果自定义头文件和系统重名，那么使用<>时优先引用系统的，使用""时优先应用自定义的



//枚举 定义常量的一种方式 也算是整型
//
//enum AA {JIANZI,SHITOU,BU};//0,1,2
//enum BB {J,S=100,B};//0,100,101
//
//int main()
//{
//	enum AA a = JIANZI;
//	//eunm BB b = 0;
//	//虽然J=0，但实际上J是BB类型的，0是int类型的，所以这句代码有问题
//	
//	switch (a)
//	{
//	case JIANZI:
//		printf("剪子\n");
//		break;
//	case SHITOU:
//		printf("石头\n");
//		break;	
//	case BU:
//		printf("布\n");
//		break;
//	default:
//		break;
//	}
//
//	return 0;
//}
//



//联合体

//union AA 
//{
//	char a;
//	int b;
//	short c;
//};
////所有成员共享一个空间，所以类型最大的就是该联合体的size
//
//int main() 
//{
//	union AA a;
//	printf("%d\n", sizeof(a));
//
//	//a.a = 1;
//	//如果是这个情况的话后面输出只有a是1，另外两条是乱码
//	//char只有一个字节，所以int的其他三个字节没有被赋值，还是乱码
//	a.b = 1;
//	//后面输出的均为1，原因是int的四个字节都已经赋值了
//	printf("%d\n", a.a);
//	printf("%d\n", a.b);
//	printf("%d\n", a.c);
//
//	printf("%p\n", &a.a);
//	printf("%p\n", &a.b);	
//	printf("%p\n", &a.c);
//
//	return 0;
//}