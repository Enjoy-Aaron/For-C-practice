#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX(a,b) (a>b? a:b)
using namespace std;
typedef long long ll;
const int MAXN=1010;
char s1[MAXN],s2[MAXN];
ll dp[MAXN][MAXN];

int main()
{
    scanf("%s%s",s1,s2);
    int n=strlen(s1),m=strlen(s2);
    for (int i=0;i<=m;++i) dp[0][i]=0;
    for (int i=0;i<=n;++i) dp[i][0]=0;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            if (s1[i]==s2[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = MAX(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    printf("%lld",dp[n][m]);
    return 0;
}
