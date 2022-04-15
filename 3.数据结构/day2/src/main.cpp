#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int nValue;
    struct node *pNext;
}List;

void CreateList(List **pHead){
    //辅助变量
    List *pTemp = NULL;
    List *pTail = NULL;

    int nlenth;
    printf("请输入链表初始长度：\n");
    scanf("%d",&nlenth);

    int nNum;
    while(nlenth){
        printf("请输入值：\n");
        scanf("%d",&nNum);

        //临时节点
        pTemp = (List*)malloc(sizeof(List));
        pTemp->nValue = nNum;
        pTemp->pNext = NULL;

        //添加
        if (*pHead == NULL) {   //链表为空的情况
            *pHead = pTemp;
        }else {                 //链表不为空的情况
            pTail->pNext = pTemp;
        }
        pTail = pTemp;
        nlenth--;
    }
}

void Print(List* pHead){
    while (pHead) {
        printf("%d  ",pHead->nValue);
        pHead = pHead->pNext;
    }
    printf("\n");
}

int main(){
    List *pHead = NULL;
    CreateList(&pHead);
    Print(pHead);
    
    return 0;
}
