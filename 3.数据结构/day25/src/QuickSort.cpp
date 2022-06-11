#include <stdio.h>

//foundation基础版快排（挖坑填补法）
int DetermineLocation(int arr[], int nBegin,int nEnd){
    int temp = arr[nBegin];
    while (nBegin < nEnd) {
        //从后向前找比标准值小的
        while (nEnd > nBegin) {
            if (arr[nEnd] < temp) {
                arr[nBegin] = arr[nEnd];
                nBegin++;
            }
            nEnd--;
        }
        //从前向后找比标准值大的
        while (nEnd > nBegin) {
            if (arr[nBegin] > temp) {
                arr[nEnd] = arr[nBegin];
                nEnd--;
            }
            nBegin++;
        }
    }
    //标准值放入
    arr[nBegin] = temp;
    return nBegin;
}

//optimize优化版快排（区间分割法）
int DetermineLocation1(int arr[], int nBegin,int nEnd){
    int nSmall = nBegin - 1;
    for (nBegin; nBegin < nEnd; nBegin++) {
        if (arr[nBegin] < arr[nEnd]) {
            //小区间扩张
            if (++nSmall != nBegin) {
                arr[nSmall] = arr[nSmall]^arr[nBegin];
                arr[nBegin] = arr[nSmall]^arr[nBegin];
                arr[nSmall] = arr[nSmall]^arr[nBegin];
            }//使用异或交换时注意，不可以位于同一物理空间上，所以需要判断++nSmall != nBegin
            //当然也可以用swap函数，然后也可以用中间量temp啥的方法来换~
        }
    }
    //标准值放入
    if (++nSmall != nEnd) {
        arr[nSmall] = arr[nSmall]^arr[nEnd];
        arr[nEnd] = arr[nSmall]^arr[nEnd];
        arr[nSmall] = arr[nSmall]^arr[nEnd];
    }
    return nSmall;
}

void QuickSort(int arr[], int nBegin,int nEnd){
    if (arr == NULL ||nBegin > nEnd) return;
    //找标准值位置
    int nTemp = DetermineLocation1(arr, nBegin, nEnd);
    //分割
    QuickSort(arr, nBegin, nTemp - 1);
    QuickSort(arr, nTemp + 1, nEnd);
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
    QuickSort(arr, 0 , sizeof(arr)/sizeof(arr[0]) - 1);
    Print(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
