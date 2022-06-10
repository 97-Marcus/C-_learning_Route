#include <stdio.h>

void SelectionSort(int arr[],int nLength){
    if(arr == NULL || nLength <= 0)
        return;
    int i,j;
    int min;
    for (i = 0; i < nLength -1; i++) {
        min = i;
        for (j = i + 1; j < nLength; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        //将最小值放入
        int temp;
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
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
    int arr[] = {10,7,8,19,2,11,66,74,88};
    SelectionSort(arr, sizeof(arr)/sizeof(arr[0]));
    Print(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}


