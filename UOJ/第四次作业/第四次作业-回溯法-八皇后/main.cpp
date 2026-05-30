#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 110;
long long tot;
int vis[2][2 * MAXN];

void Search(int n, int cur)
{
    if (cur==n) {
        tot++;
        return;
    }
    for (int i=0; i<n; ++i) {
        if (vis[0][i] || vis[1][i+cur] || vis[2][i-cur+n]) continue;
        vis[0][1] = vis[1][i+cur] = vis[2][i-cur+n] = 1;
        Search(n, cur+1);
        vis[0][1] = vis[1][i+cur] = vis[2][i-cur+n] = 0;
    }
    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    Search(n, 0);
    printf("%lld\n",tot);
    return 0;
}
