#include < stdio.h >
#include < string.h >

//字符串：以'\0'结尾的字符数组

/*
int main() 
{
	char str[5] = { 'a','b','c','d','\0' };//'\0'不会被输出
	//char str[5] = { 'a','b','c','d','0' };
	//'\0'不等于‘0’，在ASCII中‘\0’ == 0,'0' == 48
	//char str[5] = { 'a','b','c','d','e' };
	//没有以\0结尾，后面乱码
	//char str[5] = { 'a','b','c','d'};
	//数组中没有被定义的位置自动补为0，也就相当于‘\0’,因此可以输出abcd

	char str1[] = "abcde"; //在栈区定义一个字符数组，然后将字符常量区中的字符串拷贝到栈区的字符数组中
	//此时这个数组存放六个字符 分别是abcde和\0
	//所有以双引号出现的字符串，都存储在字符常量区
	//“abcde”代表a的地址，单拿出“xxx”代表该字符串在字符常量区存储空间首元素的地址

	char* str2 = "abcde";//该指针在字符常量区

	printf("%d\n", sizeof(str1));	
	printf("%d\n", sizeof(str2));
	//str1与str2大小不一样，1是字符串数组，长度由数组元素（字符串长度）决定，2是指针，指针大小由程序位数决定

	//修改的不同
	  str1[1] = 'B';
	//str2[1] = 'B';//该指针在字符常量区，常量，所以不可以修改
				  //str1可以修改的原因是，它的类型是栈区的字符数组中
	printf("%s\n", str);
	printf("%s\n", str1);

	printf("%d\n", strlen(str));//strlen是计算字符串长度的，不算\0
	printf("%d\n", sizeof(str));//sizeof是计算大小的，由于\0也占用空间，所以要算


	return 0;
}
*/



//strlen函数的仿写
/*
int MYstrlen(char* str);

int main()
{
	char str[5] = { 'a','b','c','d','\0' };
	printf("%d\n", MYstrlen(str));
}

int MYstrlen(char* str) 
{
	int count = 0;
	
	//知道次数时用for，不知道次数的时候用while
	//while (str!='\0')
	//应该是字符串里面的内容和\0比较,而不是str（指针）去进行比较,地址不可能等于\0，所以需要间接引用

	while (*str!='\0')
	{
		count++;
		str++;
	}//遍历字符串的套路~
	
	//当*str='\0'时就不符合循环条件了，因此会跳出循环，不执行while中的语句块，所以count不会+1。
	//计算长度时，\0不包括在内，所以返回count即可。

	return count;
}
*/



//strcpy(目标，源)	返回值是目标的首地址，没有返回值则错误，返回空NULL
/*
int main()
{
	char str1[10];
	char str2[] = "abcd";
	strcpy_s(str1, sizeof(str1), str2);
	printf("%s\n", str1);
	//复制字符串,strcpy不安全，需要用strcpy_s来替换
	//不安全是因为如果目标的空间比较小或者比较大，那么会栈溢出或者乱码
	//strcpy_s(目标，目标的大小，源)	
	//返回值是int，如果成功返回0，如果失败返回非0值，不同值表示不同的错误，需要查阅手册
	return 0;
}
*/


//仿写syrcpy
/*
char* MYsyrcpy(char* str1, char* str2);

int main()
{
	char str1[10];
	char str2[] = "abcd";

	printf("%s\n", MYsyrcpy(str1, str2));

	return 0;
}

char* MYsyrcpy(char* str1, char* str2) 
{
	char* pmark = str1;
	while (*str2 != '\0')
	{
		*str1 = *str2; 
		str1++;
		str2++;
	}
	//str2的\0还没有复制过去，所以str1还不是字符串，所以需要再赋值\0
	*str1 = '\0';
	//return str1;//错误的原因是str1在程序中进行了++，所以已经不是首元素的地址了，所以需要在最前面先记录首元素地址
	return pmark;
}
*/


//strncpy（目标，源，要复制多长）	部分复制
//注意，也不安全，需要更换为strncpy_s
/*
int main()
{
	char str1[10];
	char str2[] = "abcd";

	//strncpy(str1, str2, 3);
	strncpy_s(str1, sizeof(str1), str2, 3);
	printf("%s\n", str1);

	return 0;
}
*/
