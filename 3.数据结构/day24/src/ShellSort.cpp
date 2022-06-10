#include <stdio.h>

void ShellSort(int arr[],int nLength){
    if(arr == NULL || nLength <= 0)
        return;
    int i,j;
    int nGap;
    int k;
    int temp;
    //确认间隔，此程序以2分方式为例
    for (nGap = nLength / 2; nGap >= 1; nGap /= 2) {
        //组
        // for (i = 0; i < nGap; i++) {
        //     //各组内插入排序
        //     for (j = i + nGap; j < nLength; j += nGap) {
        //         k = j - nGap;   //有序的最后一个元素
        //         temp = arr[j];
        //         while (k >= i && temp < arr[k]) {
        //             arr[k + nGap] = arr[k];    //移动
        //             k -= nGap;  //往前走
        //         }
        //         //插入
        //         arr[k + nGap] = temp;
        //     }
        // }
        for (i = nGap; i < nLength; i++) {
            j = i - nGap;
            temp = arr[i];
            while(j >= 0 && temp < arr[j]){
                arr[j + nGap] = arr[j];
                j -= nGap;
            }
            //插入
            arr[j + nGap] = temp;
        }
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
    ShellSort(arr, sizeof(arr)/sizeof(arr[0]));
    Print(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}


