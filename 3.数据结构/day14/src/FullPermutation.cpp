#include <stdio.h>

void FullPermutation(int arr[],int nLen,int start){
    if (start == nLen) {
        int i;
        for(i = 0;i < nLen; i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        return;
    }

    int i;
    int temp;
    for (i = start; i < nLen; i++) {
        //交换
        temp = arr[i];
        arr[i] = arr[start];
        arr[start] = temp;

        //第一个确定后，后面的要全排列
        FullPermutation(arr,nLen,start + 1);
        
        //回溯(把交换的换回去)
        temp = arr[i];
        arr[i] = arr[start];
        arr[start] = temp;
    }
}

int main()
{
    int arr[] = {1,2,3};
    FullPermutation(arr,3,0);
    return 0;
}