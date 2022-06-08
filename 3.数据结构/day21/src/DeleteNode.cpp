#include <cstddef>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

enum COLOR{RED,BLACK}; 

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

RBT *GetUncle(RBT *pFather){
	if(pFather == pFather->pFather->pLeft){
		return pFather->pFather->pRight;
	}else{
		return pFather->pFather->pLeft;
	}
}

RBT *GetBrother(RBT * pNode){
    if (pNode == pNode->pFather->pLeft) {
        return pNode->pFather->pRight;
    }else{
        return pNode->pFather->pLeft;
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

RBT *FindNode(RBT * pTree,int nNum){
    while (pTree) {
        if(pTree->nValue == nNum){
            return pTree;
        }else if(pTree->nValue > nNum){
            pTree = pTree->pLeft;
        }else {
            pTree = pTree->pRight;
        }
    }
    return NULL;
}

void DeleteNode(int nNum){
    //找到当前被删除节点
    RBT *pTemp = NULL;
    pTemp = FindNode(pRBT, nNum);
    if(pTemp == NULL) return;   //没有要删除的节点 直接结束即可
    
    RBT *pMark = NULL;  //标记
    //孩子情况的分析
    if (pTemp->pLeft != NULL && pTemp->pRight != NULL) {
        pMark = pTemp;
        pTemp = pTemp->pLeft;
        while (pTemp->pRight != NULL) {
            pTemp = pTemp->pRight;
        }   //找到左的最右，然后进行值的覆盖替换
        pMark->nValue = pTemp->nValue;
    }

    //颜色情况的讨论
    RBT *pNode = pTemp->pFather;
    //1. 根
    if (pNode == NULL) {
        //  1.1 无子的情况
        if (pTemp->pLeft == NULL && pTemp->pRight == NULL) {
            free(pTemp);
            pTemp = NULL;
            pRBT = NULL;
            return;
        }
        //  1.2 有一子(红)的情况
        else {
            pRBT = pTemp->pLeft ? pTemp->pLeft : pTemp->pRight;
            pRBT->nColor = BLACK;
            pRBT->pFather = NULL;
            free(pTemp);
            pTemp = NULL;
            return;
        }
    }
    //2. 非根
        //2.1 节点为红色
        if (pTemp->nColor == RED) {
             //判断这个红节点在父亲左侧还是右侧
            if (pTemp == pNode->pLeft) {
                pNode->pLeft = NULL;
            }else{
                pNode->pRight = NULL;
            }
            free(pTemp);
            pTemp = NULL;
            return;
        }
        //2.2 节点为黑色且有一个红子
        if (pTemp->nColor == BLACK && (pTemp->pLeft != NULL || pTemp->pRight != NULL)) {
            if (pTemp == pNode->pLeft) {    //判断这个红子在父亲左侧还是右侧，此处为左
                pNode->pLeft = pTemp->pLeft ? pTemp->pLeft : pTemp->pRight;    //爷孙相连，父亲的左侧换人换成删除节点的孩子
                pNode->pLeft->nColor = BLACK;
                pNode->pLeft->pFather = pNode;
            }else if (pTemp == pNode->pRight) {
                pNode->pRight = pTemp->pLeft ? pTemp->pLeft : pTemp->pRight;
                pNode->pRight->nColor = BLACK;
                pNode->pRight->pFather = pNode;
            }
            free(pTemp);
            pTemp = NULL;
            return;
        }
        //2.3 节点为黑色且无子
        else {
            RBT *pBrother = GetBrother(pTemp);    //兄弟节点
            //删除节点，注意获取兄弟节点和删除节点的顺序不可以乱，先删除节点就无法获取到其兄弟了
            if (pTemp == pNode->pLeft) {
                pNode->pLeft = NULL;
            }else {
                pNode->pRight = NULL;
            }
            free(pTemp);
            pTemp = NULL;
            //调整
            while (1) {
                //2.3.1 兄弟是红色
                if (pBrother->nColor == RED) {
                    pNode->nColor = RED;
                    pBrother->nColor = BLACK;
                    //判断方向进行旋转
                    if (pBrother == pNode->pRight) {
                        LeftRotate(pNode);
                        pBrother = pNode->pRight;   //旋转完兄弟会换人，要更新一下兄弟
                    }else {
                        RightRotate(pNode);
                        pBrother = pNode->pLeft;
                    }
                }
                //2.3.2 兄弟是黑色
                else if (pBrother->nColor == BLACK) {
                    //2.3.2.1 侄子全黑
                    if ( (pBrother->pLeft == NULL && pBrother->pRight == NULL) ||
                        ( (pBrother->pLeft != NULL && pBrother->pLeft->nColor == BLACK) && 
                            (pBrother->pRight != NULL && pBrother->pRight->nColor == BLACK) ) ) {
                        //2.3.2.1.1 父亲红
                        if (pNode->nColor == RED) {
                            pNode->nColor = BLACK;
                            pBrother->nColor = RED;
                            break;
                        }
                        //2.3.2.1.2 父亲黑
                        else if (pNode->nColor == BLACK) {
                            pBrother->nColor = RED;
                            pTemp = pNode;  //父亲作为新的操作节点
                            pNode = pTemp->pFather; //父亲这个变量也需要随之发生变化
                            //判断是否为根，为根则直接结束了
                            if (pNode == NULL) {
                                break;
                            }
                            pBrother = GetBrother(pTemp);   //因为temp改变了 更新一下Brother
                        }
                    }
                    //2.3.2.2 左侄子红，右侄子黑
                    else if ( (pBrother->pLeft != NULL && pBrother->pLeft->nColor ==RED) &&
                                (pBrother->pRight == NULL || pBrother->pRight->nColor == BLACK) ) {
                        //2.3.2.2.1 兄弟在父亲右侧
                        if (pBrother == pNode->pRight) {
                            pBrother->nColor = RED;
                            pBrother->pLeft->nColor = BLACK;
                            RightRotate(pBrother);
                            pBrother = pNode->pRight;   //旋转后兄弟换人了 记得更新
                        }
                        //2.3.2.2.2 兄弟在父亲左侧
                        else {
                            pBrother->nColor = pNode->nColor;   //把父亲颜色给兄弟
                            pNode->nColor = BLACK;
                            pBrother->pLeft->nColor = BLACK;
                            RightRotate(pNode);
                            break;
                        }
                    }
                    //2.3.2.3 右侄子红，左侄子随便
                    else {
                        //2.3.2.3.1 兄弟在父亲左侧
                        if (pBrother == pNode->pLeft) {
                            pBrother->nColor = RED;
                            pBrother->pRight->nColor = BLACK;
                            LeftRotate(pBrother);
                            pBrother = pNode->pLeft;
                        }
                        //2.3.2.3.2 兄弟在父亲右侧
                        else {
                            pBrother->nColor = pNode->nColor;   //把父亲颜色给兄弟
                            pNode->nColor = BLACK;
                            pBrother->pRight->nColor = BLACK;
                            LeftRotate(pNode);
                            break;
                        }
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
    printf("------------------------\n");
    DeleteNode(1);
    PreorderTraversal(pRBT);
    printf("------------------------\n");
    DeleteNode(8);
    PreorderTraversal(pRBT);
    printf("------------------------\n");
    DeleteNode(11);
    PreorderTraversal(pRBT);
    printf("------------------------\n");
    DeleteNode(14);
    PreorderTraversal(pRBT);
    printf("------------------------\n");
    DeleteNode(2);
	PreorderTraversal(pRBT);
	printf("------------------------\n");
	DeleteNode(5);
	PreorderTraversal(pRBT);
	printf("------------------------\n");
	DeleteNode(7);
	PreorderTraversal(pRBT);
	printf("------------------------\n");
	DeleteNode(15);
	PreorderTraversal(pRBT);
	printf("------------------------\n");
    return 0;
}