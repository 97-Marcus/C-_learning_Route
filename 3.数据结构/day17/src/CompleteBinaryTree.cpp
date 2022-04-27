#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int nValue;
    struct Node *pLeft;
    struct Node *pRight;
}BinaryTree; 

BinaryTree *CreateCompleteBT(int arr[], int nLength){
    if (arr == NULL || nLength <= 0) return NULL;

    //空间申请
    BinaryTree *pCCompleteBT = NULL;
    pCCompleteBT = (BinaryTree*)malloc(sizeof(BinaryTree)*nLength);

    //赋值
    int i;
    for (i = 0; i < nLength; i++) {
        pCCompleteBT[i].nValue = arr[i];
        pCCompleteBT[i].pLeft = NULL;
        pCCompleteBT[i].pRight = NULL;
    }

    //父子关系关联
    for (i = 0; i <= (nLength / 2) - 1; i++) {
        if (2 * i + 1 < nLength) {
            pCCompleteBT[i].pLeft = &pCCompleteBT[2 * i + 1];
        }
        if (2 * i + 2 < nLength) {
            pCCompleteBT[i].pRight = &pCCompleteBT[2 * i + 2];
        }
    }
    return pCCompleteBT;
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
    int arr[] = {1,2,3,4,5};
    pTree = CreateCompleteBT(arr, 5);
    PreorderTraversal(pTree);
    return 0;
}