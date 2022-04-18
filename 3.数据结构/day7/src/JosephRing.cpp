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

int JosephRing(int n,int k){
    //辅助队列
    ListQueue * pQueue = NULL;
    Init(&pQueue);

    //计数器
    int nCount = 0;

    //入队
    int i = 1;
    while (i <= n) {
        Push(pQueue, i);
        i++;
    }

    //出环
    while (pQueue->nCount > 1) {
        //弹出 计数
        i = Pop(pQueue);
        nCount++;
        //是否满足出环条件
        //满足则计数器置为0，无需重新入队 
        if (nCount == k) {
            nCount = 0;
            continue;
        }else { //不满足，元素重新入队
            Push(pQueue, i);
        }
    }
    i = Pop(pQueue);
    return i;
}

int main()
{
    int nResult = JosephRing(5, 3);
    printf("%d\n",nResult);
    return 0;
} 