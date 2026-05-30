#include <iostream>
#include <cstdio>
#define MAX(a,b) (a>b? a:b)
using namespace std;
typedef long long ll;
const int MAXN=1e7;
int a[MAXN],dp[MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    for (int i=1;i<=n;++i) dp[i]=1;
    for (int i=2;i<=n;++i) {
        for (int j=1;j<i;++j) {
            if (a[j] < a[i]) {
                dp[i]=MAX(dp[i], dp[j]+1);
            }
        }
    }
    int maxn=0;
    for (int i=1;i<=n;++i) {
        maxn=MAX(maxn,dp[i]);
    }
    printf("%d\n",maxn);
    return 0;
}
