#include <iostream>
#include <cstdio>
#define MIN(a,b) (a<b? a:b)
using namespace std;
typedef long long ll;

int main()
{
    int n;
    while (1) {
        scanf("%d",&n);
        if (n==0) break;
        ll res = 1;
        while (res*2 <= n) res<<=1;
        ll res2 = res*2;
        int d = MIN(n-res, res2-n);
        ll ans = n - 3*d;
        printf("%lld\n",ans);
    }
    return 0;
}
