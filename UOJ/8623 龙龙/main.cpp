#include <iostream>
#include <cstdio>
using namespace std;

long long H(int n){
    long long res = 0;
    int l = 1, r=1;
    while (l <= n) {
        int k = n / l;
        r = n / k;
        res += (r-l+1LL )*k;
        l = r + 1;
    }
    return res;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        printf("%lld\n",H(n));
    }
    return 0;
}
