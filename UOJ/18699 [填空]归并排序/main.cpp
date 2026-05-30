#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
map<ll,int> cnt;
int A[110];
void dfs(int dep, int n, ll a[])
{
    if (dep == n) {
        for (int i=0;i<n;++i) printf("%d ",a[A[i]]);
        printf("\n");
        return;
    }
    for (int i=0; i<n; ++i) {
        if (cnt[a[i]]==0) continue;
        if (dep>0 && a[i]%2==1 && a[A[dep-1]]%2==1) continue;
        cnt[a[i]]--;
        A[dep] = i;
        dfs(dep+1,n,a);
        cnt[a[i]]++;
    }
    return;
}

int main()
{
    int N, n=0;
    ll tmp;
    ll a[110]={};
    scanf("%d",&N);
    for (int i=0;i<N;++i) {
        scanf("%lld",&tmp);
        if (cnt.find(tmp) == cnt.end()) {
            cnt[tmp]=1;
            a[n++]=tmp;
        }
        else cnt[tmp]++;
    }
    sort(a,a+n);
    dfs(0,N,a);
    return 0;
}
