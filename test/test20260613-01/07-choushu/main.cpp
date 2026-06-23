#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX(a,b) (a>b? a:b)
using namespace std;
const int MAXN = 100001;
typedef long long ll;
int T[MAXN], dp[MAXN];

int main() {
    int t, maxn=0;
    scanf("%d",&t);
    for (int i=1;i<=t;++i) {
        scanf("%d",&T[i]);
        maxn = MAX(maxn, T[i]);
    }
    int n2=1, n3=1, n5=1;
    dp[1] = 1;
    int n=2;
    while (n<=maxn) {
        ll nn2 = dp[n2] * 2;
        ll nn3 = dp[n3] * 3;
        ll nn5 = dp[n5] * 5;
        dp[n] = min({nn2, nn3, nn5});
        if (dp[n] == nn2) n2++;
        if (dp[n] == nn3) n3++;
        if (dp[n] == nn5) n5++;
        n++;
    }
    for (int i=1; i<=t; ++i) {
        printf("%lld\n", dp[T[i]]);
    }
    return 0;
}