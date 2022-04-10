#include <stdio.h>

//两乒乓球队比赛，各出三个人，抽签决定比赛名单，甲队为abc，乙队为xyz，a不和x比，c不和x和z比，请输出三队选手pk名单。(注意是否排除一对多的可能性)
/*
int main()
{
	char a;
	char b;
	char c;

	for (a='x';a<='z';a++)//字符型变量可以通过++改变数字或者字母内容
	{
		for (b='x';b<='z';b++)
		{
			for (c='x';c<='z';c++)
			{
				//if (a != 'x' && c != 'x' && c != 'z')//可以一对多的情况
				if (a != b && b != c && c != a && a != 'x' && c != 'x' && c != 'z')//只能一对一的情况

				{
					printf("a —— %c\t", a);//注意区分%d和%c分别使用哪种变量
					printf("b —— %c\t", b);
					printf("c —— %c\n", c);
				}
			}
		}
	}//嵌套执行情况为3*3*3=27次
	return 0;
}
*/




//0b开头二进制，0开头八进制，0x开头十六进制
/*
int main()
{
	//char a = 127;
	unsigned char a = 255;
	a++;
	printf("%d\t", a);
	a--;
	printf("%d\n", a);
	return 0;
}
*/

