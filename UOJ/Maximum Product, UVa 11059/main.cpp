#include <iostream>
#include <cstdio>
#define MAX(a,b) (a>b? a:b)
#define MIN(a,b) (a<b? a:b)
using namespace std;
typedef long long ll;
const int MAXN = 20;

int main()
{
    ll ans = 0;
    int n,s[MAXN]={};
    while (scanf("%d",&n) == 1) {
        for (int i=0;i<n;++i) scanf("%d",&s[i]);
        ans = 0;
        for (int i=0;i<n;++i) {
            ll current_product = 1;
            for (int j=i;j<n;++j) {
                if (s[j] <= s[j-1] && j!=i) break;
                current_product *= s[j];
                ans = MAX(ans,current_product);
            }
        }
        printf("%lld\n",ans);
    }

    return 0;
}
