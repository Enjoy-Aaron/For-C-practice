#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5+10;

void DFS(int dep, int n, int *A, int *a, int *vis) {
    if (dep == n) {
        for (int i=0; i<n; ++i) printf("%d ",a[A[i]]);
        printf("\n");
        return;
    }
    for (int i=0; i<n; ++i) {
        if (vis[i] == 1) continue;
        A[dep] = i;
        vis[i] = 1;
        DFS(dep+1, n, A, a, vis);
        vis[i] = 0;
    }
}

int main() {
    int a[MAXN], A[MAXN], vis[MAXN], n;
    scanf("%d",&n);
    for (int i=0;i<n;++i) scanf("%d",&a[i]);
    sort(a, a+n);
    DFS(0, n, A, a, vis);
    return 0;
}