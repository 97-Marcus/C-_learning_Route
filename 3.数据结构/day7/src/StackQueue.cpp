#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int nvalue;
    struct node *pNext;
}Date;

typedef struct stack{
    int nConut;
    Date *pTop;
}Stack;

typedef struct queue{
    Stack *pStack1;
    Stack *pStack2;
}Queue;

void Init(Stack **pStack){
    *pStack = (Stack*)malloc(sizeof(Stack));
    (*pStack)->nConut = 0;
    (*pStack)->pTop = NULL;
}

void Push(Stack *pStack,int nNum){
    if (pStack == NULL) {
        printf("stack is not exist!\n");
        exit(1);
    }

    Date *pTemp = NULL;
    pTemp = (Date*)malloc(sizeof(Date));
    pTemp->nvalue = nNum;

    pTemp->pNext = pStack->pTop;
    pStack->pTop = pTemp;
    pStack->nConut++;
}

int Pop(Stack *pStack){
    if (pStack == NULL) {
        printf("stack is not exist!\n");
        exit(1);
    }

    if (pStack->nConut == 0)    
        return -1;

    Date *pDel = NULL;
    pDel = pStack->pTop;
    int nNum = pDel->nvalue;

    pStack->pTop = pStack->pTop->pNext;
    free(pDel);
    pStack->nConut--;
    return nNum;
}

int IsEmpty(Stack *pStack){
    if (pStack == NULL) {
        printf("stack is not exist!\n");
        exit(1);
    }
    return pStack->nConut == 0 ? 1 : 0; 
}

void q_Init(Queue **pQueue){
    *pQueue = (Queue*)malloc(sizeof(Queue));
    Init(&(*pQueue)->pStack1);
    Init(&(*pQueue)->pStack2);
}

void q_Push(Queue *pQueue,int nNum){
    //栈1入队
    //考虑栈2是否非空   如果非空，将栈2元素压入栈1
    while (!IsEmpty(pQueue->pStack2)) {
        Push(pQueue->pStack1,Pop(pQueue->pStack2));
    }
    //新元素入栈1
    Push(pQueue->pStack1,nNum);
}

int q_Pop(Queue *pQueue){
    //栈2出队
    //考虑栈1是否非空   如果非空，将栈1元素依次放入栈2
    while (!IsEmpty(pQueue->pStack1)) {
        Push(pQueue->pStack2,Pop(pQueue->pStack1));
    }
    //将栈2栈顶元素弹出
    int nNum = Pop(pQueue->pStack2);
    return nNum;
}

int main(){
    Queue *pQueue = NULL;
    q_Init(&pQueue);

    q_Push(pQueue, 1);
    q_Push(pQueue, 2);
    q_Push(pQueue, 3);
    q_Push(pQueue, 4);

    printf("%d\n",q_Pop(pQueue));
    printf("%d\n",q_Pop(pQueue));
    q_Push(pQueue, 5);
    q_Push(pQueue, 6);
    printf("%d\n",q_Pop(pQueue));
    printf("%d\n",q_Pop(pQueue));
    printf("%d\n",q_Pop(pQueue));
    printf("%d\n",q_Pop(pQueue));

    return 0;
}