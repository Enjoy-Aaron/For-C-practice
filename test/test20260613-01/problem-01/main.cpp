#include <iostream>
#include <cstdio>
#define MAX(a,b) (a>b? a:b)
using namespace std;
const int MAXN = 1010;
int c, n;
int dp[MAXN],v[MAXN],w[MAXN];

int main() {
    scanf("%d%d",&c, &n);
    for (int i=1;i<=n;++i) {
        scanf("%d%d",&w[i],&v[i]);
    }
    for (int i=1;i<=n;++i) {
        for (int j=c; j>=w[i]; j--) {
            dp[j] = MAX(dp[j], dp[j-w[i]] + v[i]);
        }
    }
    printf("%d",dp[c]);
    return 0;
}