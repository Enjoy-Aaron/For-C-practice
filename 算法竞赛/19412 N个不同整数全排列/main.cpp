#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e7;
int vis[MAXN];
int a[MAXN];
int A[MAXN];

void solve(int n,int dep)
{
    if (dep==n) {
        for (int i=0;i<n;++i) {
            printf("%d ",A[i]);
        }
        printf("\n");
        return;
    }
    for (int i=0;i<n;++i) {
        if (vis[a[i]]) continue;
        A[dep]=a[i];
        vis[a[i]]=1;
        solve(n,dep+1);
        vis[a[i]]=0;
    }
    return;
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;++i) {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    solve(n,0);
    return 0;
}
