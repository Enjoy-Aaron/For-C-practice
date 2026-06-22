#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;
map<ll, ll> dp;

ll solve(ll n) {
    if (n==1 || n==2) return n;
    if (n==3) return 0;
    if (dp.find(n/2) == dp.end()) dp[n/2] = solve(n/2);
    if (dp.find((n+1)/2) == dp.end()) dp[(n+1)/2] = solve((n+1)/2);
    dp[n] = dp[n/2] + dp[(n+1)/2];
    return dp[n];
}

int main() {
    ll n;
    while (scanf("%lld",&n) == 1 && n!=0) {
        printf("%lld\n",solve(n));
    }
    return 0;
}