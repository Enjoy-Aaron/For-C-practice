#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll pown(ll a,int b)
{
    ll res=1;
    while (b){
        if (b&1){
            res*=a;
        }
        a*=a;
        b>>=1;
        printf("%llu\n",res);
    }
    return res;
}

int main()
{
    ll res=pown(2,63);
    printf("%llu",res);
    return 0;
}
