#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Sunday(const char *src,const char * match){
    if(src == NULL || match == NULL)
        return -1;
    
    //获得next数组
    int *pNext = NULL;
    pNext = (int*)malloc(sizeof(int)*256);
    memset(pNext,-1,sizeof(int)*256);   //赋初值

    int i;
    for(i = 0; i < strlen(match); i++){
        pNext[match[i]] = i;    
        //字符当下标 位置存进去
    }

    //匹配
    int j = 0;
    int k = 0;
    i = 0;

    while(i < strlen(src) && j < strlen(match)){
        if (src[i] == match[j]) {
            i++;
            j++;
        }else {
            if (k + strlen(match) < strlen(src)) {
                i = k + strlen(match) - pNext[src[k+strlen(match)]];
                k = i;
                j = 0;
            }else{
                return -1;
            }
        }
    }
    //判断是否匹配成功
    if (j == strlen(match)) {
        printf("success.\n");
        return k;
    }else{
        return -1;
    }
}

int main(){
    int nIndex = Sunday("adhbeiabcabcsudhasi", "abcabc");
    if (nIndex == -1) {
        printf("fail.\n");
    }else{
        printf("%d\n",nIndex);
    }
    return 0;
}
