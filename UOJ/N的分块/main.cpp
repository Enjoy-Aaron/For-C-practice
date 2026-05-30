#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

int main()
{
    ll T,n;
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld",&n);
        ll l=1,r,k,tot=0;
        while (l<=n) {
            k = n/l;
            r = n/k;
            tot += (r-l+1)*k;
            l = r+1;
        }
        printf("%lld\n",tot);
    }
    return 0;
}
