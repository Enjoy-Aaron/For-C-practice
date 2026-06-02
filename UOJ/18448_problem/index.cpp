#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 2005;   // 节点数上限
const int MAXM = 2005;   // 边数上限

// 边结构体：起点、终点、权值
struct Edge {
    int u, v;
    long long w;  // 大权值，必须用long long
} edges[MAXM];

// 并查集数组
int fa[MAXN];

// 并查集：查找（路径压缩）
int find(int x) {
    if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

// 边排序：按权值升序
bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    int n, m;
    cin >> n >> m;
    int cnt = 0; // 有效边数（过滤自环后）
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        // 过滤自环（a==b无意义）
        if (a == b) continue;
        edges[cnt].u = a;
        edges[cnt].v = b;
        edges[cnt].w = w;
        cnt++;
    }

    // 初始化并查集
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }

    // 按边权从小到大排序
    sort(edges, edges + cnt, cmp);

    long long ans = 0; // 最小生成树总权值
    int select = 0;    // 已选边数（需要选n-1条）

    // Kruskal核心：遍历所有边
    for (int i = 0; i < cnt; ++i) {
        int u = edges[i].u;
        int v = edges[i].v;
        long long w = edges[i].w;

        int fu = find(u);
        int fv = find(v);
        // 两点不连通，选择这条边
        if (fu != fv) {
            fa[fu] = fv;       // 合并集合
            ans += w;          // 累加权值
            select++;          // 计数+1
            if (select == n-1) break; // 选够n-1条，直接退出
        }
    }

    // 输出结果
    cout << ans << endl;
    return 0;
}