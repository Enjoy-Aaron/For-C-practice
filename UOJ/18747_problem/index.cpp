#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 105;
// 邻接表：存储 邻接点、边权值
vector<pair<int, int>> adj[MAXN];
// 入度数组（拓扑排序用）
int in_degree[MAXN];
// 存储拓扑排序结果
vector<int> topo_order;
int n, m;

// 拓扑排序
void topologicalSort() {
    queue<int> q;
    // 入度为0的节点入队
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo_order.push_back(u);

        // 遍历邻接点，入度减1
        for (auto &edge : adj[u]) {
            int v = edge.first;
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    memset(in_degree, 0, sizeof(in_degree));

    // 建图（有向边）
    for (int i = 0; i < m; ++i) {
        int a, b, x;
        cin >> a >> b >> x;
        adj[a].emplace_back(b, x);
        in_degree[b]++;
    }

    // 1. 执行拓扑排序
    topologicalSort();

    // 2. 动态规划求最长路径
    vector<int> dist(n + 1, -0x3f3f3f3f); // 初始化为极小值
    dist[1] = 0; // 起点1的距离为0

    for (int u : topo_order) {
        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            // 松弛操作：更新最长路径
            dist[v] = max(dist[v], dist[u] + w);
        }
    }

    // 输出终点n的最长路径（关键路径长度）
    cout << dist[n] << endl;

    return 0;
}