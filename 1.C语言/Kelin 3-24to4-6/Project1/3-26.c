#include <stdio.h>


//打印某年某月的天数（主要判断2月）
/*
int main() 
{
	int year = 2021;
	int mouth = 2;

	switch(mouth)
	{
		case 1:
			printf("31天\n");
			break;
		case 2:
			if (year % 4 == 0)
			{
				printf("29天\n");
			}
			else
				printf("28天\n");
			break;
		case 3:
			printf("31天\n");
			break;
		case 4:
			printf("30天\n");
			break;
	}

	return 0;
}
*/



//青蛙爬井问题
/*
int main()
{
	int day = 1;//0是黑天，1是白天
	int now_meter = 0;
	int total_day = 0;

	////方法一：
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
	//	//}//第六天的时候now_meter=10,但是没有跳出while循环，再次进行了下面的if循环，因此应该使用else。
	//	else
	//	{
	//		now_meter -= 4;
	//		day = 1;
	//	}
	//}

	//方法二：
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



//年龄的二倍，父亲年龄36，儿子13，几年后父亲年龄是儿子的二倍。
/*
int main()
{
	int father = 36;
	int son = 13;
	int year = 0;
	while (father < 150)
		//注意年龄限制，考虑实际问题，人不能永生，所以不要使用死循环，也不要使用父亲年龄为二倍这一条件作为循环函数的条件。
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
		//if else中只会进行一个，本程序中如果使用else，那么当进入if后便不会进入else，那么也就达不到father++，无法跳出while，成为了死循环;如果使用else，那么再使用一个break可以跳出while循环，但是只能输出第一次年龄为二倍的情况，无法获取到第二次及以后的。因此，正确程序如下：
		father++;
		son++;
		year++;
	}
	return 0;
}
*/



//打印出所有的水仙花数，水仙花数：指的是一个三位数，其各位数字的立方和等于该数本身。比如：153=1的三次方+5的三次方+3的三次方。难点:在于如何把百位，十位，个位取下来。
//百位：利用c中，整数除整只能得到整数，除法/100即可得到百位
//个位；取余10即可得到个位
//十位：①除法/10剩下百位十位两位数再次取余%10得到十位；②先取余100剩下十位个位，再除法/10得到十位
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


//猴子第一天摘了若干桃子，当即吃了一半，又多吃了一个，第二天也如此，……到第十天时，发现只剩下一个桃子了，第一天有多少桃子？
/*
int main()
{
	int tatol = 1;
	int i;
	for (i = 1; i <= 9; i++)
	{
		tatol = (tatol + 1) * 2;
		printf("第%d天有%d个桃子\n", 10-i,tatol);
	}
	return 0;
}
*/



//逻辑与或非
/*
int main()
{
	int age = 25;
	int sex = 0;//0为女，1为男

	////年龄必须大于等于25岁且为女性
	//if (age >= 25 && 0 ==sex)//两个均满足才为真，有一个or两个不满足都为假&&
	//{
	//	printf("ok");
	//}
	//else
	//{
	//	printf("no");
	//}

	////||大于等于25岁，男女不限，小于25岁，必须男性
	//if (age >= 25 || 1 == sex)//只要有一个或以上满足即为真，如果两个都不满足才为假||
	//{
	//	printf("ok");
	//}
	//else
	//{
	//	printf("no");
	//}

	printf("%d", !!age);//取非只会返回0和1
	return 0;
}
*/

