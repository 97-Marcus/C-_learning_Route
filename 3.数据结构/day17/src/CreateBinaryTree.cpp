#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int nValue;
    struct Node *pLeft;
    struct Node *pRight;
}BinaryTree; 

//通过形参修改实参 创建数要修改根结点 所以地址传递
void CreateBinaryTree(BinaryTree **pTree){
    int nNum;
    scanf("%d",&nNum);
    if (nNum == -1) return; //设置特殊标志
    //节点添加
    *pTree = (BinaryTree*)malloc(sizeof(BinaryTree));
    (*pTree)->nValue = nNum;
    (*pTree)->pLeft = NULL;
    (*pTree)->pRight = NULL;
    //左子树
    CreateBinaryTree(&( (*pTree)->pLeft) );
    //右子树
    CreateBinaryTree(&( (*pTree)->pRight) );
}

void PreorderTraversal(BinaryTree *pTree){
    if (pTree == NULL)  return;
    printf("%d",pTree->nValue);
    PreorderTraversal(pTree->pLeft);
    PreorderTraversal(pTree->pRight);
}

int main()
{
    BinaryTree *pTree = NULL;
    CreateBinaryTree(&pTree);
    PreorderTraversal(pTree);
    return 0;
}