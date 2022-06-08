#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//字典树

typedef struct node{
    int nFlag;
    char *str;
    struct node * pCharacter[26];
}TireTree;  

TireTree *GetNode(){
    TireTree *pNode = NULL;
    pNode =(TireTree*)malloc(sizeof(TireTree));
    memset(pNode, 0, sizeof(TireTree));
    // void *memset(void *str, int c, size_t n) 
    // 复制字符 c（一个无符号字符）到参数 str 所指向的字符串的前 n 个字符。
    return pNode;
}

void AddWord(TireTree *pTree,char *str){
    int i = 0;
    int len = strlen(str);
    while (i < len) {
        //对应字符是否有节点
        if (pTree->pCharacter[str[i]-97] == NULL) {
            pTree->pCharacter[str[i]-97] = GetNode();
        }
        //处理下一个节点
        pTree = pTree->pCharacter[str[i]-97];
        i++;
    }
    //末尾标志及计数
    pTree->nFlag++;
    pTree->str = str;   //方便遍历
}

TireTree *CreateTireTree(char *strArr[],int length){
    if (strArr == NULL || length <= 0) return NULL;
    //根节点
    TireTree *pRoot = NULL;
    pRoot = GetNode();
    //单词添加
    int i;
    for(i = 0;i < length;i++){
        AddWord(pRoot,strArr[i]);
    }
    return pRoot;
}

void Search(TireTree *pRoot,char *str){
    if(pRoot == NULL)
        return;
    int i = 0;
    int len = strlen(str);

    while (i < len) {
        if (pRoot->pCharacter[str[i]-97] == NULL) {
            //失败
            printf("failed.TAT~ 啥也没有");
            return;
        }
        pRoot = pRoot->pCharacter[str[i]-97];
        i++;
    }

    if (pRoot->nFlag != 0) {
        printf("success.A_A~    %s\n",pRoot->str);
        return;
    }else {
        printf("failed.QAQ~ 有这前缀\n");
        return;
    }
}

void PreorderTraversal(TireTree *pTree){
    if(pTree == NULL) return;
    if(pTree->nFlag != 0){
        printf("%s\n",pTree->str);
    }
    int i;
    for(i = 0;i < 26;i++){
        PreorderTraversal(pTree->pCharacter[i]);
    }
}//前序遍历

int main(){
    char *strArr[]={"milk","apple","chips","banana","orange","bread"};
    TireTree *pTree = CreateTireTree(strArr, 6);
    PreorderTraversal(pTree);
    Search(pTree, "apple");
    Search(pTree, "app");
    Search(pTree, "green");
    return 0;
}