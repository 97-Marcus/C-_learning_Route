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

typedef struct stack{
    ListQueue *pQueue1;
    ListQueue *pQueue2;
}Stack;

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

int Pop(ListQueue *pListQueue){
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

void s_Init(Stack **pStack){
    *pStack = (Stack*)malloc(sizeof(Stack));
    Init(&(*pStack)->pQueue1);
    Init(&(*pStack)->pQueue2);
}

void s_Push(Stack *pStack,int nNum){
    if (pStack->pQueue1->nCount == 0) {
        Push(pStack->pQueue2, nNum);
    }else {
        Push(pStack->pQueue1, nNum);
    }
}

int s_Pop(Stack *pStack){
    if (pStack->pQueue1->nCount == 0 && pStack->pQueue2->nCount == 0) 
        return -1;
    int nNum;
    if (pStack->pQueue1->nCount != 0) {
        //将队1内元素除了尾以外 都压入另一个队列
        while (pStack->pQueue1->nCount > 1) {
            Push(pStack->pQueue2, Pop(pStack->pQueue1));
        }
        nNum = Pop(pStack->pQueue1);
    }
    else {
        while(pStack->pQueue2->nCount > 1){
            Push(pStack->pQueue1, Pop(pStack->pQueue2));
        }
        nNum = Pop(pStack->pQueue2);
    }
    return nNum;
}

int main(){
    Stack *pStack = NULL;
    s_Init(&pStack);

    s_Push(pStack, 1);
    s_Push(pStack, 2);
    s_Push(pStack, 3);
    s_Push(pStack, 4);

    printf("%d\n",s_Pop(pStack));
    printf("%d\n",s_Pop(pStack));
    printf("%d\n",s_Pop(pStack));
    printf("%d\n",s_Pop(pStack));

    return 0;
}