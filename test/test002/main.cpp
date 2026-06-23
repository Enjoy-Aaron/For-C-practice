/**
    ¿ìËÙÃİ
**/
#include <bits/stdc++.h>
#define r read()
#define MAX(a,b) (a>b? a:b)
#define MIN(a,b) (a<b? a:b)
using namespace std;
typedef unsigned long long ll;

inline int read()
{
    register int f=0,x=0;
    register char ch=getchar();
    while (ch<48 || ch>57) f|= ch=='-',ch=getchar();
    while (ch>=48 && ch<=57) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return f? -x:x;
}

ll powResult(ll a,int b)
{
    ll ans=1;
    while (b){
        if (b&1){
            ans*=a;
        }
        a*=a;
        b>>=1;
    }
    return ans;
}

int main()
{
    int a,b;
    a=r;b=r;
    ll ans=powResult(a,b);
    printf("%llu",ans);
    return 0;
}
