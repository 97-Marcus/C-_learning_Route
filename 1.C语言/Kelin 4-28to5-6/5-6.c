////�ļ����ַ���ʽASCII ��������ʽ��
////������ int getchar();
//
////д���ļ������ݡ��������������ļ���
////��ȡ�ļ���д��ķ���
////����ֻ������ݡ�������
//
//#include <stdio.h>
//
//int main() 
//{
//	char buf[1024] = { 0 };//��ʼ�����ļ���û��\0�����ַ�������ʡ��
//	size_t n;
//
//	FILE* pFile;
//	fopen_s(&pFile,"C:\\Users\\Nothingserious\\source\\repos\\Kelin 4-28to5-7\\�ļ�\\111.txt", "r+");
//	//FILE *pFile = fopen("·��","�򿪷�ʽ")
//	//fopen����ȫ������ʹ��fopen_s
//	//���pFile����ֵΪNULL����ļ�ʧ�ܣ�
//	//·����Ҫ��\��·����Ҫ���ƣ��̷���ð����Ҫ�Լ���
//
//	//�ļ�����
//
//	n = fread(buf, 1, 1024, pFile);
//	//��¼����ֵ(д���Ĵ���)��һ��һ���ֽڣ�����������С�������򷵻�ֵΪ�ɹ��õ��ֽ���
//	// 	   	n = fread(buf, 1, 1, pFile);   ������д�벿���޷����
//	//ԭ�򣺴Ӷ���д���뾭���ļ���ĩβ�����û�о���ĩβ��ô��Ҫ����fseek����(���벨����ĳ��λ�ã�ֻҪ���ü���)
//	//		fseek(pFile,0,SEEK_CUR);
//
//	//��ָ�� "r +"�� "w +" �� "a +" ��������ʱ����ͬʱ���ö�ȡ��д�� (���ļ�����Ϊ "����" ) �� ���ǣ�����Ӷ�ȡ�л���д��ʱ����������������� EOF ��ǡ� ���û�� EOF������ʹ�ö��ļ���λ�����ĸ�Ԥ���á� �ļ���λ������ fsetpos �� fseek �� rewind �� ����д���л�����ȡʱ������ʹ�ö� fflush ���ļ���λ�����ĸ�Ԥ���á�
//
//	printf("%d\n", n);
//	printf("%s\n", buf);
//
//	fwrite("000", 1, 3, pFile);
//	fclose(pFile);
//	//��ʱ�ر�
//
//	return 0;
//}




//
////�ı��ļ�����
//
//#include <stdio.h>
//
//int main()
//{
//	FILE* pFile1 = NULL;
//	FILE* pFile2 = NULL;
//	char c;
//
//	fopen_s(&pFile1, "C:\\Users\\Nothingserious\\source\\repos\\Kelin 4-28to5-7\\�ļ�\\111.txt", "r");
//	fopen_s(&pFile2, "C:\\Users\\Nothingserious\\source\\repos\\Kelin 4-28to5-7\\�ļ�\\222.txt", "w");
//
//	while ((c = fgetc(pFile1)) != EOF) {
//		fputc(c, pFile2);
//	}
//
//	fclose(pFile1);
//	fclose(pFile2);
//
//	return 0;
//}




//�������ļ�����

#include <stdio.h>

int main() 
{
	FILE* pFile1 = NULL;
	FILE* pFile2 = NULL;
	char buf[1024] = { 0 };
	size_t read, write;

	fopen_s(&pFile1, "C:\\Users\\Nothingserious\\Pictures\\v2-5ecf812e446581f2814774469226fae0_r.jpg", "rb");
	fopen_s(&pFile2, "C:\\Users\\Nothingserious\\Pictures\\123.jpg", "wb");

	while ((read = fread(buf, 1, 1024, pFile1)) > 0)//����ֵΪ�ɹ����ֽ���������ֻҪ�ܶ�ȡ��Ҫ����
	{
		write = fwrite(buf, 1, read, pFile2);//������д���� �������һ�ζ�250д��1024 �ᵼ���ļ���С��һ�� ����׼ȷ����
		printf("%d %d\n", read, write);
	}

	fclose(pFile1);
	fclose(pFile2);

	return 0;
}