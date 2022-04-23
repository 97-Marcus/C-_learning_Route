//二分查找代码实现
#include <stdio.h>


//递归方式
int BinarySearch(int arr[],int nBegin,int nEnd,int nNum){
    if(arr == NULL || nBegin > nEnd) return -1;

    //int nMid = (nBegin + nEnd)/2;
    //不知道给定的数据是多大，如果很大的话，相加可能会超出int的上限出现问题，所以要进行优化
    int nMid = nBegin + (nEnd - nBegin)/2;

    if (arr[nMid] == nNum) {
        return nMid; 
    }
    if (arr[nMid] > nNum) { //左侧
        return BinarySearch(arr, nBegin, nMid-1, nNum);
    }else {                 //右侧
        return BinarySearch(arr, nMid+1, nEnd, nNum);
    }
}

//循环方式
int BinarySearch1(int arr[],int nBegin,int nEnd,int nNum){
    if(arr == NULL || nBegin > nEnd) return -1;

    int nMid;
    //找到中间位置，比较
    while (nBegin <= nEnd) {
        nMid = nBegin + (nEnd-nBegin)/2;
        if (arr[nMid] == nNum) {
            return nMid;
        }else if (arr[nMid] > nNum) {   //左侧
            nEnd = nMid - 1;
        }else {                         //右侧
            nBegin = nMid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    int nIndex = BinarySearch(arr,0,sizeof(arr)/sizeof(arr[0])-1,4);
    int nIndex2 = BinarySearch1(arr,0,sizeof(arr)/sizeof(arr[0])-1,5);
    printf("%d\n%d\n",nIndex,nIndex2);
    return 0;
}
