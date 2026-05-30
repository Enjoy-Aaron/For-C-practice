#include <iostream>
#include <cstdio>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
using namespace std;
const int MAXN = 310, INF = 0x3f3f3f3f;

int main()
{
    int n, m[MAXN], s[MAXN][MAXN], dp[MAXN][MAXN];
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        scanf("%d", &m[i]);
    }
    for (int i=0; i<n; ++i) {
        s[i][i] = m[i];
        for (int j=i+1; j<n; ++j) {
            s[i][j] = s[i][j-1] + m[j];
        }
    }
    for (int i=0; i<n; ++i) {
        dp[i][i] = 0;
        for (int j=i+1; j<n; ++j) {
            dp[i][j] = INF;
        }
    }
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            for (int k=i; k<j; ++k) {
                dp[i][j] = MIN(dp[i][j], dp[i][k] + dp[k+1][j] + s[i][j]);
            }
        }
    }
    printf("%d\n", dp[0][n-1]);
    return 0;
}