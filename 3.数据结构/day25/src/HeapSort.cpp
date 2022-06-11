#include <stdio.h>

#define LEFT    (2*nRootID+1)
#define RIGHT   (2*nRootID+2)

void Adjust(int arr[], int nLength,int nRootID){
    int MAX;
    for (MAX = LEFT; MAX < nLength; MAX = LEFT) {       
        //第二个MAX = LEFT是循环走完一次再走这，相当于更新Root后重新赋初值
        //两个孩子
        if (RIGHT < nLength) {
            if (arr[MAX] < arr[RIGHT]) {
                MAX = RIGHT;
            }
        }
        //大的和父比较
        if (arr[MAX] > arr[nRootID]) {
            arr[MAX] = arr[MAX] ^ arr[nRootID];
            arr[nRootID] = arr[MAX] ^ arr[nRootID];
            arr[MAX] = arr[MAX] ^ arr[nRootID];
            nRootID = MAX;
        }
        else {
            //比父小的情况
            break;  //那就不用调整了 直接结束所在循环就行
        }
    }
}

void HeapSort(int arr[], int nLength){
    if (arr == NULL ||nLength <= 0) return;
    //建初始堆
    int i;
    for(i = nLength/2 - 1;i >= 0;i--){  //nLength/2 - 1为父下标
        //依次调整各个父位置
        Adjust(arr,nLength,i);
    }
    //排序
    for (i = nLength - 1; i > 0; i--) { 
        //第一次是堆顶元素和最后一个元素（n-1）进行交换
        //每次调整的元素个数也是从n-1开始，所以i = nLength - 1
        //i > 0而不是i >= 0 ，这表示调整次数，当剩下最后一个的时候就不需要操作了
        //交换
        arr[i] = arr[0]^arr[i];
        arr[0] = arr[0]^arr[i];
        arr[i] = arr[0]^arr[i];
        //调整堆顶
        Adjust(arr,i,0);
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
    int arr[] = {90,87,98,89,92,91,96,94,98};
    HeapSort(arr, sizeof(arr)/sizeof(arr[0]));
    Print(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
