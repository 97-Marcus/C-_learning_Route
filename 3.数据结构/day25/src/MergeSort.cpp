#include <stdio.h>
#include <stdlib.h>

void Merge(int arr[],int nBegin,int nEnd){
    int nBegin1 = nBegin;
    int nEnd1 = nBegin + (nEnd - nBegin)/2;
    int nBegin2 = nEnd1 + 1;
    int nEnd2 = nEnd;
    int *pTemp = (int*)malloc(sizeof(int)*(nEnd-nBegin+1));
    int i = 0;
    //合并
    while (nBegin1 <= nEnd1 && nBegin2 <= nEnd2) {
        if (arr[nBegin1] > arr[nBegin2]) {
            pTemp[i] = arr[nBegin2];
            i++;
            nBegin2++;
        }else {
            pTemp[i] = arr[nBegin1];
            i++;
            nBegin1++;
        }
    }
    //将有剩余的部分放入
    while (nBegin1 <= nEnd1) {
        pTemp[i] = arr[nBegin1];
        i++;
        nBegin1++;
    }
    while (nBegin2 <= nEnd2) {
        pTemp[i] = arr[nBegin2];
        i++;
        nBegin2++;
    }
    //元素放回原数组
    for(int i = 0;i < nEnd - nBegin + 1;i++){
        arr[nBegin + i] = pTemp[i];
    }
    //释放
    free(pTemp);
    pTemp = NULL;
}

void MergeSort(int arr[],int nBegin,int nEnd){
    if(arr == NULL || nBegin >= nEnd)
        return;
    //分割
    int nMid;
    nMid = nBegin + (nEnd - nBegin)/2;
    MergeSort(arr,nBegin,nMid);
    MergeSort(arr,nMid + 1,nEnd);
    //合并
    Merge(arr,nBegin,nEnd);
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
    int arr[] = {90,87,98,89,92,91,96,94,98};
    MergeSort(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1);
    Print(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
