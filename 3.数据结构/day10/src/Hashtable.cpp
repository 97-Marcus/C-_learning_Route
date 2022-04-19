#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hash{
    int nValue;
    struct hash *pNext;
}Hash;

Hash **CreateHashTable(int arr[],int nLength){
    if (arr == NULL || nLength <= 0)
        return NULL;
    
    //表头
    Hash **pHash = NULL;
    pHash = (Hash**)malloc(sizeof(Hash)*nLength);
    memset(pHash, 0, sizeof(Hash*)*nLength);    //赋初值

    //元素入表
    int nIndex;
    Hash *pTemp = NULL;
    int i;
    for (i = 0; i < nLength; i++) {
        nIndex = arr[i] % nLength;    //获得当前元素所处位置
        pTemp = (Hash*)malloc(sizeof(Hash));    //给元素申请空间
        pTemp->nValue = arr[i];     //
        pTemp->pNext = pHash[nIndex];   //头添加 节点的下一个等于原来的表头
        pHash[nIndex] = pTemp;  //新来的节点成为新的表头
    }
    return pHash;
}

//搜索
void HashSearch(Hash **pHash,int nLength,int nNum){
    if (pHash == NULL) 
        return;

    int nIndex = nNum % nLength;
    Hash *pTemp = pHash[nIndex];  //临时节点
    while (pTemp) { //遍历
        if (pTemp->nValue == nNum) {    //和要找的相同
            printf("%d\n",pTemp->nValue);   //直接输出
            return;
        }
        pTemp = pTemp->pNext;   //不同的话就往下走 继续遍历
    }
    printf("failed.\n");
}

int main()
{
    int arr[] = {10,166,2,18,99,333,15,25,90,376};
    Hash **pHash = CreateHashTable(arr, sizeof(arr)/sizeof(arr[0]));
    HashSearch(pHash, sizeof(arr)/sizeof(arr[0]), 333);
    return 0;
}
