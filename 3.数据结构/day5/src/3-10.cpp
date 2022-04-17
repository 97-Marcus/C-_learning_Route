
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

void Clear(Stack *pStack){
    if (pStack == NULL || pStack->nConut == 0)
        return;

    while (pStack->nConut != 0) {
        Pop(pStack);
    }
}

void Destory(Stack **pStack){
    Clear(*pStack);
    free(*pStack);
    *pStack = NULL;
}

int GetTop(Stack *pStack){
    if (pStack == NULL || pStack->nConut == 0) {
        printf("stack is not exist or stack is empty!\n");
        exit(1);
    }
    return pStack->pTop->nvalue;
}

int GetCount(Stack *pStack){
    if (pStack == NULL) {
        printf("stack is not exist!\n");
        exit(1);
    }
    return pStack->nConut;
}

int IsEmpty(Stack *pStack){
    if (pStack == NULL) {
        printf("stack is not exist!\n");
        exit(1);
    }
    return pStack->nConut == 0 ? 1 : 0; //三目运算符
        // 0 ? 1 : 0
        //如果是0(空)则返回true(1)，否则返回false(0)
}

int main()
{
    Stack *pStack = NULL;

    Init(&pStack);
    Push(pStack, 1);
    Push(pStack, 2);
    Push(pStack, 3);
    Push(pStack, 4);

    printf("%d\n",GetCount(pStack));
    printf("%d\n",GetTop(pStack)); 

    printf("%d\n",Pop(pStack));
    printf("%d\n",Pop(pStack));
    printf("%d\n",Pop(pStack));
    printf("%d\n",Pop(pStack));

    printf("%d\n",IsEmpty(pStack));
    Destory(&pStack);
    Push(pStack, 100);

    return 0;
}