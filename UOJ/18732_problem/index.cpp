#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 25;
vector<int> adj[MAXN];  // 邻接表
int in_degree[MAXN];    // 入度数组
int n, m;

// 拓扑排序（小根堆保证编号小的优先）
void topoSort() {
    // 小根堆：优先弹出编号最小的节点
    priority_queue<int, vector<int>, greater<int>> q;
    vector<int> res;  // 存储拓扑序列

    // 入度为0的节点入堆
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.top();
        q.pop();
        res.push_back(u);

        // 遍历邻接点，入度减1
        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    // 输出结果
    for (int i = 0; i < res.size(); ++i) {
        if (i > 0) cout << " ";
        cout << res[i];
    }
    cout << endl;
}

int main() {
    cin >> n >> m;
    // 初始化入度
    fill(in_degree, in_degree + MAXN, 0);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);   // a -> b，b依赖a
        in_degree[b]++;        // b的入度+1
    }

    topoSort();
    return 0;
}