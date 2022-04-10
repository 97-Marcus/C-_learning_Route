////文件（字符形式ASCII 二进制形式）
////缓冲区 int getchar();
//
////写入文件（数据→缓冲区→物理文件）
////读取文件（写入的反向）
////代码只完成数据→缓冲区
//
//#include <stdio.h>
//
//int main() 
//{
//	char buf[1024] = { 0 };//初始化，文件里没有\0，读字符串可以省事
//	size_t n;
//
//	FILE* pFile;
//	fopen_s(&pFile,"C:\\Users\\Nothingserious\\source\\repos\\Kelin 4-28to5-7\\文件\\111.txt", "r+");
//	//FILE *pFile = fopen("路径","打开方式")
//	//fopen不安全，所以使用fopen_s
//	//如果pFile返回值为NULL则打开文件失败；
//	//路径需要补\；路径不要复制，盘符和冒号需要自己打
//
//	//文件操作
//
//	n = fread(buf, 1, 1024, pFile);
//	//记录返回值(写满的次数)，一次一个字节，读缓冲区大小次数，则返回值为成功得到字节数
//	// 	   	n = fread(buf, 1, 1, pFile);   后续的写入部分无法完成
//	//原因：从读到写必须经过文件的末尾，如果没有经过末尾那么需要调用fseek函数(无须波动到某个位置，只要调用即可)
//	//		fseek(pFile,0,SEEK_CUR);
//
//	//当指定 "r +"、 "w +" 或 "a +" 访问类型时，将同时启用读取和写入 (该文件被称为 "更新" ) 。 但是，当你从读取切换到写入时，输入操作必须遇到 EOF 标记。 如果没有 EOF，必须使用对文件定位函数的干预调用。 文件定位函数是 fsetpos 、 fseek 和 rewind 。 当从写入切换到读取时，必须使用对 fflush 或文件定位函数的干预调用。
//
//	printf("%d\n", n);
//	printf("%s\n", buf);
//
//	fwrite("000", 1, 3, pFile);
//	fclose(pFile);
//	//及时关闭
//
//	return 0;
//}




//
////文本文件复制
//
//#include <stdio.h>
//
//int main()
//{
//	FILE* pFile1 = NULL;
//	FILE* pFile2 = NULL;
//	char c;
//
//	fopen_s(&pFile1, "C:\\Users\\Nothingserious\\source\\repos\\Kelin 4-28to5-7\\文件\\111.txt", "r");
//	fopen_s(&pFile2, "C:\\Users\\Nothingserious\\source\\repos\\Kelin 4-28to5-7\\文件\\222.txt", "w");
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




//二进制文件复制

#include <stdio.h>

int main() 
{
	FILE* pFile1 = NULL;
	FILE* pFile2 = NULL;
	char buf[1024] = { 0 };
	size_t read, write;

	fopen_s(&pFile1, "C:\\Users\\Nothingserious\\Pictures\\v2-5ecf812e446581f2814774469226fae0_r.jpg", "rb");
	fopen_s(&pFile2, "C:\\Users\\Nothingserious\\Pictures\\123.jpg", "wb");

	while ((read = fread(buf, 1, 1024, pFile1)) > 0)//返回值为成功的字节数，所以只要能读取就要继续
	{
		write = fwrite(buf, 1, read, pFile2);//读多少写多少 否则最后一次读250写了1024 会导致文件大小不一样 则不是准确复制
		printf("%d %d\n", read, write);
	}

	fclose(pFile1);
	fclose(pFile2);

	return 0;
}