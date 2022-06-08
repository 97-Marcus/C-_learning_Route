#include <cstdio>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

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

void BFS(Graph *pGraph,int nBegin){ //传图和起始顶点
    //标记数组
    int *pMark = NULL;
    pMark = (int *)malloc(sizeof(int*)*pGraph->nVertex);
    memset(pMark, 0, sizeof(int*)*pGraph->nVertex);
    //队列
    queue<int>q;
    //起始顶点 入队 标记
    q.push(nBegin);
    pMark[nBegin-1] = 1;
    while (!q.empty()) {
        nBegin = q.front();
        q.pop();
        printf("%d  ",nBegin);
        //遍历
        for (int i = 0; i<pGraph->nVertex; i++) {
            if (pGraph->pMatrix[nBegin-1][i] == 1 && pMark[i] == 0) {
                q.push(i + 1);
                pMark[i] = 1;
            }
        }
    }
    printf("\n");
    //释放
    free(pMark);
    pMark = NULL;
}

int main(){
    Graph *pGraph = CreateGraph();
    BFS(pGraph, 4);
    return 0;
}
