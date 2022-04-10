#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//链表删除

/*

typedef struct Node {
	int id;
	struct Node* pNext;
}List;

void AddNote(List** pHead1, List** pEnd1, int id);
void DeleteNote(List** pHead1, List** pEnd1, int id);

int main() 
{
	List* pHead = NULL;
	List* pEnd = NULL;

	AddNote(&pHead, &pEnd, 1);
	AddNote(&pHead, &pEnd, 2);
	AddNote(&pHead, &pEnd, 3);
	AddNote(&pHead, &pEnd, 4);

	DeleteNote(&pHead, &pEnd, 4);

	while (pHead != NULL) 
	{
		printf("%d\n", pHead->id);
		pHead = pHead->pNext;//①
	}

	return 0;
}

void AddNote(List** pHead1, List** pEnd1, int id) 
{
	List* pTemp = (List*)malloc(sizeof(List));

	pTemp->id = id;
	pTemp->pNext = NULL;
	//不进行赋空的话，那么有值，在遍历时无法结束，在pHead=pNext!=NULL时会出问题①

	if (NULL == *pHead1)
	{
		*pHead1 = pTemp;
	}
	else
	{
		(*pEnd1)->pNext = pTemp;
	}
	*pEnd1 = pTemp;
}


void DeleteNote(List** pHead1, List** pEnd1, int id) 
{
	List* pDelete = NULL;
	List* pMark = *pHead1;

	//头删除
		//直接删除头节点的话，2号节点找不到。
		//但是头指针先指向2号节点再删除头节点的话，单向链表是找不到头节点的，所以需要一个删除标记。
	if ((*pHead1)->id == id)
	{
		//删除标记指向头节点
		pDelete = *pHead1;
		//头指针指向头节点的下一个
		*pHead1 = (*pHead1)->pNext;
		//释放删除标记
		free(pHead1);
		pHead1 = NULL;
		//释放了以后这个指针不在这个程序里，但这个指针及其内容依然存在，要赋空才可以完全消除影响
		return;//结束程序
	}

	//中间删除
	while (pMark->pNext != NULL) 		//遍历链表
	{
		//遍历标记停在删除节点的前一个节点上
		if (pMark->pNext->id == id) 
		{
			//删除标记指向遍历标记的下一个
			pDelete = pMark->pNext;
			//遍历标记的下一个指向遍历标记的下一个的下一个
			pMark->pNext = pMark->pNext->pNext;
			//释放删除标记
			free(pDelete);
			pDelete = NULL;
			//判断删除的是否是尾节点
			if (pMark->pNext == NULL) 
			{
				*pEnd1 = pMark;
			}
			//尾删除
			//中间删除可以删除尾节点，但是尾指针依然指向删除的节点，所以需要加一条判断其是否为尾节点
		    //看标记的下一个是NULL还是非空即可，如果NULL则是尾节点，那么让尾指针指向标记节点即可
			return;
		}
		pMark = pMark->pNext;
	}	
}
*/




//随机数 int rand (void);
//实际上，rand() 函数产生的随机数是伪随机数，是根据一个数值按照某个公式推算出来的，这个数值我们称之为“种子”.
//种子在每次启动计算机时是随机的，但是一旦计算机启动以后它就不再变化了；
//也就是说，每次启动计算机以后，种子就是定值了，所以根据公式推算出来的结果（也就是生成的随机数）就是固定的。
//我们可以通过 srand() 函数来重新“播种”:void srand (unsigned int seed);
//在实际开发中，可以用时间作为参数，只要每次播种的时间不同，那么生成的种子就不同，最终的随机数也就不同。
//使用 <time.h> 头文件中的 time() 函数即可得到当前的时间（精确到秒），就像下面这样：
//srand((unsigned)time(NULL));

/*
 
int main()
{
	
	//printf("%d\n",time(NULL)/60/60/24/365);

	srand((unsigned int)time(NULL));

	printf("%d\n",rand() % 10);			//0-9
	printf("%d\n",rand() %10 + 11);		//11-20 - 11    0 - 9
	printf("%d\n",rand() % 6 + 12);		//12-17   - 12   0 - 5
	printf("%d\n",rand());

	//如果要规定上下限：比如：int a = rand() % 51 + 13;    //产生13~63的随机数
    //取模即取余，rand()%51是产生 0~50 的随机数，后面+13保证 a 最小只能是 13，最大就是 50+13=63。

	//也就是说想要设范围区间为（max，min），那么只需 rand%(max-min+1)+min 即可。
	
	return 0;
}

*/