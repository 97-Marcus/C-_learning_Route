#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

enum COLOR{RED,BLACK};  //枚举
//等同于:
//    #define RED    0
//    #define BLACK  1

typedef struct Node{
    int nValue;
    int nColor;
    struct Node *pLeft;
    struct Node *pRight;
    struct Node *pFather;
}RBT;

RBT *pRBT = NULL;

//右旋代码
void RightRotate(RBT *pNode){
    if (pNode == NULL || pNode->pLeft == NULL) return;
    RBT *pMark = pNode->pLeft;
    //三个孩子的关系
    pNode->pLeft = pMark->pRight;
    pMark->pRight = pNode;
    if (pNode->pFather == NULL) {
        pRBT = pMark;
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

//左旋代码
void LeftRotate(RBT *pNode){
    if (pNode == NULL || pNode->pRight == NULL) return;
    RBT *pMark = pNode->pRight;
    //三个孩子的关系
    pNode->pRight = pMark->pLeft;
    pMark->pLeft = pNode;
    if (pNode->pFather == NULL) {
        pRBT = pMark;
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

RBT *GetFather(RBT *pTree,int nNum){
    while (pTree) {
        if (pTree->nValue > nNum) {
            if (pTree->pLeft == NULL) return pTree;
            pTree = pTree->pLeft;   //左侧
        }else if(pTree->nValue < nNum){
            if (pTree->pRight == NULL) return pTree;
            pTree = pTree->pRight;  //右侧
        }else{
            printf("date error!\n");
            exit(1);
        }
    }
    return NULL;
}

RBT *GetUncle(RBT * pFather){
    if (pFather == pFather->pFather->pLeft) {
        return pFather->pFather->pRight;
    }else{
        return pFather->pFather->pLeft;
    }
}

void AddNode(int nNum){
    RBT *pTemp = NULL;
    pTemp = (RBT*)malloc(sizeof(RBT));
    pTemp->nValue = nNum;
    pTemp->nColor = RED;
    pTemp->pFather = NULL;
    pTemp->pLeft = NULL;
    pTemp->pRight = NULL;

    //找到父亲节点
    RBT *pNode = NULL;
    pNode = GetFather(pRBT, nNum);
    pTemp->pFather = pNode;

    //空树情况
    if (pNode == NULL) {
        pRBT = pTemp;
        pRBT->nColor = BLACK;
        return;
    }

    //非空树情况
    //连接
    if (nNum < pNode->nValue) {
        pNode->pLeft = pTemp;
    }else{
        pNode->pRight = pTemp;
    }
    //调整
        //父亲为黑色
    if(pNode->nColor == BLACK){
        return;
    }
    //父亲为红色
    RBT * pGrandFather = NULL;
    RBT * pUncle = NULL;
    while (pNode->nColor == RED) {
        pGrandFather = pNode->pFather;
        pUncle = GetUncle(pNode);
        //叔叔为红色
        if (pUncle != NULL && pUncle->nColor == RED) {
            //不加pUncle != NULL &&情况下如果pUncle为NULL，pUncle->nColor将直接引发程序崩溃
            pNode->nColor = BLACK;
            pUncle->nColor = BLACK;
            pGrandFather->nColor = RED;
            pTemp = pGrandFather;
            pNode = pTemp->pFather;
            //需要判断其是否为根，如果是根的话需要将红色变回黑色，红黑树要求根节点必须是黑色
            if (pNode == NULL) {
                pTemp->nColor = BLACK;
                break;
            }
            continue;
        }
        //叔叔为黑色
        if (pUncle == NULL || pUncle->nColor == BLACK) {
            //不加pUncle != NULL ||情况下如果pUncle为NULL，pUncle->nColor将直接引发程序崩溃
            //父亲是爷爷的左侧
            if (pNode == pGrandFather->pLeft) {
                //当前节点是父亲的右侧
                if (pTemp == pNode->pRight) {
                    pTemp = pNode;
                    LeftRotate(pTemp);  //左旋
                    pNode = pTemp->pFather; //更新父亲
                }
                //当前节点是父亲的左侧
                if (pTemp == pNode->pLeft) {
                    pNode->nColor = BLACK;
                    pGrandFather->nColor = RED;
                    RightRotate(pGrandFather);  //右旋
                    break;
                }
            }
            //父亲是爷爷的右侧
            if (pNode == pGrandFather->pRight) {
                //当前节点是父亲的左侧
                if (pTemp == pNode->pLeft) {
                    pTemp = pNode;
                    RightRotate(pTemp);  //右旋
                    pNode = pTemp->pFather; //更新父亲
                }
                //当前节点是父亲的右侧
                if (pTemp == pNode->pRight) {
                    pNode->nColor = BLACK;
                    pGrandFather->nColor = RED;
                    LeftRotate(pGrandFather);  //左旋
                    break;
                }
            }
        }
    }
}

void CreateRBT(){
    int nNum;
    int nLenth;
    printf("请输入节点个数：\n");
    scanf("%d",&nLenth);
    printf("请输入节点：\n");
    for (int i = 0; i < nLenth; i++) {
        scanf("%d",&nNum);
        AddNode(nNum);
    }
}

void PreorderTraversal(RBT *pTree){
    if (pTree == NULL)  return;
    printf("value = %d\tcolor = %d\n",pTree->nValue,pTree->nColor);
    PreorderTraversal(pTree->pLeft);
    PreorderTraversal(pTree->pRight);
}//前序遍历


int main()
{
    CreateRBT();
    PreorderTraversal(pRBT);
    return 0;
}