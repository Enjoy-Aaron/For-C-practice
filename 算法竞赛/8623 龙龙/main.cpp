#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

ll H(int n)
{
    ll res = 0;
    ll l=1;
    while (l<=n) {
        ll k=n/l;
        ll r=n/k;
        res += (r-l+1) * k;
        l=r+1;
    }
    return res;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        ll n;
        scanf("%lld",&n);
        printf("%lld\n",H(n));
    }
    return 0;
}
