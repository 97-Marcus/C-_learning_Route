#include <cstdlib>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct Node{
    int nValue;
    struct Node *pNext;
}Radix;  

void RadixSort(int arr[],int nLength){
    if(arr == NULL || nLength <= 0)
        return;
    //最大值
    int nMax = arr[0];
    for(int i = 0;i < nLength;i++){
        if(arr[i] > nMax){
            nMax = arr[i];
        }
    }
    //计算最大值位数
    int nCount = 1;
    while (nMax) {
        nCount *= 10;
        nMax /= 10;
    }nCount /= 10;
    //按位处理
    Radix **pRadix = NULL;  //申请表头
    pRadix = (Radix**)malloc(sizeof(Radix*)*10);
    memset( pRadix, 0, sizeof(Radix*)*10);
    for (int i = 1; i <= nCount; i *= 10) {
        //入组
        int nIndex;
        Radix *pTemp = NULL;
        for(int j = 0;j < nLength;j++){
            pTemp = (Radix*)malloc(sizeof(Radix));
            pTemp->nValue = arr[j];
            pTemp->pNext = NULL;
            nIndex = arr[j]/i % 10;
            //尾添加
            if (pRadix[nIndex] == NULL) {
                pRadix[nIndex] = pTemp;
            }else{
                Radix *pNode = pRadix[nIndex];
                while (pNode->pNext != NULL) {
                    pNode = pNode->pNext;
                }
                pNode->pNext = pTemp;
            }
        }
        //放回原数组
        int k = 0;
        for(int i = 0; i < 10;i++){
            pTemp = pRadix[i];
            while (pTemp) {
                arr[k] = pTemp->nValue;
                k++;
                pTemp = pTemp->pNext;
            }
        }
        //释放
        Radix *pDel = NULL;
        for(int i = 0; i < 10;i++){
            pTemp = pRadix[i];
            while (pTemp) {
                pDel = pTemp;
                pTemp = pTemp->pNext;
                free(pDel);
                pDel = NULL;
            }
        }
        //表头清空
        memset(pRadix, 0, sizeof(Radix*)*10);
    }
    free(pRadix);
    pRadix = NULL;
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
    int arr[] = {11,72,811,1,32,17,22,156,11};
    RadixSort(arr, sizeof(arr)/sizeof(arr[0]));
    Print(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}