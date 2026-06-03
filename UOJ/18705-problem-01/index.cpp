#include <iostream>
#include <cstdio>
using namespace std;

#define MAX(a, b) (a>b? a:b)

const int MAXN = 1e6+10;
int dp[MAXN], v[MAXN], w[MAXN];

int main() {
    int c,n;
    scanf("%d%d",&c,&n);
    for (int i=0;i<n;++i) scanf("%d%d",&w[i],&v[i]);
    for (int i=0;i<n;++i) {
        for (int j=c;j>=w[i];--j) {
            dp[j] = MAX(dp[j], dp[j-w[i]] + v[i]);
        }
    }
    printf("%d\n",dp[c]);
    return 0;
}