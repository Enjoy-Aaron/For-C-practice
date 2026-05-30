#include <iostream>
#include <cstdio>
#include <set>
#include <cmath>
#define MAX(a,b) (a>b? a:b)
#define MIN(a,b) (a<b? a:b)
using namespace std;
const int MAXN = 20, INF=1e5;
bool isv[MAXN];
int a[5][MAXN];
int n,ans=INF;
set<int> sum[5];

void solve(int num,int dep,int sumL)
{
    if (dep == n) return;
    for (int i=1;i<=n;++i) {
        if (isv[i]) continue;
        isv[i] = 1;
        sum[num].insert(sumL+a[num][i]);
        solve(num,dep+1,sumL+a[num][i]);
        isv[i] = 0;
    }
    return;
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=4;++i) {
        for (int j=1;j<=n;++j) {
            scanf("%d",&a[i][j]);
        }
    }
    solve(1,0,0);solve(2,0,0);solve(3,0,0);solve(4,0,0);
    set<int>::iterator it[5];
    for (int i=1;i<=4;++i) {
        it[i] = sum[i].begin();
    }
    while (1) {
        bool flag = 0;
        for (int i=1;i<=4;++i) {
            if (it[i] == sum[i].end()) {
                flag = 1;
                break;
            }
        }
        if (flag) break;
        int max_i = 1, min_i = 1;
        for (int i=1;i<=4;++i) {
            if (*it[max_i] < *it[i]) {
                max_i = i;
            }
            if (*it[min_i] > *it[i]) {
                min_i = i;
            }
        }
        ans = MIN(ans, *it[max_i]-*it[min_i]);
        it[min_i]++;
    }
    printf("%d",ans);
    return 0;
}
