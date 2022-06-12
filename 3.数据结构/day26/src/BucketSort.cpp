#include <cstdlib>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct Node{
    int nValue;
    struct Node *pNext;
}List;

void Sort(List *pHead){
    if (pHead == NULL ||pHead->pNext == NULL) return;
                //根本没有或者只有一个，那都不需要排序，直接return
    //冒泡排序
    List *pNode = pHead;        //趟数
    List *pTemp = NULL;         //遍历
    while(pNode->pNext != NULL){
        pTemp = pHead;
        while (pTemp->pNext != NULL) {
            if(pTemp->nValue > pTemp->pNext->nValue){
                pTemp->nValue = pTemp->nValue ^ pTemp->pNext->nValue;
                pTemp->pNext->nValue = pTemp->nValue ^ pTemp->pNext->nValue;
                pTemp->nValue = pTemp->nValue ^ pTemp->pNext->nValue;
            }
            pTemp = pTemp->pNext;
        }
        pNode = pNode->pNext;
    }
}    

void BucketSort(int arr[],int nLength){
    if(arr == NULL || nLength <= 0)
        return;
    //最大值最小值
    int nMax = arr[0];
    int nMin = arr[0];
    for(int i = 0;i < nLength;i++){
        if(arr[i] > nMax){
            nMax = arr[i];
        }
        if (arr[i] < nMin) {
            nMin = arr[i];
        }
    }
    //计算数字位数
    int nCount = 1;
    int nNum = nMax;
    while(nNum){
        nNum = nNum / 10;   //每次去掉数字最后一位
	    nCount *= 10;           //循环一次计数器+1
    }
    nCount /= 10;

    //拆分高位
    int nMinIndex = nMin / nCount % 10;
    int nMaxIndex = nMax / nCount % 10;

    //申请桶子
    List **pBucket = NULL;
    pBucket = (List**)malloc(sizeof(List*)*(nMaxIndex - nMinIndex + 1));
    memset(pBucket, 0, sizeof(List*)*(nMaxIndex - nMinIndex + 1));

    //元素入桶
    List *pTemp = NULL;
    int nIndex;
    for(int i = 0;i < nLength;i++){
        nIndex = arr[i] / nCount % 10 - nMinIndex;
        //头插
        pTemp = (List*)malloc(sizeof(List));
        pTemp->nValue = arr[i];
        pTemp->pNext = pBucket[nIndex];
        pBucket[nIndex] = pTemp;
    }

    //各桶内元素排序
    for(int i = 0;i < nMaxIndex - nMinIndex + 1;i++){
        Sort(pBucket[i]);
    }

    //将桶内元素放回原数组
    nNum = 0;
    for(int i = 0; i < nMaxIndex - nMinIndex + 1;i++){
        pTemp = pBucket[i];
        while (pTemp) {
            arr[nNum] = pTemp->nValue;
            nNum++;
            pTemp = pTemp->pNext;
        }
    }

    //释放
    List *pDel = NULL;
    for(int i = 0; i < nMaxIndex - nMinIndex + 1;i++){
        pTemp = pBucket[i];
        while (pTemp) {
            pDel = pTemp;
            pTemp = pTemp->pNext;
            free(pDel);
            pDel = NULL;
        }
    }
    free(pBucket);
    pBucket = NULL;
}

void Print(int arr[],int nLength){
    if(arr == NULL || nLength <= 0)
        return;
    for (int i = 0; i < nLength; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {101,722,811,119,221,119,662,743,838};
    BucketSort(arr, sizeof(arr)/sizeof(arr[0]));
    Print(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}