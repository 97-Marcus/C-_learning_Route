#include <stdio.h>


//��ӡĳ��ĳ�µ���������Ҫ�ж�2�£�
/*
int main() 
{
	int year = 2021;
	int mouth = 2;

	switch(mouth)
	{
		case 1:
			printf("31��\n");
			break;
		case 2:
			if (year % 4 == 0)
			{
				printf("29��\n");
			}
			else
				printf("28��\n");
			break;
		case 3:
			printf("31��\n");
			break;
		case 4:
			printf("30��\n");
			break;
	}

	return 0;
}
*/



//������������
/*
int main()
{
	int day = 1;//0�Ǻ��죬1�ǰ���
	int now_meter = 0;
	int total_day = 0;

	////����һ��
	//while (now_meter < 10) 
	//{
	//	if (1 == day)
	//	{
	//		now_meter += 5;
	//		day = 0;
	//		total_day++;
	//	}
	//	//if (0 == day)
	//	//{
	//	//	now_meter -= 4;
	//	//	day = 1;
	//	//}//�������ʱ��now_meter=10,����û������whileѭ�����ٴν����������ifѭ�������Ӧ��ʹ��else��
	//	else
	//	{
	//		now_meter -= 4;
	//		day = 1;
	//	}
	//}

	//��������
	while (1) 
	{
		total_day++;
		now_meter += 5;
		if (now_meter >= 10) 
		{
			break;
		}
		now_meter -= 4;
	}
	printf("%d\n", total_day);
	return 0;
}
*/



//����Ķ�������������36������13��������������Ƕ��ӵĶ�����
/*
int main()
{
	int father = 36;
	int son = 13;
	int year = 0;
	while (father < 150)
		//ע���������ƣ�����ʵ�����⣬�˲������������Բ�Ҫʹ����ѭ����Ҳ��Ҫʹ�ø�������Ϊ������һ������Ϊѭ��������������
	{
		if (2 * son == father)
		{
			printf("son=%d   father=%d   year=%d", son, father, year);
		}
		//else 
		//{
		//	father++;
		//	son++;
		//	year++;
		//}
		//if else��ֻ�����һ���������������ʹ��else����ô������if��㲻�����else����ôҲ�ʹﲻ��father++���޷�����while����Ϊ����ѭ��;���ʹ��else����ô��ʹ��һ��break��������whileѭ��������ֻ�������һ������Ϊ������������޷���ȡ���ڶ��μ��Ժ�ġ���ˣ���ȷ�������£�
		father++;
		son++;
		year++;
	}
	return 0;
}
*/



//��ӡ�����е�ˮ�ɻ�����ˮ�ɻ�����ָ����һ����λ�������λ���ֵ������͵��ڸ����������磺153=1�����η�+5�����η�+3�����η����ѵ�:������ΰѰ�λ��ʮλ����λȡ������
//��λ������c�У���������ֻ�ܵõ�����������/100���ɵõ���λ
//��λ��ȡ��10���ɵõ���λ
//ʮλ���ٳ���/10ʣ�°�λʮλ��λ���ٴ�ȡ��%10�õ�ʮλ������ȡ��100ʣ��ʮλ��λ���ٳ���/10�õ�ʮλ
/*
int main() 
{
	int i;
	for (i = 100; i <= 999; i++)
	{
		int a = i / 100;
		int b = i / 10 % 10;
		int c = i % 10;
		if (a * a * a + b * b * b + c * c * c == i) 
		{
			printf("%d\n", i);
		}
	}
	return 0;
}
*/


//���ӵ�һ��ժ���������ӣ���������һ�룬�ֶ����һ�����ڶ���Ҳ��ˣ���������ʮ��ʱ������ֻʣ��һ�������ˣ���һ���ж������ӣ�
/*
int main()
{
	int tatol = 1;
	int i;
	for (i = 1; i <= 9; i++)
	{
		tatol = (tatol + 1) * 2;
		printf("��%d����%d������\n", 10-i,tatol);
	}
	return 0;
}
*/



//�߼�����
/*
int main()
{
	int age = 25;
	int sex = 0;//0ΪŮ��1Ϊ��

	////���������ڵ���25����ΪŮ��
	//if (age >= 25 && 0 ==sex)//�����������Ϊ�棬��һ��or���������㶼Ϊ��&&
	//{
	//	printf("ok");
	//}
	//else
	//{
	//	printf("no");
	//}

	////||���ڵ���25�꣬��Ů���ޣ�С��25�꣬��������
	//if (age >= 25 || 1 == sex)//ֻҪ��һ�����������㼴Ϊ�棬����������������Ϊ��||
	//{
	//	printf("ok");
	//}
	//else
	//{
	//	printf("no");
	//}

	printf("%d", !!age);//ȡ��ֻ�᷵��0��1
	return 0;
}
*/

