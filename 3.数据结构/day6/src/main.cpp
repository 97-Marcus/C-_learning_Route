#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

typedef struct date{
    int nValue;
    struct date *pNext;
}Date;

typedef struct queue{
    int nCount;
    Date *pHead;
    Date *pTail;
}ListQueue;

void Init(ListQueue **pListQueue){
    *pListQueue = (ListQueue*)malloc(sizeof(ListQueue));
    (*pListQueue)->nCount = 0;
    (*pListQueue)->pHead = NULL;
    (*pListQueue)->pTail = NULL;
}

void Push(ListQueue *pListQueue,int nNum){
    if (pListQueue == NULL) {
        printf("queue is not exist.\n");
        exit(1);
    }
    Date *pTemp = NULL;
    pTemp = (Date*)malloc(sizeof(Date));
    pTemp->nValue = nNum;
    pTemp->pNext = NULL;

    if (pListQueue->pHead == NULL) {
        pListQueue->pHead = pTemp;
    }else {
        pListQueue->pTail->pNext = pTemp;
    }
    pListQueue->pTail = pTemp;
    pListQueue->nCount++;
}

int Pop(ListQueue * pListQueue){
    if (pListQueue == NULL) {
        printf("queue is not exist.\n");
        exit(1);
    }
    if (pListQueue->nCount == 0)
        return -1;
    //标记
    Date *pDel = pListQueue->pHead;
    int nNum = pDel->nValue;
    //移动
    pListQueue->pHead = pListQueue->pHead->pNext;
    free(pDel);
    pDel = NULL;
    pListQueue->nCount--;

    if (pListQueue->nCount == 0) {
        pListQueue->pTail = NULL;
    }

    return nNum;
}

int IsEmpty(ListQueue *pListQueue){
    if (pListQueue == NULL) {
        printf("queue is not exist.\n");
        exit(1);
    }
    return pListQueue->nCount == 0? 1: 0;
}

int main()
{
    ListQueue *pListQueue = NULL;
    Init(&pListQueue);

    Push(pListQueue, 1);
    Push(pListQueue, 2);
    Push(pListQueue, 3);
    Push(pListQueue, 4);
    printf("%d\n",IsEmpty(pListQueue));

    printf("%d\n",Pop(pListQueue));
    printf("%d\n",Pop(pListQueue));
    printf("%d\n",Pop(pListQueue));
    printf("%d\n",Pop(pListQueue));
    printf("%d\n",IsEmpty(pListQueue));

    return 0;
}
