#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX(a, b) (a>b ? a:b)
#define MIN(a, b, c) (c<(a<b ? a:b) ? c:(a<b ? a:b))
using namespace std;
typedef long long ll;
const int MAXN = 1e5+10;
char s1[MAXN], s2[MAXN];
int dp[MAXN][MAXN];

int main() {
    scanf("%s%s",s1,s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for (int i=0;i<=len1;++i) {
        dp[i][0] = i;
    }
    for (int i=0;i<=len2;++i) {
        dp[0][i] = i;
    }
    for (int i=1;i<=len1;++i) {
        for (int j=1;j<=len2;++j) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = MIN(dp[i-1][j-1] + 1, dp[i-1][j] + 1, dp[i][j-1] + 1);
            }
        }
    }
    printf("%d\n",dp[len1][len2]);
    return 0;
}