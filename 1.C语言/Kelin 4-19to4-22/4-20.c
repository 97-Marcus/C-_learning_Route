#include < stdio.h >
#include < stdlib.h >

//链表添加

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
	List* pHead = NULL;//一级指针（头指针），存的是头节点的地址
	List* pEnd = NULL;

	//AddNode(pHead, pEnd, GetNode(1, "aa", "111"));
	//AddNode(pHead, pEnd, GetNode(2, "bb", "222"));
	//AddNode(pHead, pEnd, GetNode(3, "cc", "333"));
	//AddNode(pHead, pEnd, GetNode(4, "dd", "444"));

	AddNode(&pHead, &pEnd, GetNode(1, "aa", "111"));//对头节点的地址取地址，也就是二级指针
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
	//给新结点开辟空间，malloc申请来的都在堆区
	pTemp->id = id;
	pTemp->name = name;
	pTemp->tel = tel;
	pTemp->pNext = NULL;

	return pTemp;
}

//void AddNode(List* pHead, List* pEnd, List* pNode)
//该函数中的pHead以及pEnd在该函数结束时就被系统回收了，和主函数当中的pHead和pEnd并非是同一个指针变量
//因此在参数设置时，应该使用该指针的地址而并非该指针

//pHead1 == &pHead               *pHead1 == pHead              **pHead1 == *pHead
//二级指针 == 头指针的地址（传参）    对二级指针间接引用 == 头指针      对头指针间接引用 == 头节点
void AddNode(List** pHead1, List** pEnd1, List* pNode)
{
	//是否有节点
	if (NULL == *pHead1)
	{
		//没有
		//头指针指向新来节点
		*pHead1 = pNode;
	}
	else
	{
		//有
		//尾节点的下一个指向新来的节点
		//pEnd1->pNext = pNode;
		//*pEnd1->pNext = pNode;//优先级出问题了
		(*pEnd1)->pNext = pNode;
	}
	//尾节点指向新来的节点
	*pEnd1 = pNode;
}

*/
