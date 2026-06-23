#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX(a, b) (a>b? a:b)
#define MIN(a, b) (a<b? a:b)
using namespace std;
const int MAXN = 1010;
int dp[MAXN][MAXN];

int main() {
    char s1[MAXN], s2[MAXN];
    scanf("%s%s",s1,s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for (int i=1; i<=len1; ++i) {
        for (int j=1; j<=len2; ++j) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = MAX(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    printf("%d\n", dp[len1][len2]);
    return 0;
}