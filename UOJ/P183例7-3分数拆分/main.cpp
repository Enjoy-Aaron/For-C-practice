#include <iostream>
#include <cstdio>
using namespace std;
typedef unsigned long long ll;

int main()
{
    ll k;
    scanf("%lld",&k);
    for (ll y=k+1;y<=2*k;++y) {
        if (k*y % (y-k) == 0) {
            ll x = k*y/(y-k);
            printf("1/%lld=1/%lld+1/%lld\n",k,x,y);
        }
    }
    return 0;
}
