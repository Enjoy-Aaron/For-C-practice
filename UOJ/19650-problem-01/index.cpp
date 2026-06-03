#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
const int MAXN = 10010;
int A[MAXN], s[MAXN];
map<ll, int> cnt;

void DFS(int dep, int n, int len) {
    if (dep == n) {
        for (int i=0; i<n; ++i) {
            printf("%d ", s[A[i]]);
        }
        printf("\n");
    }
    for (int i=0; i<len; ++i) {
        if (cnt[s[i]] == 0) continue;
        if (dep>0 && s[A[dep-1]] % 2 == 1 && s[i] % 2 ==1) continue;
        A[dep] = i;
        cnt[s[i]]--;
        DFS(dep+1, n, len);
        cnt[s[i]]++;
    }
}

int main() {
    int n, len=0;
    scanf("%d",&n);
    for (int i=0;i<n;++i) {
        ll tmp;
        scanf("%lld",&tmp);
        if (cnt.find(tmp) == cnt.end()) {
            cnt[tmp] = 1;
            s[len++] = tmp;
        }
        else cnt[tmp]++;
    }
    sort(s, s+len);
    DFS(0, n, len);
    return 0;
}