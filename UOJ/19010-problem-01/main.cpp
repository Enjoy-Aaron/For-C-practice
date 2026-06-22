#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 110;
int n, a[MAXN], A[MAXN], k;
bool vis[MAXN];

void dfs(int dep, bool &flag) {
    if (flag == 1) return;
    if (dep == n) {
        ll res = 0;
        for (int i=0; i<n; ++i) {
            res = (res<<3) + (res<<1) + a[A[i]];
        }
        if (res % k==0) {
            printf("%lld\n",res);
            flag = 1;
        }
        return;
    }
    for (int i=0; i<n; ++i) {
        if (vis[i]) continue;
        if (n>1 && dep==0 && a[i]==0) continue;
        vis[i]=true;
        A[dep] = i;
        dfs(dep+1, flag);
        vis[i] = false;
    }
    return;
}

int main() {
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;++i) {
        scanf("%d",&a[i]);
    }
    sort(a, a+n);
    bool flag=0;
    dfs(0, flag);
    if (!flag) printf("-1\n");
    return 0;
}

