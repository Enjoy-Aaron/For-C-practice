#include <iostream>
#include <cstdio>
#define MAX(a,b) (a>b? a:b)
using namespace std;
typedef long long ll;
int a[10100],dp[10100];

int main()
{
    int n;
    while (scanf("%d",&n)==1 && n!=0) {
        for (int i=1;i<=n;++i) {
            scanf("%d",&a[i]);
            dp[i]=1;
        }
        for (int i=2;i<=n;++i) {
            for (int j=1;j<i;++j) {
                if (a[j]<a[i]) {
                    dp[i]=MAX(dp[i],dp[j]+1);
                }
            }
        }
        int maxn = 0;
        for (int i=1;i<=n;++i) maxn=MAX(maxn, dp[i]);
        printf("%d\n",maxn);
    }
    return 0;
}
