#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX(a,b) (a>b? a:b)
using namespace std;
const int MAXN = 100;
int n, a[MAXN], maxn, tot;
bool vis[MAXN];

void dfs(int cnt, int sum, bool& flag, int kn, int k) {
    if (flag == 1) return;
    if (sum == 0) {
        sum = kn;
        cnt++;
    }
    if (cnt == k-1) {
        flag = 1;
        return;
    }
    for (int i=0; i<n; ++i) {
        if (vis[i]) continue;
        if (a[i] > sum) continue;
        if (i>0 && a[i]==a[i-1] && !vis[i-1]) continue;
        vis[i] = 1;
        dfs(cnt, sum-a[i], flag, kn, k);
        vis[i] = 0;
        if (sum == kn && flag == 0) return;
    }
}

bool cmp(const int &a, const int &b) {
    return a >= b;
}

int main() {
    scanf("%d",&n);
    for (int i=0; i<n; ++i) {
        scanf("%d",&a[i]);
        tot += a[i];
        maxn = MAX(maxn, a[i]);
    }
    sort(a, a+n, cmp);
    for (int kn = maxn; kn <= tot; ++kn) {
        if (tot % kn != 0) continue;
        int k = tot / kn;
        bool flag = 0;
        dfs(0, kn, flag, kn, k);
        if (flag) {
            printf("%d\n",k);
            break;
        }
    }
    return 0;
}