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

List *ReverseList(List *pHead){ //倒置链表
    printf("倒置链表：\n");
    
    //如果函数参数不是地址，而是变量这种，那一定要检测数据是否异常（代码的鲁棒性）
    if (pHead==NULL||pHead->pNext==NULL) {  //不存链表或链表只有一个节点
        return pHead;   //直接返回原来的就行，不用倒置了
    }
    List *p1 = NULL;
    List *p2 = pHead;
    List *p3 = pHead->pNext;

    while (p3 != NULL) {
        //断开 改向
        p2->pNext = p1;
        //移动
        p1 = p2;
        p2 = p3;
        p3 = p3->pNext;
    }
    p2->pNext = p1;
    return p2;
}

int main(){
    List *pHead = NULL;
    CreateList(&pHead);
    Print(pHead);
    pHead = ReverseList(pHead);
    Print(pHead);
    return 0;
}
