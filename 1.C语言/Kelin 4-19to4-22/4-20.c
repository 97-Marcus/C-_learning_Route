#include < stdio.h >
#include < stdlib.h >

//�������

/*
typedef struct Node
{
	int id;
	char* name;
	char* tel;
	struct Node* pNext;
}List;

List* GetNode(int id, char* name, char* tel);
//void AddNode(List* pHead, List* pEnd, List* pNode);
void AddNode(List** pHead1, List** pEnd1, List* pNode);

int main()
{
	List* pHead = NULL;//һ��ָ�루ͷָ�룩�������ͷ�ڵ�ĵ�ַ
	List* pEnd = NULL;

	//AddNode(pHead, pEnd, GetNode(1, "aa", "111"));
	//AddNode(pHead, pEnd, GetNode(2, "bb", "222"));
	//AddNode(pHead, pEnd, GetNode(3, "cc", "333"));
	//AddNode(pHead, pEnd, GetNode(4, "dd", "444"));

	AddNode(&pHead, &pEnd, GetNode(1, "aa", "111"));//��ͷ�ڵ�ĵ�ַȡ��ַ��Ҳ���Ƕ���ָ��
	AddNode(&pHead, &pEnd, GetNode(2, "bb", "222"));
	AddNode(&pHead, &pEnd, GetNode(3, "cc", "333"));
	AddNode(&pHead, &pEnd, GetNode(4, "dd", "444"));

	while (pHead != NULL)
	{
		printf("%d  %s  %s\n", pHead->id, pHead->name, pHead->tel);
		pHead = pHead->pNext;
	}

	return 0;
}

List* GetNode(int id, char* name, char* tel)
{
	List* pTemp = (List*)malloc(sizeof(List));
	//���½�㿪�ٿռ䣬malloc�������Ķ��ڶ���
	pTemp->id = id;
	pTemp->name = name;
	pTemp->tel = tel;
	pTemp->pNext = NULL;

	return pTemp;
}

//void AddNode(List* pHead, List* pEnd, List* pNode)
//�ú����е�pHead�Լ�pEnd�ڸú�������ʱ�ͱ�ϵͳ�����ˣ������������е�pHead��pEnd������ͬһ��ָ�����
//����ڲ�������ʱ��Ӧ��ʹ�ø�ָ��ĵ�ַ�����Ǹ�ָ��

//pHead1 == &pHead               *pHead1 == pHead              **pHead1 == *pHead
//����ָ�� == ͷָ��ĵ�ַ�����Σ�    �Զ���ָ�������� == ͷָ��      ��ͷָ�������� == ͷ�ڵ�
void AddNode(List** pHead1, List** pEnd1, List* pNode)
{
	//�Ƿ��нڵ�
	if (NULL == *pHead1)
	{
		//û��
		//ͷָ��ָ�������ڵ�
		*pHead1 = pNode;
	}
	else
	{
		//��
		//β�ڵ����һ��ָ�������Ľڵ�
		//pEnd1->pNext = pNode;
		//*pEnd1->pNext = pNode;//���ȼ���������
		(*pEnd1)->pNext = pNode;
	}
	//β�ڵ�ָ�������Ľڵ�
	*pEnd1 = pNode;
}

*/
