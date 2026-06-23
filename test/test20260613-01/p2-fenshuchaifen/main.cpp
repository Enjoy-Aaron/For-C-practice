#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

int main() {
    ll k;
    scanf("%lld", &k);
    for (ll y=k+1; y<=2*k; ++y) {
        ll x = y*k / (y-k);
        if (x*y == k*(x+y)) {
            printf("1/%lld=1/%lld+1/%lld\n", k,x,y);
        }
    }
    return 0;
}