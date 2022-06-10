#include <stdio.h>

void InsertionSort(int arr[],int nLength){
    if(arr == NULL || nLength <= 0)
        return;
    int i,j;
    i = 1;
    int temp;
    //无序元素插入
    for (i = 0; i < nLength; i++) {
        j = i - 1;
        temp = arr[i];
        //倒序遍历有序数组 插入无序元素
        //while(temp < arr[j] && j >= 0){ 
        while(j >= 0 && temp < arr[j]){
            //不可能无休止的往前遍历，注意有序数组j限制
            //移动
            arr[j + 1] = arr[j];
            j--;
            //注意 j--后，j = -1时
            //temp < arr[j] && j >= 0中temp < arr[j]会产生越界访问
            //所以需要改成j >= 0 && temp < arr[j]
        }
        //插入
        arr[j + 1] = temp;
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
    int arr[] = {10,7,8,19,2,11,6,4,88};
    InsertionSort(arr, sizeof(arr)/sizeof(arr[0]));
    Print(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}