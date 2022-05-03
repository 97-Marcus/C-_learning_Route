#include <iostream>
#include <queue>
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

void LevelTaversal(BinaryTree* pTree){
    if (pTree == NULL) return;
    
    //队列
    queue<BinaryTree*> q;
    //根节点入队
    q.push(pTree);
    //遍历
    while (!q.empty()) {
        pTree = q.front();
        q.pop();
        //输出
        cout<<pTree->nValue<<"  ";
        //非空子节点入队
        if (pTree->pLeft != NULL) {
            q.push(pTree->pLeft);
        }
        if (pTree->pRight != NULL) {
            q.push(pTree->pRight);
        }
    }
}

int main()
{
    BinaryTree *pTree = CreateBinaryTree();
    LevelTaversal(pTree);
    cout<<endl;
    return 0;
}