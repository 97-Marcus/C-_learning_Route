#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <iostream>
using namespace std;

typedef struct Node{
    int nValue;
    struct Node *pLeft;
    struct Node *pRight;
}BinaryTree;

void InorderTraversal(BinaryTree *pTree){
    if (pTree == NULL)  return;
    //栈
    stack<BinaryTree*> s;

    while (1) {
        while (pTree) {
            //保存
            s.push(pTree);
            //左
            pTree = pTree->pLeft;
        }
        if (s.empty()) break;
        pTree = s.top();
        cout<<pTree->nValue<<"  ";
        s.pop();
        pTree = pTree->pRight;
    }
}//中序遍历

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

void Search(BinaryTree *pTree,int nNum,BinaryTree **pDel,BinaryTree **pDelFather){
    while (pTree) {
        if(pTree->nValue == nNum){
            *pDel = pTree;
            return;
        }
        else if(pTree->nValue > nNum){  //左侧
            *pDelFather = pTree;
            pTree = pTree->pLeft;
        }
        else {                          //右侧
            *pDelFather = pTree;
            pTree = pTree->pRight;
        }
    }
    *pDelFather = NULL;
}

void DeleteBSTNode(BinaryTree **pTree,int nNum){
    //查找
    BinaryTree *pDel = NULL;
    BinaryTree *pDelFather = NULL;
    //搜索
    Search(*pTree,nNum,&pDel,&pDelFather);
    //删除
    if(pDel == NULL)    return;     //未找到，不用删
    BinaryTree *pMark = NULL;       //标记
        //两个孩子情况的处理
        if(pDel->pLeft != NULL && pDel->pRight != NULL){
            //左的最右or右的最左来进行替换
            pMark = pDel;
            //本代码选择左的最右
            pDelFather = pDel;
            pDel = pDel->pLeft;
            while (pDel->pRight != NULL) {
                pDelFather = pDel;
                pDel = pDel->pRight;
            }
            //值覆盖
            pMark->nValue = pDel->nValue;
        }
    //0个or1个孩子的处理
    if(pDelFather == NULL){     //被删除节点是根，换根的情况
        *pTree = pDel->pLeft ? pDel->pLeft : pDel->pRight;
            //左孩子非空则左孩子成为新根，右孩子非空则右孩子成为新根
        free(pDel);
        pDel = NULL;
        return;
    } 
    else{       //被删除节点非根，需要判断爷孙相连是左侧还是右侧相连
        if (pDel == pDelFather->pLeft) {
            pDelFather->pLeft = pDel->pLeft ? pDel->pLeft : pDel->pRight;
        }else {
            pDelFather->pRight = pDel->pLeft ? pDel->pLeft : pDel->pRight;
        }
        free(pDel);
        pDel = NULL;
        return;
    }
}

int main()
{
    BinaryTree *pTree = CreateBST();
    InorderTraversal(pTree);
    cout<<endl;

    DeleteBSTNode(&pTree, 10);
    InorderTraversal(pTree);
    cout<<endl;
    return 0;
}