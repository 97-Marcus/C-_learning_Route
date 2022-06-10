#include <stdio.h>

void BubbleSort(int arr[],int nLength){
    if(arr == NULL || nLength <= 0)
        return;
    int i,j,temp;
    int index;
    int count = 0;
    for (i = 0; i < nLength - 1; i++) {
        index = 0;
        for(j = 0; j < nLength -1 - i;j++){
            if (arr[j]>arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                index = j + 1;
            }
            count++;
        }
        if (index == 0) break;
        i = nLength - index - 1;    //因为上面的for里要i++，所以先减掉一个
    }
    printf("%d\n",count);
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
    BubbleSort(arr, sizeof(arr)/sizeof(arr[0]));
    Print(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}


