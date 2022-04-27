#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int nValue;
    struct Node *pLeft;
    struct Node *pRight;
}BinaryTree;

BinaryTree* CreateBinaryTree(){
    //根
    BinaryTree* Root = NULL;
    Root = (BinaryTree*)malloc(sizeof(BinaryTree));
    Root->nValue = 1;
    //根的左
    Root->pLeft = (BinaryTree*)malloc(sizeof(BinaryTree));
    Root->pLeft->nValue = 2;
    //根的右
    Root->pRight = (BinaryTree*)malloc(sizeof(BinaryTree));
    Root->pRight->nValue = 3;
    //根的左的左
    Root->pLeft->pLeft = (BinaryTree*)malloc(sizeof(BinaryTree));
    Root->pLeft->pLeft->nValue = 4;
    Root->pLeft->pLeft->pLeft = NULL;
    Root->pLeft->pLeft->pRight = NULL;
    //根的左的右
    Root->pLeft->pRight = (BinaryTree*)malloc(sizeof(BinaryTree));
    Root->pLeft->pRight->nValue = 5;
    Root->pLeft->pRight->pLeft = NULL;
    Root->pLeft->pRight->pRight = NULL;

    return Root;
}

void PostorderTraversal(BinaryTree *pTree){
    if (pTree == NULL)  return;
    //左子树
    PostorderTraversal(pTree->pLeft);
    //右子树
    PostorderTraversal(pTree->pRight);
    //打印
    printf("%d",pTree->nValue);
}

int main()
{
    BinaryTree*BinaryTree1 = CreateBinaryTree();
    PostorderTraversal(BinaryTree1);
    return 0;
}