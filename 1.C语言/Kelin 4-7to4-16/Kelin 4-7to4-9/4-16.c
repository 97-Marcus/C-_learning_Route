#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//�ַ�����ϰ��

//6.��ת�ַ���
//7.�ж��Ƿ����(����ָ����˳���������һ�����ַ���)  "abcdcba"

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
	//�����ַ�����Զ�ȡһλ
	//����abc\0��ʵ������Ҫ��ȡ��λ������\0Ҳ�ᱻ��ȡ������������abʱֻ�ܶ�ȡa

	return 0;
}
*/



//Ҫ��δ֪����λ������£���Ҫ���������ݻ��Գ���
/*
int main() 
{
	//while (getchar() != '\n')
	//{
	//	printf("%c", getchar());
	//}

	//��12345\nΪ��,���24���޷���������
	//getchar() != '\n'��getchar�õ�135,printf("%c", getchar())��getchar()�õ�24\n
	//��1234\0Ϊ�������24����Խ�������
	//getchar() != '\n'��getchar�õ�13\n,printf("%c", getchar())��getchar()�õ�24

	//getchar()ÿ�ζ�ȡһ���ַ��������Ƿ������������


	char c;
	//while (c = getchar() != '\n')
	//!=�����ȼ���=�ߣ������ִ��getchar() != '\n'������Ҳ����1
	//����c��char�ͣ���ŵ���1������ʾ������

	while ((c = getchar()) != '\n')
	{
		printf("%c", c);
	}
	return 0;
}
*/



//�ݴ��û������һ���ַ����Ա�����ʱȡ��
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

	//�����뻺������ȡ�ַ�
	while ((c = getchar()) != '\n')
	{
		//ȡ�µ��ַ��ŵ��ַ�������
		*str = c;
		//�����ۼ�
		count++;
		str++;
		//�ж��Ƿ��ܷ���
		if (count + 1 == size)
		{
			//�Ų���
			//���ַ���
			*str = '\0';
			//size����
			size += 5;
			//����һ���µĿռ�
			newstr = (char*)malloc(size);
			//�����ַ������������ַ�������
			strcpy_s(newstr, size, pMark);
			//�ͷ����ַ���
			free(pMark);
			//�ҵ����ַ�����βλ��
			str = newstr + count;
			//���ָ���ַ����׵�ַ
			pMark = newstr;
		}
	}
	//���ַ���
	*str = '\0';

	return pMark;
}

*/

/*
����һ��char�����ַ������룩
��malloc�����ڶ�������һ���µĿռ���ַ���
����һ��char* ����ָ�����ַ����׵�ַ
����һ��char* �����ַ���Ϊ��
����һ��int���ͱ�������

whileѭ�����������ַ�c�����ڡ�\n��ʱ
�ַ�c��ֵ����malloc������ַ�����
�ַ�����ַ����
����
����ͳ�ƴ��� + 1�����ڿ��ٿռ��Сʱ
���ַ�������\0��
����ռ�
�����ַ������������Ŀռ�
����strcpy������ԭ���ַ��������ָ����ָ�����ݴ浽�µ��ַ�����
�ͷ�ԭ�ַ����Ŀռ�
���ָ��ָ�����ַ������׵�ַ
���Ϊ�ַ�������\0��
���� ���ָ���׵�ַ
*/ 