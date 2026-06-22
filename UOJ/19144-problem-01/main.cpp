#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

bool solve(ll n, ll idx) {
    if (n==1 || n==2) return false;
    if (n==3) return true;
    if (idx%2==0) return solve(n/2, idx/2);
    else return solve((n+1)/2, (idx+1)/2);
}

int main() {
    ll n, idx;
    while (scanf("%lld%lld",&n, &idx) == 2 && n!=0 && idx!=0) {
        if (solve(n, idx)) {
            printf("Y\n");
        }
        else printf("N\n");
    }
    return 0;
}