#include < stdio.h >
#include < string.h >

//�ַ�������'\0'��β���ַ�����

/*
int main() 
{
	char str[5] = { 'a','b','c','d','\0' };//'\0'���ᱻ���
	//char str[5] = { 'a','b','c','d','0' };
	//'\0'�����ڡ�0������ASCII�С�\0�� == 0,'0' == 48
	//char str[5] = { 'a','b','c','d','e' };
	//û����\0��β����������
	//char str[5] = { 'a','b','c','d'};
	//������û�б������λ���Զ���Ϊ0��Ҳ���൱�ڡ�\0��,��˿������abcd

	char str1[] = "abcde"; //��ջ������һ���ַ����飬Ȼ���ַ��������е��ַ���������ջ�����ַ�������
	//��ʱ��������������ַ� �ֱ���abcde��\0
	//������˫���ų��ֵ��ַ��������洢���ַ�������
	//��abcde������a�ĵ�ַ�����ó���xxx��������ַ������ַ��������洢�ռ���Ԫ�صĵ�ַ

	char* str2 = "abcde";//��ָ�����ַ�������

	printf("%d\n", sizeof(str1));	
	printf("%d\n", sizeof(str2));
	//str1��str2��С��һ����1���ַ������飬����������Ԫ�أ��ַ������ȣ�������2��ָ�룬ָ���С�ɳ���λ������

	//�޸ĵĲ�ͬ
	  str1[1] = 'B';
	//str2[1] = 'B';//��ָ�����ַ������������������Բ������޸�
				  //str1�����޸ĵ�ԭ���ǣ�����������ջ�����ַ�������
	printf("%s\n", str);
	printf("%s\n", str1);

	printf("%d\n", strlen(str));//strlen�Ǽ����ַ������ȵģ�����\0
	printf("%d\n", sizeof(str));//sizeof�Ǽ����С�ģ�����\0Ҳռ�ÿռ䣬����Ҫ��


	return 0;
}
*/



//strlen�����ķ�д
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
	
	//֪������ʱ��for����֪��������ʱ����while
	//while (str!='\0')
	//Ӧ�����ַ�����������ݺ�\0�Ƚ�,������str��ָ�룩ȥ���бȽ�,��ַ�����ܵ���\0��������Ҫ�������

	while (*str!='\0')
	{
		count++;
		str++;
	}//�����ַ�������·~
	
	//��*str='\0'ʱ�Ͳ�����ѭ�������ˣ���˻�����ѭ������ִ��while�е����飬����count����+1��
	//���㳤��ʱ��\0���������ڣ����Է���count���ɡ�

	return count;
}
*/



//strcpy(Ŀ�꣬Դ)	����ֵ��Ŀ����׵�ַ��û�з���ֵ����󣬷��ؿ�NULL
/*
int main()
{
	char str1[10];
	char str2[] = "abcd";
	strcpy_s(str1, sizeof(str1), str2);
	printf("%s\n", str1);
	//�����ַ���,strcpy����ȫ����Ҫ��strcpy_s���滻
	//����ȫ����Ϊ���Ŀ��Ŀռ�Ƚ�С���߱Ƚϴ���ô��ջ�����������
	//strcpy_s(Ŀ�꣬Ŀ��Ĵ�С��Դ)	
	//����ֵ��int������ɹ�����0�����ʧ�ܷ��ط�0ֵ����ֵͬ��ʾ��ͬ�Ĵ�����Ҫ�����ֲ�
	return 0;
}
*/


//��дsyrcpy
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
	//str2��\0��û�и��ƹ�ȥ������str1�������ַ�����������Ҫ�ٸ�ֵ\0
	*str1 = '\0';
	//return str1;//�����ԭ����str1�ڳ����н�����++�������Ѿ�������Ԫ�صĵ�ַ�ˣ�������Ҫ����ǰ���ȼ�¼��Ԫ�ص�ַ
	return pmark;
}
*/


//strncpy��Ŀ�꣬Դ��Ҫ���ƶ೤��	���ָ���
//ע�⣬Ҳ����ȫ����Ҫ����Ϊstrncpy_s
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
