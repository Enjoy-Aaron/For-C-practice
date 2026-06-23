#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
const int MAXN = 110;
typedef long long ll;
ll a[MAXN];
int n, cnt;
map<ll, int> cou;

void solve(int dep, int *A) {
    if (dep == n) {
        for (int i=0;i<n;++i) printf("%lld ",a[A[i]]);
        printf("\n");
        return;
    }
    for (int i=0;i<cnt; ++i) {
        if (cou[a[i]]==0) continue;
        if (dep>0 && a[A[dep-1]]%2==1 && a[i]%2==1) continue;
        cou[a[i]]--;
        A[dep] = i;
        solve(dep+1,A);
        cou[a[i]]++;
    }
}

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;++i) {
        ll tmp;
        scanf("%lld",&tmp);
        if (cou.find(tmp) == cou.end()) {
            cou[tmp]=1;
            a[cnt++] = tmp;
        }
        else cou[tmp]++;
    }
    sort(a, a+cnt);
    int A[MAXN]={};
    solve(0, A);
    return 0;
}