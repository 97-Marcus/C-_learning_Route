/* 

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int nvalue;
    struct node *pNext;
}ListStack;

void Push(ListStack **pTop,int nvalue){
    //新元素申请空间
    ListStack *pTemp = NULL;
    pTemp = (ListStack*) malloc(sizeof(ListStack));
    pTemp->nvalue = nvalue;
    pTemp->pNext = NULL;

    //头增加
    pTemp->pNext = *pTop;
    *pTop = pTemp;
}

int Pop(ListStack **pTop){
    if (*pTop == NULL) {
        printf("stack is empty~\n");
        exit(1);    //结束所在进程
    }

    //标记
    ListStack *pDel = *pTop;
    int nNum = pDel->nvalue;

    //头弹出
    *pTop = (*pTop)->pNext;
    free(pDel);
    pDel = NULL;
    return nNum;
}

int main()
{
    ListStack *pTop = NULL;
    Push(&pTop, 1);
    Push(&pTop, 2);
    Push(&pTop, 3);
    Push(&pTop, 4);

    printf("%d\n",Pop(&pTop));
    printf("%d\n",Pop(&pTop));
    printf("%d\n",Pop(&pTop));
    printf("%d\n",Pop(&pTop));

    return 0;
}
 
 */