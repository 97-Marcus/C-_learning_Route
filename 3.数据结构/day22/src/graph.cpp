#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VertexNumber 5

typedef struct node{
    int nVertex;//点的数量
    int nEdge;  //边的数量
    int pMatrix[VertexNumber][VertexNumber];   //矩阵(去宏定义里改，是写死的)
    //如果想要动态的可以用指针形式，如
    //int *pMatrix;
}Graph;

Graph *CreateGraph(){
    Graph *pGraph = NULL;
    pGraph = (Graph*)malloc(sizeof(Graph));
    printf("输入顶点个数和边的数量：\n");
    int nV,nE;
    scanf("%d%d",&nV,&nE);
    pGraph->nVertex = nV;
    pGraph->nEdge = nE;
    memset(pGraph->pMatrix,0,sizeof(int)*VertexNumber*VertexNumber);//初始化
    //pGraph->pMatrix = (int*)malloc(sizeof(int)*nV*nV);    //动态申请
    //memset(pGraph->pMatrix,0,sizeof(int)*nV*nV);  //给矩阵全部赋初值为 0

    int v1,v2;
    //放入边
    for(int i = 0;i < nE;i++){
        printf("请输入两个顶点以确认一条边：\n");
        scanf("%d%d",&v1,&v2);
        if (v1 >= 1 && v1 <= nV && v2 >= 1 && v2 <= nV && v1 != v2 && pGraph->pMatrix[v1-1][v2-1] == 0) {
            //输入的顶点要大于等于1且小于点的个数；
            //同时由于创建是简单图，所以顶点和顶点自己不存在关系，不能输入两个一样的顶点；
            //同时需要判断矩阵内相应位置是否已经存在关系，如果不存在才放。
            pGraph->pMatrix[v1-1][v2-1] = 1;
            pGraph->pMatrix[v2-1][v1-1] = 1;    //构建的是无向，所以矩阵应该沿对角线对称
            //pGraph->pMatrix[(v1-1)*nV][(v2-1)*nV] = 1;    
            //pGraph->pMatrix[(v2-1)*nV][(v1-1)*nV] = 1;
                //动态申请的话要算一下位置，前面的判断也需要算，pGraph->pMatrix[(v1-1)*nV][(v2-1)*nV] == 0
        }
        else {
            i--;    //放错了要把边的计数减回来噢
        }
    }
    return pGraph;
}

int main(){
    Graph *pGraph = CreateGraph();
    int i;
    int j;  //还不知道图的遍历，所以先用二维数组遍历啦
    for (i = 0 ; i < pGraph->nVertex ; i++) {
        for (j = 0 ; j < pGraph->nVertex ; j++) {
            printf("%d  ",pGraph->pMatrix[i][j]);
        }
        printf("\n");
    }
    return 0;    
}