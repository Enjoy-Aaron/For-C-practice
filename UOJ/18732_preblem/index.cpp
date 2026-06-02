#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 105;    // 节点数上限
const int INF = 0x3f3f3f3f; // 无穷大

int g[MAXN][MAXN];       // 邻接矩阵存图
int dist[MAXN];          // 存储起点到各点的最短距离
bool vis[MAXN];          // 标记节点是否已确定最短路
int n, m;

// Dijkstra 算法：求起点1到所有点的最短路
void dijkstra() {
    // 初始化：距离无穷大，未访问
    memset(dist, INF, sizeof(dist));
    memset(vis, false, sizeof(vis));
    dist[1] = 0; // 起点1的距离为0

    // 遍历n次，每次确定一个节点的最短路
    for (int i = 1; i <= n; ++i) {
        // 1. 找未访问的、距离最小的节点u
        int u = -1;
        int min_dist = INF;
        for (int j = 1; j <= n; ++j) {
            if (!vis[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }
        if (u == -1) break; // 剩余节点不可达，直接退出
        vis[u] = true;

        // 2. 松弛操作：用u更新所有相邻节点的距离
        for (int v = 1; v <= n; ++v) {
            if (!vis[v] && g[u][v] != INF) {
                dist[v] = min(dist[v], dist[u] + g[u][v]);
            }
        }
    }
}

int main() {
    // 1. 初始化邻接矩阵为无穷大
    memset(g, INF, sizeof(g));
    for (int i = 1; i <= n; ++i) g[i][i] = 0;

    // 2. 输入节点数、边数
    cin >> n >> m;

    // 3. 输入边，无向图双向存边，重边取最小值
    int a, b, x;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> x;
        if (x < g[a][b]) { // 处理重边，保留最小权值
            g[a][b] = x;
            g[b][a] = x;
        }
    }

    // 4. 执行最短路算法
    dijkstra();

    // 5. 输出结果：无法到达输出-1，否则输出最短距离
    if (dist[n] == INF) cout << -1 << endl;
    else cout << dist[n] << endl;

    return 0;
}