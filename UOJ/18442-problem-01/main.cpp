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
    ll n;
    while (scanf("%lld",&n) == 1 && n!=0) {
        bool flag = false;
        for (int i=1; i<=n; ++i) {
            if (!solve(n, i)) {
                printf("%d\n",i);
                flag = true;
                break;
            }
        }
        if (flag==false) printf("0\n");
    }
    return 0;
}