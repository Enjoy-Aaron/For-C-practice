#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int vis[10100];
void dfs(int dep, int n, int a[], int A[]) {
    if (dep == n) {
        for (int i=0;i<n;++i) printf("%d ",a[A[i]]);
        printf("\n");
        return;
    }
    for (int i=0;i<n;++i) {
        if (vis[i] == 1) continue;
        vis[i] = 1;
        A[dep] = i;
        dfs(dep+1, n, a, A);
        vis[i] = 0;
    }
}

int main() {
    int n;
    scanf("%d",&n);
    int a[10100]={};
    for (int i=0; i<n; ++i) {
        scanf("%d",&a[i]);
    }
    int A[10100]={};
    sort(a, a+n);
    dfs(0, n, a, A);
    return 0;
}