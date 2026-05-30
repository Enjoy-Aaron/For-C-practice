#include <iostream>
#include <cstdio>
#define MAX(a,b) (a>b? a:b)
using namespace std;
typedef long long ll;
ll c,n,w[10010],v[10010],dp[1000010];

int main()
{
    scanf("%lld%lld",&c,&n);
    for (int i=1;i<=n;++i) {
        scanf("%lld%lld",&w[i],&v[i]);
    }
    for (int i=1;i<=n;++i) {
        for (int j=c;j>=w[i];j--) {
            dp[j]=MAX(dp[j], dp[j-w[i]]+v[i]);
        }
    }
    printf("%lld\n",dp[c]);
    return 0;
}
