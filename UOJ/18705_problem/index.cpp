#include <cstdio>
#include <iostream>
#define MAX(a,b) (a>b? a:b)
using namespace std;
const int MAXN = 1e7;
int dp[MAXN], w[MAXN], v[MAXN];

int main()
{
    int n, c;
    scanf("%d%d",&c,&n);
    for (int i=0;i<n;++i) scanf("%d%d",&w[i],&v[i]);
    for (int i=0;i<n;++i) {
        for (int j=c;j>=w[i];j--) {
            dp[j] = MAX(dp[j], dp[j-w[i]] + v[i]);
        }
    }
    printf("%d\n",dp[c]);
    return 0;
}