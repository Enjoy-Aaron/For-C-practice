#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

ll H(ll n) {
    ll l=1, r, k, res = 0;
    while (l<=n) {
        k = n / l;
        r = n / k;
        res += (r-l+1) * k;
        l = r + 1;
    }
    return res;
}

int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        ll tmp;
        scanf("%lld",&tmp);
        printf("%lld\n",H(tmp));
    }
    return 0;
}