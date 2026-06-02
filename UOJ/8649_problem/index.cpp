#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// 最大顶点数
const int MAXN = 100;

// 边节点结构体
struct ArcNode {
    int adjvex;          // 邻接点的下标
    int weight;          // 权值（网使用）
    ArcNode *nextarc;    // 指向下一条边的指针
};

// 顶点结构体
struct VNode {
    char data;           // 顶点数据（字符型）
    ArcNode *firstarc;   // 指向第一个边节点
};

// 邻接表图结构体
struct AdjGraph {
    VNode adj[MAXN];     // 顶点数组
    int n, e;            // 顶点数、边数
    int kind;            // 图的类型：0-有向图 1-有向网 2-无向图 3-无向网
};

// 查找顶点对应的下标
int getIndex(AdjGraph &G, char ch) {
    for (int i = 0; i < G.n; i++) {
        if (G.adj[i].data == ch) {
            return i;
        }
    }
    return -1;
}

// 创建图（邻接表）
void CreateGraph(AdjGraph &G) {
    cin >> G.kind;       // 输入图类型
    cin >> G.n >> G.e;   // 输入顶点数、边数

    // 初始化顶点
    for (int i = 0; i < G.n; i++) {
        cin >> G.adj[i].data;
        G.adj[i].firstarc = NULL;
    }

    // 创建边节点
    char v1, v2;
    int w;
    for (int i = 0; i < G.e; i++) {
        cin >> v1 >> v2;
        // 网需要输入权值
        if (G.kind == 1 || G.kind == 3) {
            cin >> w;
        }

        int v1_index = getIndex(G, v1);
        int v2_index = getIndex(G, v2);

        // 头插法：新建边节点
        ArcNode *p = new ArcNode;
        p->adjvex = v2_index;
        p->weight = w;
        p->nextarc = G.adj[v1_index].firstarc;
        G.adj[v1_index].firstarc = p;

        // 无向图/无向网：反向再建一条边
        if (G.kind == 2 || G.kind == 3) {
            ArcNode *q = new ArcNode;
            q->adjvex = v1_index;
            q->weight = w;
            q->nextarc = G.adj[v2_index].firstarc;
            G.adj[v2_index].firstarc = q;
        }
    }
}

// 广度优先遍历 BFS
bool visited[MAXN];  // 访问标记数组
void BFS(AdjGraph &G, int start) {
    queue<int> q;     // 队列存储顶点下标

    // 初始化访问标记
    memset(visited, false, sizeof(visited));
    // 起始顶点入队
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        // 出队顶点并输出
        int u = q.front();
        q.pop();
        cout << G.adj[u].data << " ";

        // 遍历所有邻接点
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
    CreateGraph(G);   // 创建图
    BFS(G, 0);        // 从第一个顶点（下标0）开始遍历
    return 0;
}