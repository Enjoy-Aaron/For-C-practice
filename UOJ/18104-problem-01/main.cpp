#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if (a==0) return b;
    if (b==0) return a;
    ll n = a%b;
    while (n) {
        a = b;
        b = n;
        n = a%b;
    }
    return b;
}

int main() {
    int T;
    ll a,b;
    scanf("%d",&T);
    while (T--) {
        scanf("%lld%lld",&a,&b);
        ll res = a*b;
        printf("%lld\n", res/gcd(a,b));
    }
    printf("group 1 done\n");

    while (scanf("%lld%lld",&a,&b) == 2 && !(a==0 && b==0)) {
        ll res = a*b;
        printf("%lld\n", res/gcd(a,b));
    }
    printf("group 2 done\n");

    while (scanf("%lld%lld",&a,&b)==2) {
        ll res = a*b;
        printf("%lld\n", res/gcd(a,b));
    }
    printf("group 3 done\n");
}
