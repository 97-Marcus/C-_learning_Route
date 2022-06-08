#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VertexNumber 5

typedef struct node{
    int nVertex;
    int nEdge;
    int pMatrix[VertexNumber][VertexNumber];
}Graph;

Graph *CreateGraph(){
    Graph *pGraph = NULL;
    pGraph = (Graph*)malloc(sizeof(Graph));
    printf("输入顶点个数和边的数量：\n");
    int nV,nE;
    scanf("%d%d",&nV,&nE);
    pGraph->nVertex = nV;
    pGraph->nEdge = nE;
    memset(pGraph->pMatrix,0,sizeof(int)*VertexNumber*VertexNumber);

    int v1,v2;
    for(int i = 0;i < nE;i++){
        printf("请输入两个顶点以确认一条边：\n");
        scanf("%d%d",&v1,&v2);
        if (v1 >= 1 && v1 <= nV && v2 >= 1 && v2 <= nV && v1 != v2 && pGraph->pMatrix[v1-1][v2-1] == 0) {
            pGraph->pMatrix[v1-1][v2-1] = 1;
            pGraph->pMatrix[v2-1][v1-1] = 1;
        }
        else {
            i--;
        }
    }
    return pGraph;
}

void myDFS(Graph *pGraph,int nBegin,int *pMark){ //递归函数
    //打印 标记
    printf("%d  ",nBegin);
    pMark[nBegin-1] = 1;
    //遍历
    int i;
    for (i = 0; i < pGraph->nVertex; i++) {
        //有关的且未被打印过的第一个点
        if (pGraph->pMatrix[nBegin-1][i] == 1 && pMark[i] == 0) {
            //处理
            myDFS(pGraph, i + 1, pMark);    //i是下标但是遍历的点是1到n所以要i+1
        }//用循环结束来控制递归结束
    }
}

void DFS(Graph *pGraph,int nBegin){ //传图和起始顶点
    //标记数组
    int *pMark = NULL;
    pMark = (int *)malloc(sizeof(int*)*pGraph->nVertex);
    memset(pMark, 0, sizeof(int*)*pGraph->nVertex);

    //直接写递归的话，每次都要来个标记数组，所以可以再写个递归函数
    //顶点处理递归函数
    myDFS(pGraph,nBegin,pMark);

    //释放
    free(pMark);
    pMark = NULL;
}

int main(){
    Graph *pGraph = CreateGraph();
    DFS(pGraph, 4);
    return 0;
}
