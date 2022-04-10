#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//字符串练习题

//6.翻转字符串
//7.判断是否回文(回文指的是顺读和逆读都一样的字符串)  "abcdcba"

/*

void T6(char* str);
int T7(char* str);

int main() 
{
	char str[] = "123456";
	T6(str);
	printf("%s\n", str);
	
	printf("%d\n", T7("123456"));
	printf("%d\n", T7("abcdcba"));

	return 0;
}

void T6(char* str) 
{
	char* begin = str;
	char* end = str + strlen(str) - 1;
	char c;

	while (begin < end)
	{
		c = *begin;
		*begin = *end;
		*end = c;

		begin++;
		end--;
	}
}

int T7(char* str) 
{
	char* begin = str;
	char* end = str + strlen(str) - 1;
	int Bool = 0;

	while (begin < end)
	{
		if (*begin == *end)
		{
			begin++;
			end--;
		}
		if (*begin != *end) 
		{
			return Bool;
		}
	}
	while (begin = end)
	{
		Bool++;
		return Bool;
	}
	return Bool;
}
*/

/*
int main()
{
	printf("%c\n", getchar());
	printf("%c\n", getchar());
	printf("%c\n", getchar());
	printf("%c\n", getchar());
	printf("%c\n", getchar());
	//输入字符后可以读取一位
	//输入abc\0，实际上需要读取四位，最后的\0也会被获取，所以再输入ab时只能读取a

	return 0;
}
*/



//要求：未知多少位的情况下，需要将所有内容回显出来
/*
int main() 
{
	//while (getchar() != '\n')
	//{
	//	printf("%c", getchar());
	//}

	//以12345\n为例,输出24且无法结束程序
	//getchar() != '\n'中getchar得到135,printf("%c", getchar())中getchar()得到24\n
	//以1234\0为例，输出24后可以结束程序
	//getchar() != '\n'中getchar得到13\n,printf("%c", getchar())中getchar()得到24

	//getchar()每次读取一个字符后无论是否输出都不会存放


	char c;
	//while (c = getchar() != '\n')
	//!=的优先级比=高，因此先执行getchar() != '\n'返回真也就是1
	//所以c（char型）存放的是1，会显示出方块

	while ((c = getchar()) != '\n')
	{
		printf("%c", c);
	}
	return 0;
}
*/



//暂存用户输入的一段字符，以便所需时取用
/*

char* GetString();

int main()
{

	char* str = GetString();

	printf("%s\n", str);

	return 0;
}

char* GetString()
{
	char c;
	int size = 5;
	char* str = (char*)malloc(size);
	int count = 0;
	char* newstr = NULL;
	char* pMark = str;

	//从输入缓冲区中取字符
	while ((c = getchar()) != '\n')
	{
		//取下的字符放到字符数组里
		*str = c;
		//计数累计
		count++;
		str++;
		//判断是否能放下
		if (count + 1 == size)
		{
			//放不下
			//变字符串
			*str = '\0';
			//size增大
			size += 5;
			//开辟一个新的空间
			newstr = (char*)malloc(size);
			//将老字符串拷贝到新字符数组中
			strcpy_s(newstr, size, pMark);
			//释放老字符串
			free(pMark);
			//找到新字符串结尾位置
			str = newstr + count;
			//标记指向字符串首地址
			pMark = newstr;
		}
	}
	//变字符串
	*str = '\0';

	return pMark;
}

*/

/*
定义一个char类型字符（传入）
用malloc函数在堆区开辟一个新的空间存字符串
定义一个char* 类型指针标记字符串首地址
定义一个char* 类型字符串为空
定义一个int类型变量计数

while循环，当传入字符c不等于‘\n’时
字符c的值传入malloc定义的字符串，
字符串地址后移
计数
当（统计次数 + 1）等于开辟空间大小时
给字符串赋‘\0’
增大空间
给新字符串开辟增大后的空间
调用strcpy函数将原有字符串（标记指针所指向）内容存到新的字符串中
释放原字符串的空间
标记指针指向新字符串的首地址
最后为字符串赋‘\0’
返回 标记指针首地址
*/ 