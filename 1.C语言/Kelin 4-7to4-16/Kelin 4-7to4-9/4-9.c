#include <stdio.h>




//ֵ���ݣ��������Ҫ�޸�ʵ�Σ�ֻ��Ҫ���䴫�ݽ�ĳ�������У���ô����ѡ��ֵ����
//��ַ���ݣ������Ҫͨ������ȥ�޸�main�е�ʵ�Σ���ôѡ���ַ����
//ע�⣺���Ǻ��������г���ָ����ǵ�ַ���ݣ���Ϊ�п���ʵ�ξ���һ��ָ�룬ֱ�Ӱ�ָ���ֵ������Ҳ��ֵ����

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
//main�е�ab��change�е�ab��һ����main�е�ab������ֵ������change��ab��change��ab���н�����main�е�abû�б仯
//���������������һ����ʵ�ʲ�һ����û������ab���ݣ�����ַ��Ψһ�ģ�����ͨ����ַ�������ݵĽ���

void change(int *a,int *b) 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

*/



//������ϰ��
//1.��дһ������������Ϊ��������int���Ͳ��������ֵ
//2.��дһ������������һ��������һ����֮������������ӵĺ�
//3.��дһ������������һ��int����������Ԫ�ص�ֵ
//4.��дһ������������double���������Ԫ�ص��±�
//5.��дһ������������double���������Ԫ�ص���ֵ���±�


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
	//������������±��������ֵ��ԭ����Ҫѧϰ��ջ�ſ��Խ���
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
		//��sum = sum + i
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
//��Ϊ����ֵֻ������һ����������Ҫ�޸Ķ��ʵ��ʱ������ͨ����ַ����������~
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



//����ָ��(�������OneNote~)
/*
void AA();//AA��void�������͵�
int add(int a, int b);

//typedef int(*) (int, int) PFUN;//д����λ��������飬ҲҪ���ո�ʽд
typedef int(*PFUN)(int, int);

int main() 
{
	//void* pfun() = &AA;//void * �Ƿ��ͣ�û�����͵ĵ�ַ������ʽ�Ӳ�������ԭ���ǣ���߲���ָ����Ǻ���
	void(*pfun) = &AA;
	
	AA();
	//&AA();//ȡ���Ǻ�������ֵ�ĵ�ַ��Ӧ����ȡ��ַ���ٺ����Ž�ϣ�
	(&AA)();

	//int(*pfun1)(int a, int b) = &add;	//һ��˵���Ͳ������֣�����ab��Ҫɾ���ģ����ǲ�Ӱ����������
	//int(*pfun1)(int , int ) = &add;	//̫�鷳������ʹ��typedef���и���
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
������⣺
typedef ֻ�����е����ͽ��б������壬�������µ����ͣ�
#define ֻ����Ԥ������̶Դ�����м򵥵��滻��
�����˽���������󣬷������Ǿ���������ͬ�ĸ����û��̫�����ϵ��

�����⣺
typedef  unsigned int  UINT32;  // UINT32 ������unsigned int
UINT32 sum;                     // ����һ��������int sum;
typedef  int  arr[3];           // arr ������ int[3];�����int�����ݵ����飩
arr a;							// ����һ�����飺int a[3];

ͬ��
typedef  void (*pfun)(void);    // pfun ������ void(*)(void)
pfun main;                      // ����һ��������void (*main)(void);
*/