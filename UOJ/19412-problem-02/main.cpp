#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 10;
int n, a[MAXN];

void solve(int dep, int A[], bool vis[]) {
    if (dep == n) {
        for (int i=0; i<n; ++i) {
            printf("%d ",a[A[i]]);
        }
        printf("\n");
        return;
    }
    for (int i=0; i<n; ++i) {
        if (vis[i]) continue;
        vis[i] = 1;
        A[dep] = i;
        solve(dep+1, A, vis);
        vis[i] = 0;
    }
    return;
}

void Solve() {
    int A[MAXN]={};
    bool vis[MAXN] = {};
    solve(0, A, vis);
}

int main() {
    scanf("%d",&n);
    for (int i=0; i<n; ++i) {
        scanf("%d",&a[i]);
    }
    sort(a, a+n);
    Solve();
    return 0;
}