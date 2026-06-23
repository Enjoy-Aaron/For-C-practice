#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;
map<int ,ll> dp;

ll solve(int n) {
    if (n==1 || n==2) return 0;
    if (n==3) return 1;
    if (dp.find(n/2) == dp.end()) dp[n/2] = solve(n/2);
    if (dp.find((n+1)/2) == dp.end()) dp[(n+1)/2] = solve((n+1)/2);
    dp[n] = dp[n/2] + dp[(n+1)/2];
    return dp[n];
}

int main() {
    int n;
    while (scanf("%d",&n)==1 && n!=0) {
        ll ans = solve(n);
        printf("%lld\n", ans);
    }
    return 0;
}