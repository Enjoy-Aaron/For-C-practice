#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    scanf("%lld",&n);
    for (ll y=n+1; y<=2*n; ++y) {
        ll x = (y*n) / (y-n);
        if (n*(x+y) == (x*y)) {
            printf("1/%lld=1/%lld+1/%lld\n",n,x,y);
        }
    }
    return 0;
}