#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *GetNext(const char *match){
    int i;
    int *pNext = (int*)malloc(sizeof(int)*strlen(match));
    int j;

    pNext[0] = 0;
    i = 1;
    j = i - 1;
    while(i < strlen(match)){
        if(match[i] == match[pNext[j]]){
            pNext[i] = pNext[j] + 1;
            i++;
        }else {
            if (pNext[j] == 0) {
                pNext[i] = 0;
                i++;
            }else{
                j = pNext[j] - 1;
            }
        }
    }
    return pNext;
}

int KMP(const char *src,const char *match){
    if (src == NULL || match == NULL) 
        return -1;

    //Next数组计算
    int *pNext = NULL;
    pNext = GetNext(match);

    //匹配
    int i = 0;
    int j = 0;

    while (i < strlen(src) && j < strlen(match)) {
        if (src[i] == match[j]) {
            i++;
            j++;
        }else {
            if(j == 0){
                i++;
            }else {
                j = pNext[j-1];
            }
        }
    }
    if (j == strlen(match)) {
        printf("success.\n");
        return i - j;
    }else {
        return -1;
    }
}

int main()
{
    int nIndex = KMP("weo1abcabcjisaod", "abcabc");
    if (nIndex != -1) {
        printf("%d\n",nIndex);
    }else {
        printf("fail.");
    }

    return 0;
}
