#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*

char* MYstrcat(char* str1, char* str2);

//strcat	�ַ���ƴ��

int main()
{
	char str1[10] = "abc";
	char str2[] = "123";
	//char str1[10];
	//str1[0] = 'a';
	//str1[1] = 'b';
	//str1[2] = '\0';
	//str1[3] = 'c';//	\0����Ĳ��������������\0ʶ����ǵ�һ����\0��һ������������

	//strcat(str1, str2);
	//strcat_s(str1, sizeof(str1), str2);
	//MYstrcat(str1, str2);

	//strncat(str1,str2,2);
	//��ֱ�Ӹ��ƣ��ڳ�����������ڴ��ʱ��ű�����ʾ����ջ�������Ȼ����ȫ��ֻҪ���ڴ���Ŷ������п��ܷų���
	//_s��������ڷ���װ����ʱ�Ͳ��Ḵ�ƣ�ֱ�Ӹ��㱨����ʾ����str1̫С�Ĵ��󣬷���������
	strncat_s(str1, sizeof(str1), str2, 2);
	printf("%s\n", str1);

	return 0;
}

//��дstrcat

char* MYstrcat(char* str1, char* str2)
{
	char* pMark = str1;
	while (*str1 != '\0') 
	{
		str1++;
	}
	while (*str2 != '\0') 
	{
		//*str1++ = *str2++;//*��++�����ȼ�ͬ����������Ǵ��������൱��*��str1++��= *��str2++��
		//str2++��++str2������str2++���ȸ�ֵ��ǰ�棬��++��++str2��++���ٸ�ֵ��ǰ��
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';//str2��'\0'û�и��ƽ�ȥ�������ֶ�����һ��
	//�������в�������Ҳ���������ԭ����str1�ǲ���ȫ��ʼ����ʶ�𵽵�һ��\0��ʼƴ�ӣ�������str1��abc123\0\0\0��

	return pMark;
}

*/



/*
//strcmp	�Ƚ������ַ���
//����ֵInt���ͣ�����char*
//����ֵΪ0ʱ���ַ���1�����ַ���2��Ϊ-1ʱ���ַ���1С���ַ���2��Ϊ1ʱ���ַ���1�����ַ���2
//��λ�Ƚ϶����ǱȽϳ���~

//strncmp	�Ƚϲ����ַ�����ǰ��λ��

int MYstrcmp2(char* str1, char* str2);
int MYstrcmp(char* str1,char* str2);

int main()
{
	printf("%d\n", MYstrcmp("ac", "abc"));
	printf("%d\n", MYstrcmp("ab", "abc"));
	printf("%d\n", MYstrcmp("abc", "abc"));
	printf("----------------------\n");
	printf("%d\n", strcmp("ac", "abc"));//�ڶ�λ�ϣ�c��ASCII���b��������1
	printf("%d\n", strcmp("ab", "abc"));
	printf("%d\n", strcmp("abc", "abc"));
	printf("----------------------\n");
	printf("%d\n", MYstrcmp2("ac", "abc"));//�ڶ�λ�ϣ�c��ASCII���b��������1
	printf("%d\n", MYstrcmp2("ab", "abc"));
	printf("%d\n", MYstrcmp2("abc", "abc"));
	printf("----------------------\n");
	printf("%d\n", strncmp("ab", "abc", 2));

	return 0;
}

//strcmp�����ķ�д

int MYstrcmp(char* str1,char* str2)
{
	while (*str1!='\0' && *str2!='\0')//ֻҪ��һ����'\0'������ѭ��
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
	while (*str1!='\0'||*str2!='\0')//��������'\0'������ѭ��
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
//�ַ������ͻ�ת

//����ת�ַ���
//itoa(Ҫת�������֣���ַ������)//����ȫ
//_itoa_s(Ҫת�������֣������ַ����ĵ�ַ���ַ�����С������)

//�ַ���ת����
//atoi(�ַ���)	��������
int main()
{
	char str[10];
	_itoa_s(10, str, sizeof(str), 2);
	printf("%s\n", str);
	printf("--------------------------\n");

	printf("%d\n", atoi("1234"));
	printf("%d\n", atoi("-1234"));
	printf("%d\n", atoi("--1234"));//ֻ��ʶ��һ��������
	printf("%d\n", atoi("12+34"));//���������ֺ�����޷�ʶ��
	printf("%d\n", atoi("12.34"));//���������ֺ�����޷�ʶ��
	printf("%d\n", atoi("12a34"));//���������ֺ�����޷�ʶ��
	printf("%d\n", atoi("a1234"));//���������ֺ�����޷�ʶ��
	printf("%d\n", atoi("    1234"));//��ͷ�ո��޸�����ʶ�𵫲���ʾ
	printf("%d\n", atoi("12 34"));//���������ֺ�����޷�ʶ��

	return 0;
}
*/