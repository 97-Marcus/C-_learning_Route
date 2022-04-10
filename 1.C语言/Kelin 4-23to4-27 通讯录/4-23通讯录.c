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
// 	}//�ж��Ƿ�����ɹ�
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
// 	//һ������£�һ������ֻ��һ�����ӣ�������ӿ��ܻᵼ�³���һ����rand
// 
// 	for (i = 0; i < 100; i++)
// 	{
// 		AddNote(ppHead, ppEnd, GetNote());
// 		//�����	srand((unsigned int)time(NULL));�ֱ�д��char* GetName();��char* GetTel();��
// 		//��ôÿ���������name��telʱ������������һ�����ӣ������(unsigned int)time(NULL)ǿ��ת����õ������ֺ�֮ǰ�����������һ������ôrand���������ͻ�һ����
// 	}
// }
// 

