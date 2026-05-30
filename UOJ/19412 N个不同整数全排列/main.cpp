#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100;

void dfs(int *S, int n, int *A,int dep,int *vis)
{
    if (dep == n) {
        for (int i=0;i<n;++i)
            printf("%d ",S[A[i]]);
        printf("\n");
    }
    for (int i=0;i<n;++i) {
        if (!vis[i]) {
            vis[i]=1;
            A[dep]=i;
            dfs(S, n ,A,dep+1,vis);
            vis[i]=0;
        }
    }
    return;
}

int main()
{
    int N;
    int S[MAXN]={},A[MAXN]={},vis[MAXN]={};
    scanf("%d",&N);
    for (int i=0;i<N;++i) {
        scanf("%d",S+i);
    }
    sort(S, S+N);
    dfs(S,N,A,0,vis);
    return 0;
}
