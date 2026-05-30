#include <iostream>
#include <cstdio>
#define MIN(a,b) (a<b? a:b)
using namespace std;
const int MAXSIZE = 100, INF = 1e6+10;
int T,n,rec[MAXSIZE];
int a,b,l,ans,total;

void dfs(int dep,int a,int b,int l)
{
    if (l >= ans) return;
    int remain = total - a - b - l;
    if (abs(a-b) > remain) return;
    if (dep > n) {
        if (a==b) ans = MIN(ans,l);
        return;
    }
    dfs(dep+1,a+rec[dep],b,l);
    dfs(dep+1,a,b+rec[dep],l);
    dfs(dep+1,a,b,l+rec[dep]);
    return;
}

int main()
{
    scanf("%d",&T);
    while (T--) {
        a=0;b=0;l=0;ans=INF;
        total=0;
        scanf("%d",&n);
        for (int i=1;i<=n;++i) {
            scanf("%d",&rec[i]);
            total += rec[i];
        }
        dfs(1,0,0,0);
        printf("%d\n",ans);
    }
    return 0;
}
