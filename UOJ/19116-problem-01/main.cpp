#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX(a,b) (a>b? a:b)
using namespace std;
const int MAXN = 1e5+10;
typedef long long ll;
ll dp[MAXN];
int t[MAXN],maxn;

int main() {
    int T;
    scanf("%d",&T);
    for (int i=0; i<T; ++i) {
        scanf("%d",&t[i]);
        maxn = MAX(maxn, t[i]);
    }
    dp[1] = 1;
    int p2=1, p3=1, p5=1;
    for (int i=2; i<=maxn;++i) {
        ll nn2 = dp[p2] * 2;
        ll nn3 = dp[p3] * 3;
        ll nn5 = dp[p5] * 5;
        dp[i] = min({nn2, nn3, nn5});
        if (dp[i] == nn2) p2++;
        if (dp[i] == nn3) p3++;
        if (dp[i] == nn5) p5++;
    }
    for (int i=0; i<T; ++i) {
        printf("%lld\n", dp[t[i]]);
    }
    return 0;
}