// 
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <string.h>
// 
// typedef struct Note {
// 	int id;
// 	char* name;
// 	char* tel;
// 	struct Note* pNext;
// }List;
// 
// List* GetNote();
// void AddNote(List** ppHead, List** ppEnd, List* pNode);
// int GetID();
// char* GetName();
// char* GetTel();
// void InitInfo(List** ppHead, List** ppEnd, int n);
// 
// int main()
// {
// 	List* pHead = NULL;
// 	List* pEnd = NULL;
// 
// 	InitInfo(&pHead, &pEnd, 101);
// 
// 	while (pHead != NULL)
// 	{
// 		printf("%d  %s  %s\n", pHead->id, pHead->name, pHead->tel);
// 		pHead = pHead->pNext;
// 	}
// 
// 	return 0;
// }
// 
// List* GetNote()
// {
// 	List* pTemp = (List*)malloc(sizeof(List));
// 	if (NULL == pTemp)
// 	{
// 		printf("error\n");
// 		exit(-1);
// 	}//判断是否申请成功
// 	pTemp->id = GetId();
// 	pTemp->name = GetName();
// 	pTemp->tel = GetTel();
// 	pTemp->pNext = NULL;
// 
// 	return pTemp;
// }
// 
// void AddNote(List** ppHead, List** ppEnd, List* pNode)
// {
// 	if (NULL == *ppHead) 
// 	{
// 		*ppHead = pNode;
// 	} 
// 	else
// 	{
// 		(*ppEnd)->pNext = pNode;
// 	}
// 	*ppEnd = pNode;
// }
// 
// int GetId()
// {
// 	static int id = 1;
// 
// 	return id++;
// }
// 
// char* GetName()
// {
// 	char* str = (char*)malloc(6);
// 	int i;
// 
// 	for (i = 0; i < 5; i++)
// 	{
// 		str[i] = rand() % 26 + 'a';
// 	}
// 	str[i] = '\0';
// 
// 	return str;
// }
// 
// char* GetTel()
// {
// 	char* str = (char*)malloc(12);
// 	int i;
// 
// 	switch (rand() % 4)
// 	{
// 	case 0:
// 		str[0] = '1';
// 		str[1] = '3';
// 		str[2] = '3';
// 		break;
// 	case 1:
// 		strcpy_s(str, 12, "155");
// 		break;
// 	case 2:
// 		strcpy_s(str, 12, "177");
// 		break;
// 	case 3:
// 		strcpy_s(str, 12, "188");
// 		break;
// 	}
// 
// 	for (i = 3; i < 11; i++)
// 	{
// 		str[i] = rand() % 10 + '0';
// 	}
// 	str[i] = '\0';
// 
// 	return str;
// }
// 
// void InitInfo(List** ppHead, List** ppEnd, int n)
// {
// 	int i;
// 
// 	srand((unsigned int)time(NULL));
// 	//一般情况下，一个程序只埋一个种子，多个种子可能会导致出现一样的rand
// 
// 	for (i = 0; i < 100; i++)
// 	{
// 		AddNote(ppHead, ppEnd, GetNote());
// 		//如果将	srand((unsigned int)time(NULL));分别写到char* GetName();和char* GetTel();中
// 		//那么每次随机生成name和tel时都会重新设置一次种子，而如果(unsigned int)time(NULL)强制转换后得到的数字和之前的种子里的数一样，那么rand产生的数就会一样。
// 	}
// }
// 

