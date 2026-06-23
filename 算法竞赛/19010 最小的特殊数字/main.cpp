#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, k,a[110],A[110];
int flag=0;
int vis[110];

void solve(int n, int dep)
{
    if (flag==1) return;
    if (dep==n) {
        ll res = 0;
        for (int i=0;i<n;++i) {
            res = (res<<1) + (res<<3) + a[A[i]];
        }
        if (res % k == 0) {
            for (int i=0;i<n;++i) printf("%d",a[A[i]]);
            flag=1;
        }
        return;
    }
    for (int i=0;i<n;++i) {
        if (vis[i]==1) continue;
        if (n>1 && dep==0 && a[i]==0) continue;
        vis[i]=1;
        A[dep]=i;
        solve(n,dep+1);
        vis[i]=0;
    }
}

int main()
{
    scanf("%lld%lld",&n,&k);
    for (int i=0;i<n;++i) scanf("%lld",&a[i]);
    sort(a,a+n);
    solve(n,0);
    return 0;
}
