	
//字符串练习题
//
//1.查找一个字符在另外一个字符串中第一次出现的下标
//2.查找一个字符在另外一个字符串中第一次出现的地址
//3.查找一个字符串在另外一个字符串中第一次出现的地址  abcccccde ccd
//4.统计一个字符串中单词的个数(单词与单词之间是空格分割)"a abc make 89 12 a ma make 12 abc 89"
//5.将一个字符串插入到另一个字符串中  "abcd"  "12345" 3
								//(将第二个字符串插入到第一个字符串第三位的前面也就是ab12345cd）

/*
#include <stdio.h>
#include <string.h>

int T1(char* str, char a);
char* T2(char* str, char a);
char* T3(char* str1, char* str2);
int T4(char* str1);
//char* T5(char* str1, char* str2, char* str);
//插入要在原有的基础上去做，不要开辟更大的空间
void T5(char* str1, char* str2, int n);

int main() 
{
	printf("T1----------------------\n");
	printf("%d\n", T1("abc", 'c'));
	printf("%d\n\n", T1("abc", 'e'));

	printf("T2----------------------\n");
	//(检验地址可以间接引用，看看是不是这个地址上的内容就可以了)
	printf("%c\n\n", *T2("abc", 'c'));

	printf("T3----------------------\n");
	//(只要确认前三个内容正确即可)
	printf("%s\n\n", T3("abcccccde", "ccd"));

	printf("T4----------------------\n");
	printf("%d\n\n", T4("a abc make 89 12 a ma make 12 abc 89"));

	printf("T5----------------------\n");
	//printf("%s\n\n",T5("abcd","12345",3));
	//str1的数组长度不够大
	char str[20] = "abcd";
	T5(str, "12345", 3);
	printf("%s\n\n", str);
	//输出结果是ab12345


	return 0;

}

int T1(char* str, char a) 
{
	int Mark = 0;
	while (*str != '\0') 
	{
		if (*str == a) 
		{
			return Mark;
		}
		str++;
		Mark++;
	}
	return -1;
}

char* T2(char* str, char a)
{
	while (*str != '\0')
	{
		if (*str == a)
		{
			return str;
		}
		str++;
	}
	return NULL;
}


char* T3(char* str1, char* str2) 
{
	while (*str1 != '0') 
	{
		if (0 == strncmp(str1, str2, strlen(str2)))
		{
			return str1;
		}
		str1++;//char* 字符指针数据类型，str1++则表示指向位置偏移
	}
	return NULL;
}

int T4(char* str1) 
{
	int count = 0;
	while (*str1 != '\0') 
	{
		if (*str1 == ' ') //注意=和==的区别！
		{
			count++;
		}
		str1++;
	}
	return count+1;
}//注意：本程序只能计算每个单词之间空一个格的单词个数，如果每个单词间空多个或者全是空格没有单词则不成立了

void T5(char* str1, char* str2, int n)
//思路:
//先找到第三位的位置，两种方式，①先遍历字符串找到第三位，②直接进行字符串数组偏移到第三位
//然后再将第三位之后的字符串偏移插入字符串字数的数量，需要注意的是要从后往前一位位移动，如果从前往后以后，一旦第三位之后的字符串字数数量大于要插入的字符串字数数量，那么原来的字符串就会有被覆盖的情况发生。
{
	char* p1 = str1 + n - 1;//找到第三位前的位置：首地址＋3-1
	char* p2 = str1 + strlen(str1);//找到'\0'的位置，还有遍历的方法但是比较麻烦
	//strlen计算字符串长度时候不计算’\0’在内，-1的原因是str1是第一个字符的地址，strlen把第一个重复计入了
	//①while (p1 < p2) //要插入的位置在\0的前面
	//但此时c没有挪过去，当p1和p2都指向c时，没有进入循环
	while (p1<=p2)
	{
		*(p2 + strlen(str2)) = *p2;
		//第一次进入循环时的解释//对p2 + strlen(str2)这个地址上的内容进行赋值，所以使用间接引用
							//p2 + strlen(str2)的含义是\0所在的地址往后偏移str2个长度
							//最终达到把\0移动到str2字符串数组长度之后的位置上，以便插入str2这个字符串
		p2--;
	}

	while (*str2 != 0) 
	{
		*p1 = *str2;
		p1++;
		str2++;
	}//①的情况下：为什么c本来应该出现的位置不是空而是\0呢？
	 //主函数中定义char str[20] = "abcd";//不完全初始化，后面没有初始化的部分全部都是'\0'
}
*/