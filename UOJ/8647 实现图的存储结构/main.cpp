#include <iostream>
#include <cstdio>
using namespace std;

#define MaxInt 32767
#define MVNum 100
#define ERROR 0
#define OK 1
typedef int Status;
typedef int vertexType;
typedef int ArcType;
typedef int OtherInfo
typedef struct {
    vertexType vexs[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vexnum, arcnum;
}AMGraph;
typedef struct ArcNode {
    int adjvex;
    struct ArcNode *nextarc;
    OtherInfo info;
}ArcNode;
typedef struct VNode {
    vertexType data;
    ArcNode *firstarc;
}VNode, AdjList[MVNum];
typedef struct {
    AdjList vertices;
    int vexnum, arcnum;
}ALGraph;

int LocateVex(AMGraph G, vertexType v)
{
    for (int i=0;i<G.vexnum;++i) {
        if (v==G.vexs[i]) return i;
    }
    return -1;
}

Status CreateUDN(AMGraph &G)
{
    cin >> G.vexnum >> G.arcnum;
    for (int i=0;i<G.vexnum;++i) {
        G.vexs[i]=i+1;
    }
    for (int i=0;i<G.vexnum;++i) {
        for (int j=0;j<G.vexnum;++j) {
            G.arcs[i][j]=0;
        }
    }
    for (int k=0;k<G.arcnum;++k) {
        int v1,v2;
        cin >> v1 >> v2;
        int i=LocateVex(G,v1), j=LocateVex(G,v2);
        G.arcs[i][j] = 1;
    }
    return OK;
}

Status printGraph(AMGraph G)
{
    for (int i=0;i<G.vexnum;++i) {
        for (int j=0;j<G.vexnum;++j) {
            printf("%d ",G.arcs[i][j]);
        }
        printf("\n");
    }
    return OK;
}

int main()
{
    AMGraph G;
    CreateUDN(G);
    printGraph(G);
    return 0;
}
