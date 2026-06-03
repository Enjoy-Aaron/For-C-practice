#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAX(a, b) (a>b? a:b)
#define MIN(a, b) (a<b? a:b)
#define MAXSIZE 1010

typedef char VertexType;
typedef int Status;
typedef struct ArcNode {
    int adjvex;
    int weight;
    ArcNode *nextarc;
} ArcNode;
typedef struct VNode {
    VertexType data;
    ArcNode *firstarc;
} VNode;
typedef struct AdjGraph {
    VNode adj[MAXSIZE];
    int vexnum, arcnum;
    int kind;
} AdjGraph;

int GetIndex(AdjGraph &G, char vex) {
    for (int i = 0; i < G.vexnum; ++i) {
        if (G.adj[i].data == vex) return i;
    }
    return -1;
}

Status CreateGraph(AdjGraph &G) {
    cin >> G.kind;
    cin >> G.vexnum >> G.arcnum;
    for (int i = 0; i < G.vexnum; ++i) {
        cin >> G.adj[i].data;
        G.adj[i].firstarc = NULL;
    }
    VertexType v1, v2;
    int w;
    for (int i = 0; i < G.arcnum; ++i) {
        cin >> v1 >> v2;
        if (G.kind == 1 || G.kind == 3) cin >> w;
        int v1_index = GetIndex(G, v1);
        int v2_index = GetIndex(G, v2);
        ArcNode *p = new ArcNode;
        p->adjvex = v2_index;
        p->weight = w;
        p->nextarc = G.adj[v1_index].firstarc;
        G.adj[v1_index].firstarc = p;
        if (G.kind == 2 || G.kind == 3) {
            ArcNode *q = new ArcNode;
            q->adjvex = v1_index;
            q->weight = w;
            q->nextarc = G.adj[v2_index].firstarc;
            G.adj[v2_index].firstarc = q;
        }
    }
    return OK;
}

bool visited[MAXSIZE];
Status TraverseGraph_BFS(AdjGraph &G, int start) {
    queue<int> q;
    memset(visited, false, sizeof(visited));
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << G.adj[u].data << " ";
        ArcNode *p = G.adj[u].firstarc;
        while (p != NULL) {
            int v = p->adjvex;
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
            p = p->nextarc;
        }
    }
    return OK;
}

int main() {
    AdjGraph G;
    CreateGraph(G);
    TraverseGraph_BFS(G, 0);
    return 0;
}