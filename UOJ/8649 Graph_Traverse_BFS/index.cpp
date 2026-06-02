#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int MAXN = 1010;

typedef struct ArcNode{
    int adjvex;
    int weight;
    ArcNode *nextarc;
}ArcNode;

typedef struct VNode{
    char data;
    ArcNode *firstarc;
}VNode;

typedef struct AdjGraph {
    VNode adj[MAXN];
    int vexnum, arcnum;
    int kind;
}AdjGraph;

int getIndex(AdjGraph &G, char ch) {
    for (int i=0; i<G.vexnum; ++i) {
        if (G.adj[i].data == ch) return i;
    }
    return -1;
}

void CreateGraph(AdjGraph &G) {
    scanf("%d",&G.kind);
    scanf("%d%d", &G.vexnum, &G.arcnum);
    for (int i=0; i<G.vexnum; ++i) {
        cin >> G.adj[i].data;
        G.adj[i].firstarc = NULL;
    }
    char v1, v2;
    int w = 0;
    for (int i=0; i<G.arcnum; ++i) {
        cin >> v1 >> v2;
        if (G.kind == 1 || G.kind == 3) {
            cin >> w;
        }
        int v1_index = getIndex(G, v1);
        int v2_index = getIndex(G, v2);
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

bool visited[MAXN];
void Graph_Traverse_BFS(AdjGraph &G, int start) {
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
}

int main() {
    AdjGraph G;
    CreateGraph(G);
    Graph_Traverse_BFS(G, 0);
    return 0;
}