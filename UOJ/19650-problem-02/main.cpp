#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
const int MAXN = 110;
int n, a[MAXN], A[MAXN], tot;
map<int, int> cnt;

void solve(int dep) {
    if (dep == n) {
        for (int i=0; i<n; ++i) {
            printf("%d ", a[A[i]]);
        }
        printf("\n");
        return;
    }
    for (int i=0; i<tot; ++i) {
        if (cnt[a[i]] == 0) continue;
        if (dep>0 && a[A[dep-1]]%2==1 && a[i] % 2 ==1) continue;
        cnt[a[i]]--;
        A[dep] = i;
        solve(dep+1);
        cnt[a[i]]++;
    }
}

int main() {
    scanf("%d",&n);
    for (int i=0; i<n; ++i) {
        int temp;
        scanf("%d",&temp);
        if (cnt.find(temp) == cnt.end()) {
            a[tot++] = temp;
            cnt[temp] = 1;
        }
        else cnt[temp]++;
    }
    sort(a, a+tot);
    solve(0);
    return 0;
}