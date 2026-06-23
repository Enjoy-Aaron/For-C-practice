#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
map<ll, bool> isv;
bool vis[110];
ll ans[100001];
int cnt;

void dfs(int dep, int n, int a[], ll res) {
    if (dep == n) {
        if (res==0) return;
        if (isv.find(res) == isv.end()) {
            isv[res] = true;
            ans[cnt++] = res;
        }
        return;
    }
    dfs(dep+1, n, a, res);
    dfs(dep+1, n, a, res+a[dep]);
}

int main() {
    int n, a[110];
    scanf("%d",&n);
    for (int i=0;i<n;++i) scanf("%d",a+i);
    dfs(0, n, a, 0);
    sort(ans, ans+cnt);
    for (int i=0;i<cnt;++i) printf("%lld ",ans[i]);
    return 0;
}