#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

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
    //栈
    stack<BinaryTree*> s;
    
    while (1) {
        while (pTree) {
            //输出
            cout<<pTree->nValue<<"  ";
            //保存
            s.push(pTree);
            //左
            pTree = pTree->pLeft;
        }
        if (s.empty()) break;
        //弹出
        pTree = s.top();
        s.pop();
        //右侧
        pTree = pTree->pRight;
    }
}//非递归实现的前序遍历

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
        //弹出
        pTree = s.top();
        //输出
        cout<<pTree->nValue<<"  ";
        s.pop();
        //右侧
        pTree = pTree->pRight;
    }
}//非递归实现的中序遍历

void LevelTaversal(BinaryTree* pTree){
    if (pTree == NULL)  return;
    //栈
    stack<BinaryTree*> s;

    BinaryTree* pMark = NULL;
    while(1){
        while (pTree) {
            //保存
            s.push(pTree);
            //找左
            pTree = pTree->pLeft;
        }
        if (s.empty()) break;
        //栈顶结点的右侧
        if (s.top()->pRight == NULL || s.top()->pRight == pMark) {
            //弹出 打印 标记
            pMark = s.top();
            s.pop();
            printf("%d  ",pMark->nValue);
        }
        else {
            pTree = s.top()->pRight;
        }
    }
}//非递归实现的后序遍历

int main(){
    BinaryTree *pTree = CreateBinaryTree();
    PreorderTraversal(pTree);
    cout<<endl;
    InorderTraversal(pTree);
    cout<<endl;
    LevelTaversal(pTree);
    return 0;
}