#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 110;
ll n, k, a[MAXN];
bool vis[MAXN];

void solve(int dep, bool &flag, ll A[]) {
    if (flag == 1) return;
    if (dep == n) {
        ll res = 0;
        for (int i=0;i<n;++i) {
            res = (res << 3) + (res << 1) + a[A[i]];
        }
        if (res % k == 0) {
            flag = 1;
            printf("%lld\n",res);
        }
        return;
    }
    for (int i=0; i<n; ++i) {
        if (dep == 0 && n > 1 && a[i] == 0) continue;
        if (vis[i] == 1) continue;
        vis[i] = 1;
        A[dep] = i;
        solve(dep+1, flag, A);
        vis[i] = 0;
    }
}

int main() {
    scanf("%lld%lld", &n, &k);
    for (int i=0;i<n;++i) scanf("%lld",&a[i]);
    sort(a, a+n);
    bool flag = false;
    ll A[MAXN] = {};
    solve(0,flag, A);
    if (flag == 0) printf("-1\n");
    return 0;
}