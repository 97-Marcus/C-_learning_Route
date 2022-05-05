#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int nValue;
    struct Node *pLeft;
    struct Node *pRight;
}BinaryTree;

void AddNode(BinaryTree **pTree,int nNum){
    //数值放入节点
    BinaryTree *pTemp = NULL;
    pTemp = (BinaryTree*)malloc(sizeof(BinaryTree));
    pTemp->nValue = nNum;
    pTemp->pLeft = NULL;
    pTemp->pRight = NULL;

    //放入树中
    if(*pTree == NULL){ //当前树空，直接作为根节点
        *pTree = pTemp;
        return;
    }
    BinaryTree *pNode = *pTree;
    while (pNode) {
        if (pNode->nValue > nNum) {
            if (pNode->pLeft == NULL) {
                pNode->pLeft = pTemp;
                return;
            }
            pNode = pNode->pLeft;
        }else if (pNode->nValue < nNum) {
            if (pNode->pRight == NULL) {
                pNode->pRight = pTemp;
                return;
            }
            pNode = pNode->pRight;
        }else {
            printf("date error.\n");
            free(pTemp);
            pTemp = NULL;
            return;
        }
    }
}

BinaryTree *CreateBST(){
    int nNum;
    int nLength;
    int i;

    BinaryTree *pTree = NULL;
    printf("请输入节点个数：\n");
    scanf("%d",&nLength);

    for (i = 0; i < nLength; i++) {
        scanf("%d",&nNum);
        //节点添加
        AddNode(&pTree,nNum);
    }
    return pTree;
}

void BstToList(BinaryTree *pTree,BinaryTree **pHead,BinaryTree **pTail){
    if (pTree == NULL) return;  //空的话就不需要处理了
    //处理左子树
    BstToList(pTree->pLeft, pHead, pTail);
    //处理节点  加到链表中  
    if (*pHead == NULL) {   //链表为空 直接做表头
        *pHead = pTree;
    }
    else{   //链表不为空  原来尾的下一个（Right）就是当前节点，当前节点的前一个就是原来的尾
        (*pTail)->pRight = pTree;
        pTree->pLeft = *pTail;
    }
    *pTail = pTree; //新来节点成为新的尾
    //处理右子树
    BstToList(pTree->pRight, pHead, pTail);
}

void Print(BinaryTree *pHead){
    while (pHead) {
        printf("%d  ",pHead->nValue);
        pHead = pHead->pRight;
    }
}

int main(){
    BinaryTree *pTree = CreateBST();
    BinaryTree *pHead = NULL;
    BinaryTree *pTail = NULL;
    BstToList(pTree, &pHead, &pTail);
    Print(pHead);
    return 0;
}