#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int nValue;
    struct Node *pLeft;
    struct Node *pRight;
    struct Node *pFather;
}BinaryTree;

BinaryTree *pTree = NULL;

BinaryTree* CreateBinaryTree(){
    //根
    BinaryTree* Root = NULL;
    Root = (BinaryTree*)malloc(sizeof(BinaryTree));
    Root->nValue = 1;
    Root->pFather = NULL;
    //根的左
    Root->pLeft = (BinaryTree*)malloc(sizeof(BinaryTree));
    Root->pLeft->nValue = 2;
    Root->pLeft->pFather = Root;
    //根的右
    Root->pRight = (BinaryTree*)malloc(sizeof(BinaryTree));
    Root->pRight->nValue = 3;
    Root->pRight->pFather = Root;
    //根的左的左
    Root->pLeft->pLeft = (BinaryTree*)malloc(sizeof(BinaryTree));
    Root->pLeft->pLeft->nValue = 4;
    Root->pLeft->pLeft->pLeft = NULL;
    Root->pLeft->pLeft->pRight = NULL;
    Root->pLeft->pLeft->pFather = Root->pLeft;
    //根的左的右
    Root->pLeft->pRight = (BinaryTree*)malloc(sizeof(BinaryTree));
    Root->pLeft->pRight->nValue = 5;
    Root->pLeft->pRight->pLeft = NULL;
    Root->pLeft->pRight->pRight = NULL;
    Root->pLeft->pRight->pFather = Root->pLeft;

    return Root;
}

void RightRotate(BinaryTree *pNode){
    if (pNode == NULL || pNode->pLeft == NULL) return;
    BinaryTree *pMark = pNode->pLeft;
    //三个孩子的关系
    pNode->pLeft = pMark->pRight;
    pMark->pRight = pNode;
    if (pNode->pFather == NULL) {
        pTree = pMark;
    }else{
        if (pNode == pNode->pFather->pLeft) {
            pNode->pFather->pLeft = pMark;
        }
        else{
            pNode->pFather->pRight = pMark;
        }
    }
    //三个父亲的关系
    if (pNode->pLeft != NULL) {
        pNode->pLeft->pFather = pNode;
    }
    pMark->pFather = pNode->pFather;
    pNode->pFather = pMark;
}

void LeftRotate(BinaryTree *pNode){
    if (pNode == NULL || pNode->pRight == NULL) return;
    BinaryTree *pMark = pNode->pRight;
    //三个孩子的关系
    pNode->pRight = pMark->pLeft;
    pMark->pLeft = pNode;
    if (pNode->pFather == NULL) {
        pTree = pMark;
    }else{
        if (pNode == pNode->pFather->pLeft) {
            pNode->pFather->pLeft = pMark;
        }
        else{
            pNode->pFather->pRight = pMark;
        }
    }
    //三个父亲的关系
    if (pNode->pRight != NULL) {
        pNode->pRight->pFather = pNode;
    }
    pMark->pFather = pNode->pFather;
    pNode->pFather = pMark;
}

void PreorderTraversal(BinaryTree *pTree){
    if (pTree == NULL)  return;
    //打印
    printf("%d  ",pTree->nValue);
    //左子树
    PreorderTraversal(pTree->pLeft);
    //右子树
    PreorderTraversal(pTree->pRight);
}//前序遍历

int main()
{
    pTree = CreateBinaryTree();
    PreorderTraversal(pTree);
    printf("\n");
    RightRotate(pTree);
    PreorderTraversal(pTree);
    printf("\n");
    LeftRotate(pTree);
    PreorderTraversal(pTree);
    printf("\n");

    return 0;
}