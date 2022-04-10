#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*

char* MYstrcat(char* str1, char* str2);

//strcat	字符串拼接

int main()
{
	char str1[10] = "abc";
	char str2[] = "123";
	//char str1[10];
	//str1[0] = 'a';
	//str1[1] = 'b';
	//str1[2] = '\0';
	//str1[3] = 'c';//	\0后面的不会输出，如果多个\0识别的是第一个，\0不一定会放在最后面

	//strcat(str1, str2);
	//strcat_s(str1, sizeof(str1), str2);
	//MYstrcat(str1, str2);

	//strncat(str1,str2,2);
	//会直接复制，在程序结束回收内存的时候才报错，显示的是栈溢出，依然不安全，只要往内存里放东西就有可能放出界
	//_s这个函数在发现装不下时就不会复制，直接给你报错，显示的是str1太小的错误，方便找问题
	strncat_s(str1, sizeof(str1), str2, 2);
	printf("%s\n", str1);

	return 0;
}

//仿写strcat

char* MYstrcat(char* str1, char* str2)
{
	char* pMark = str1;
	while (*str1 != '\0') 
	{
		str1++;
	}
	while (*str2 != '\0') 
	{
		//*str1++ = *str2++;//*和++的优先级同级，结合性是从右往左，相当于*（str1++）= *（str2++）
		//str2++和++str2的区别，str2++是先赋值给前面，再++，++str2是++完再赋值给前面
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';//str2的'\0'没有复制进去，所以手动加了一个
	//本程序中不加这条也不会乱码的原因是str1是不完全初始化，识别到第一个\0开始拼接，结束后str1是abc123\0\0\0…

	return pMark;
}

*/



/*
//strcmp	比较两个字符串
//返回值Int类型，参数char*
//返回值为0时，字符串1等于字符串2；为-1时，字符串1小于字符串2；为1时，字符串1大于字符串2
//按位比较而不是比较长度~

//strncmp	比较部分字符串（前几位）

int MYstrcmp2(char* str1, char* str2);
int MYstrcmp(char* str1,char* str2);

int main()
{
	printf("%d\n", MYstrcmp("ac", "abc"));
	printf("%d\n", MYstrcmp("ab", "abc"));
	printf("%d\n", MYstrcmp("abc", "abc"));
	printf("----------------------\n");
	printf("%d\n", strcmp("ac", "abc"));//第二位上，c的ASCII码比b大，因此输出1
	printf("%d\n", strcmp("ab", "abc"));
	printf("%d\n", strcmp("abc", "abc"));
	printf("----------------------\n");
	printf("%d\n", MYstrcmp2("ac", "abc"));//第二位上，c的ASCII码比b大，因此输出1
	printf("%d\n", MYstrcmp2("ab", "abc"));
	printf("%d\n", MYstrcmp2("abc", "abc"));
	printf("----------------------\n");
	printf("%d\n", strncmp("ab", "abc", 2));

	return 0;
}

//strcmp函数的仿写

int MYstrcmp(char* str1,char* str2)
{
	while (*str1!='\0' && *str2!='\0')//只要有一个到'\0'就跳出循环
	{
		if (*str1<*str2)
		{
			return -1;
		}
		else if (*str2<*str1)
		{
			return 1;
		}
		else
		{
			str1++;
			str2++;
		}
	}

		if (*str1 < *str2)
		{
			return -1;
		}
		else if (*str2 < *str1)
		{
			return 1;
		}
		else
		{
			return 0;
		}

}

int MYstrcmp2(char* str1, char* str2) 
{
	while (*str1!='\0'||*str2!='\0')//两个都到'\0'才跳出循环
	{
		if (*str1 < *str2)
		{
			return -1;
		}
		else if (*str2 < *str1)
		{
			return 1;
		}
		else
		{
			str1++;
			str2++;
		}
	}
	return 0;
}
*/




/*
//字符串整型互转

//整型转字符串
//itoa(要转换的数字，地址，进制)//不安全
//_itoa_s(要转换的数字，填入字符串的地址，字符串大小，进制)

//字符串转整型
//atoi(字符串)	返回整形
int main()
{
	char str[10];
	_itoa_s(10, str, sizeof(str), 2);
	printf("%s\n", str);
	printf("--------------------------\n");

	printf("%d\n", atoi("1234"));
	printf("%d\n", atoi("-1234"));
	printf("%d\n", atoi("--1234"));//只能识别一个正负号
	printf("%d\n", atoi("12+34"));//遇到非数字后面就无法识别
	printf("%d\n", atoi("12.34"));//遇到非数字后面就无法识别
	printf("%d\n", atoi("12a34"));//遇到非数字后面就无法识别
	printf("%d\n", atoi("a1234"));//遇到非数字后面就无法识别
	printf("%d\n", atoi("    1234"));//开头空格不限个数能识别但不显示
	printf("%d\n", atoi("12 34"));//遇到非数字后面就无法识别

	return 0;
}
*/