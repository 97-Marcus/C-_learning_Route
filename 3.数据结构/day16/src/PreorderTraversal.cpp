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

void PreorderTraversal(BinaryTree *pTree){
    if (pTree == NULL)  return;
    //打印
    printf("%d",pTree->nValue);
    //左子树
    PreorderTraversal(pTree->pLeft);
    //右子树
    PreorderTraversal(pTree->pRight);
}

int main()
{
    BinaryTree*BinaryTree1 = CreateBinaryTree();
    PreorderTraversal(BinaryTree1);
    return 0;
}
