#include "4-28head.h"	//��˫����
						//����Զ���ͷ�ļ���ϵͳ��������ôʹ��<>ʱ��������ϵͳ�ģ�ʹ��""ʱ����Ӧ���Զ����



//ö�� ���峣����һ�ַ�ʽ Ҳ��������
//
//enum AA {JIANZI,SHITOU,BU};//0,1,2
//enum BB {J,S=100,B};//0,100,101
//
//int main()
//{
//	enum AA a = JIANZI;
//	//eunm BB b = 0;
//	//��ȻJ=0����ʵ����J��BB���͵ģ�0��int���͵ģ�����������������
//	
//	switch (a)
//	{
//	case JIANZI:
//		printf("����\n");
//		break;
//	case SHITOU:
//		printf("ʯͷ\n");
//		break;	
//	case BU:
//		printf("��\n");
//		break;
//	default:
//		break;
//	}
//
//	return 0;
//}
//



//������

//union AA 
//{
//	char a;
//	int b;
//	short c;
//};
////���г�Ա����һ���ռ䣬�����������ľ��Ǹ��������size
//
//int main() 
//{
//	union AA a;
//	printf("%d\n", sizeof(a));
//
//	//a.a = 1;
//	//������������Ļ��������ֻ��a��1����������������
//	//charֻ��һ���ֽڣ�����int�����������ֽ�û�б���ֵ����������
//	a.b = 1;
//	//��������ľ�Ϊ1��ԭ����int���ĸ��ֽڶ��Ѿ���ֵ��
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