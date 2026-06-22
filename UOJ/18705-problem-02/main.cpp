#include <iostream>
#include <cstdio>
#define MAX(a,b) (a>b? a:b)
using namespace std;
int dp[1010][1010], w[1010], v[1010];

int main() {
    int c, n;
    scanf("%d%d",&c,&n);
    for (int i=1; i<=n; ++i) {
        scanf("%d%d",&w[i],&v[i]);
    }
    for (int i=1; i<=n; ++i) {
        for (int j=c; j>=0; j--) {
            if (j>=w[i])
                dp[i][j] = MAX(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    printf("%d\n",dp[n][c]);
    return 0;
}