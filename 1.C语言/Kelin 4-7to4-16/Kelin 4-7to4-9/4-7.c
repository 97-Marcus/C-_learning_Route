#include <stdio.h>



//typedef + ���� + ���� ��

/*
typedef unsigned int UINT;
typedef int* AA;
typedef int ARR[5];//ʹ��typedef�������ʱ��ҲҪ����ԭ���ĸ�ʽ

int main()
{
	UINT a = 10;
	unsigned d = 10;
	printf("%d\n%d\n", a, d);
	int* p,p0;//��ʱ��p��int*���ͣ�p0��int����
	AA p1,p2;//��ʱp1��p2����AA��Ҳ����int*����

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
	//a = 2;//��const���εı������ɳ������������ٽ����޸�
	//const int d;//const���εı��������ʼ��

	int c;
	const int* p1 = &c;//��int const *��һ���� 
					   //const��*��ߣ�p���Ըģ����Ը�ָ��˭�ĵ�ַ����*p���ɸģ������Ը�ָ��ĵ�ַ�ϵ����ݣ�
	int* const p2 = &c;//const��*�ұߣ�p�����Ըģ�*p���Ըģ�
	int const* constp3 = &c;//���߶���const��ʱ�򣬶������Ը�

	return 0;
}
*/




//1.Ԥ����	2.����	3.���	4.����
//�������滻
//#define + ������� + Ҫ�滻������


/*
#define AA printf("hello\n")
#define BB int *   //��ò��ӷֺš�
				   //������˵Ļ� ������дBB a�������������ʱ������Ϊʵ������int��a��
int main()
{
	AA;
	BB a, b;//��ʱa��int*���ͣ�b��int����
	return 0;
}
*/

//�в����ĺ�
/*
#define ADD(a,b)  a + b
#define MUL(a,b)  a * b
#define ARRLEN(a)	sizeof(a)/sizeof(a[0])
int main()
{
	printf("%d\n", ADD(1, 2));
	printf("%d\n", MUL(2+2, 3+3));
		//���Ϊ11��ԭ���ǣ�2+2*3+3=11,�궨��ʱ�������ż��ɣ�#define MUL(a,b)  (a) * (b)
	
	int arr[5];
	printf("%d\n", ARRLEN(arr));
	
	return 0;
}
*/


//λ����
/*
int main()
{
	//��		&	//����1Ϊ1
	//��		|	//��1��Ϊ1
	//ȡ��	~	//1��0����
	//���	^	//��ͬΪ0 ��ͬΪ1
	//����	<<	//���Ʋ�0
	//����	>>	//���Ʋ�����λ����Ϊ�޷������ͣ���0��

	
	int a = -1;
	-1 >>5��//-1Ϊ1111 1111�����Բ����ƶ���λ������궼��1111 1111

	int a = 1;
	int b = 2;
	//����a��b������
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;

	printf("%d\n%d\n", a, b);
	return 0;
}
*/


