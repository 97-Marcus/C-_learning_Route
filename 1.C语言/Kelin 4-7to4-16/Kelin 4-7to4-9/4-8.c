#include <stdio.h>


//���� �Բ���ķ�װ
//����ֵ + ������ +���������ͣ�+ ��
//void �޷���ֵ
//����ֵֻ��һ��

/*

void printHello();//��������
int Add11();
int ADD(int,int);

int main()
{
	printHello();//��������
	Add11();
	int c = Add11();
	printf("%d\n", c);

	int d = 2;
	int a = ADD(1, d);//ʵ��//��ʵ�ǻ���һ�����ص�ʵ�θ��βθ�ֵ�Ĺ��̣�int a=1��int b=d��
	printf("%d\n", a);
	printf("%d\n", ADD(2, Add11()));
	return 0;
}


void printHello() //��������ʵ��
{
	printf("Hello!\n");
	return;
	//��������return�ͽ���
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

int ADD(int a, int b) //�β�
{
	return a + b;
}

*/




//���鴫��
/*
void PrintARR();
//void PrintARRPro(int arr[]);
void PrintARRPro(int arr[],int len);

int main() 
{
	//PrintARR();
	int arr[] = { 1,2,3,4,5 };
	//PrintARRPro(arr);	
	//���ι���Ϊ��int arr[]=arr�����ڸ�ֵ������Ԫ�صĵ�ַ ��Ҳ����int arr[] = *arr;
	//������������������²Ŵ������鱾�����ö������Ŀռ䣩1.������������ȡ��ַ   2.������������sizeof֮��
	//������������ʾ��Ԫ�صĵ�ַ:���磺�������Ρ� > int*

		//int array[] = { 1, 2, 3, 4, 5 };

		//int* p1 = array;
		//int* p2 = array + 0;
		//int* p3 = &array[0];

		//printf("%d\n", p1);
		//printf("%d\n", p2);
		//printf("%d\n", p3);	//�����������һ����
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
	n = sizeof(arr) / sizeof(arr[0]);//�������1��ԭ���ǣ�arr��ʵ��������������*arr��ָ���С��4������4����4�õ�1
	//�������鴫������Ҫ�õ�����ĳ��ȣ�������Ҫ������������Ԫ�صĵ�ַ�����鳤�ȣ�

	for (i = 0; i < len; i++)
	{
		printf("%d\n", arr[i]);
	}
}
*/