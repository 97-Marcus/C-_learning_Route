#include <stdio.h>

//判断187是否能被3整除
//C中任意一个整数除以任意一个整数其结果还是整型，不会产生小数。
/*
int main()
{
	int x = 187;

	if(x % 3 == 0)
	{
		printf("yes\n");
	}
	else 
	{
		printf("no\n");
	}

	return 0;
}
*/



//某数变英文
/*
int main()
{
	int x = 3;
	switch (x) 
	{
	case 1:
		printf("one\n");
		break;
	case 2:
		printf("two\n");
		break;
	case 3:
		printf("three\n");
		break;
	default:
		printf("没有此数\n");
	}
	return 0;
}
*/



//找出三个数当中最大的数
/*
int main() 
{
	int a = 8;
	int b = 5;
	int c = 7;
	int max;

	if (a > b)
	{
		max = a;
	} 
	else
	{
		max = b;
	}

	if (max > c)
	{
		printf("%d\n", max);
	}
	else
	{
		printf("%d\n", c);
	}
	return 0;
}
*/



//1000以内被3整除的数
/*
int main() 
{
	int x;

	for (x=1; x<1000;x++)
	{
		if (x % 3 == 0)
		{
			printf("%d\n", x);
		} 
	}
	return 0;
}
*/



//连加5+6+7+....=?，加到多少的时候，结果刚好超过100？
/*
int main() 
{
	int x = 5;
	int sum = 0;

	do 
	{
		sum = sum + x;
		printf("sum=%d\n x=%d\n", sum, x);
		x = x + 1;
	} while (sum<100);

	return 0;
}
*/



//打印对称图形
/*
int main()
{
	int h;
	int k;
	int x;

	for (h = 1; h <= 5; h++)
	{
		for (k = 1; k <= 5 - h; k++)
		{
			printf(" ");
		}
		for (x = 1; x <= 2 * h - 1; x++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
*/



//打印数字
/*
int main()
{
	int hang;
	int lie;
	for (hang=1;hang<=4;hang++)
	{
		for (lie=hang;lie<=hang+4;lie++)
		{
			printf("%d\t", lie);
		}
		printf("\n");
	}
	return;
}
*/



//打印乘法表格
/*
int main() 
{
	int hang;
	int lie;
	for (hang=1;hang<+9;hang++)
	{
		for (lie=1;lie<=hang;lie++)
		{
			printf("%d*%d=%d\t", lie, hang, lie * hang);
		}
		printf("\n");
	}
	return 0;
}
*/


