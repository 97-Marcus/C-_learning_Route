#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CountingSort(int arr[],int nLength){
    if(arr == NULL || nLength <= 0)
        return;
    //最大值最小值的查找，确定范围
    int nMax = arr[0];
    int nMin = arr[0];
    for (int i = 1; i < nLength; i++) {
        if (arr[i] > nMax) {
            nMax = arr[i];
        }
        if (arr[i] < nMin) {
            nMin = arr[i];
        }
    }
    //计数数组
    int *pCount = NULL;
    pCount = (int*)malloc(sizeof(int)*(nMax - nMin + 1));
    memset(pCount,0,sizeof(int)*(nMax - nMin + 1));
    //计数
    for (int i = 0; i < nLength; i++) {
        pCount[arr[i] - nMin]++;
    }
    //累加
    for (int i = 1; i < nMax - nMin + 1; i++) {
        pCount[i] += pCount[i - 1];
    }
    //申请新空间 存储
    int *pNew = (int*)malloc(sizeof(int)*nLength);
    int index;
    for (int i = nLength - 1; i >= 0; i--) {
        //pNew[pCount[arr[i] - nMin] - 1] = arr[i];
        //pCount[arr[i] - nMin] 累加后得到的排名
        //-1是因为pNew数组下标
        //因为存储完对应计数器要--，所以加一个index
        index = pCount[arr[i] - nMin] - 1;
        pCount[arr[i] - nMin]--;
        pNew[index] = arr[i];
    }

    //pNew就是要得到的排序结果，可以根据情况看要不要拷贝覆盖源数据
    //如果要拷贝
    for (int i = 0; i < nLength; i++) {
        arr[i] = pNew[i];
    }
    free(pNew);
    pNew = NULL;
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
    CountingSort(arr, sizeof(arr)/sizeof(arr[0]));
    Print(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
