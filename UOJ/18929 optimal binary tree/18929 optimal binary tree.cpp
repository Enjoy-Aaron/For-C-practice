#include <stdio.h>
#include <string.h>

#define MAXN 305
// 自定义极大值（足够覆盖题目最大答案）
#define INF 1000000000000000000LL
typedef long long ll;

int a[MAXN];
// 记忆化数组
ll dp[MAXN][MAXN][MAXN];

ll dfs(int l, int r, int fa_idx) {
    if (l > r) return 0;
    if (dp[l][r][fa_idx] != -1) return dp[l][r][fa_idx];
    
    ll min_cost = INF;  // 用自定义INF初始化最小值
    // 枚举根节点
    for (int k = l; k <= r; k++) {
        ll cost = (ll)a[k] * a[fa_idx];
        ll left = dfs(l, k - 1, k);
        ll right = dfs(k + 1, r, k);
        ll total = cost + left + right;
        if (total < min_cost) {
            min_cost = total;
        }
    }
    dp[l][r][fa_idx] = min_cost;
    return min_cost;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    a[0] = 0;
    memset(dp, -1, sizeof(dp));
    ll ans = dfs(1, n, 0);
    printf("%lld\n", ans);
    return 0;
}