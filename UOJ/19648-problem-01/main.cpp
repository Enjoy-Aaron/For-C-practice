#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

int main() {
    ll k;
    while (scanf("%lld",&k) == 1 && k != 0) {
        for (ll z = k + 1; z <= 3 * k; ++z) {
            ll s = 2 * k * z / (z - k);
            for (ll y = z; y <= s; ++ y) {
                ll den = y * z - k * (y + z);
                if (den <= 0) continue;
                ll x = k * y * z / den;
                if (x >= y && x * den == k * y * z) {
                    printf("1/%lld=1/%lld+1/%lld+1/%lld\n",k,x,y,z);
                }
            }
        }
        printf("\n");
    }
    return 0;
}