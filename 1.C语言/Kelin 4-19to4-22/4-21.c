#include <stdio.h>
#include <stdlib.h>

//链表插入

 //typedef struct Node
 //{
 //	int id;
 //	struct Node* pNext;
 //}List;
 //
 //void AddNode(List** ppHead, List** ppEnd, int id);
 //void InsertNode(List** ppHead, List** ppEnd, List* pNode, int id);
 //
 //int main()
 //{
 //	List* pHead = NULL;
 //	List* pEnd = NULL;
 //	List a = { 6,NULL };
 //
 //	AddNode(&pHead, &pEnd, 1);
 //	AddNode(&pHead, &pEnd, 2);
 //	AddNode(&pHead, &pEnd, 3);
 //	AddNode(&pHead, &pEnd, 4);
 //
 //	InsertNode(&pHead, &pEnd, &a, 5);
 //
 //	while (pHead != NULL)
 //	{
 //		printf("%d\n", pHead->id);
 //		pHead = pHead->pNext;
 //	}
 //
 //	return 0;
 //}
 //
 //void AddNode(List** ppHead, List** ppEnd, int id)
 //{
 //	List* pTemp = (List*)malloc(sizeof(List));
 //	pTemp->id = id;
 //	pTemp->pNext = NULL;
 //
 //	if (NULL == *ppHead)
 //	{
 //		*ppHead = pTemp;
 //	}
 //	else
 //	{
 //		(*ppEnd)->pNext = pTemp;
 //	}
 //	*ppEnd = pTemp;
 //}
 //
 //void InsertNode(List** ppHead, List** ppEnd, List* pNode, int id)
 //{
 //	List* pMark = *ppHead;
 ///*从某种意义上来说，因为已经判断过头插入，且本指针是为了中间插入而定义的，所以猜测可以定义为头结点的下一个，这是有一定道理的，但问题在于判断中间插入时，我们需要找到的是插入位置的前一个节点，那么如果定义为头节点的下一个，那么当我们需要在第二个节点前插入时，我们就无法得到第二个节点的前一个，也就是头节点了*/
 //
 //	//1.头插入   (如果给id赋值为头结点id的内容，那么此时if内条件返回为真，也就能判断出这是头插入-)
 //	if ((*ppHead)->id == id)
 //	{
 //		//新来节点的下一个指向头节点
 //		//如果链表中现在没有节点，这是唯一一个节点，那么新节点的指针域存放NULL没有问题，也就是说可以写成	pNode->pNext = NULL;但如果链表中现在有节点，且要求把新节点插入到最前面，那么新节点的指针域就应该指向原来的头指针（也就是标记着指向头节点的指针）
 //		pNode->pNext = *ppHead;
 //		//头指针指向新来的节点
 //		//如果这是唯一一个节点，那么头指针和尾指针都指向该节点，如果这是插入到第一个节点之前的节点，那么头指针就应该指向这个新的节点
 //		*ppHead = pNode;
 //		return;
 //	}
 //
 //	//中间插入 
 //	//遍历链表
 //	//while (pMark != NULL)
 //	/*如果循环条件为pMark != NULL，那么当pMark为4号节点时，pMark->pNext是不存在的，那么也就不存在pMark->pNext->id，所以出现了bug*/
 //	//正确循环条件如下所示：
 //	while (pMark->pNext != NULL)
 //	{
 //		//让标记停在插入位置的前一个节点上
 //		if (pMark->pNext->id == id)
 //		{
 //			//新来节点的下一个指向标记的下一个
 //			//新来节点的指针域放标记节点的指针域，也就是标记的下一个结点的地址
 //			pNode->pNext = pMark->pNext;
 //			//标记的下一个指向新来节点
 //			//标记节点的指针域放新来节点的地址
 //			pMark->pNext = pNode;
 //			return;
 //		}
 //		pMark = pMark->pNext;
 //	}
 //
 //	//尾插入
 //	(*ppEnd)->pNext = pNode;
 //	//尾节点的下一个指向新来节点//当下尾节点的指针域放新来节点的地址
 //	*ppEnd = pNode;
 //	//因为可能后续还需要将新结点插入到链表的尾部，所以需要尾指针，也就是本函数中的ppEnd，用来始终指向链表的尾节点，以便能够将新结点插入到链表的尾部。
 //	//因此本句意思为尾指针指向新来节点以作为尾节点
 //}
