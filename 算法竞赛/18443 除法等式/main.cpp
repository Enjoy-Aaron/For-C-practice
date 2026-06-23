#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAXN = 256;

int v[MAXN];
char c[MAXN];

int main()
{
    ll n;
    while (scanf("%lld",&n)==1 && n!=0) {
        for (ll b=1;b<=98765;++b) {
            ll a = b*n;
            if (a>98765) break;
            sprintf(c,"%05lld%05lld",a,b);
            if (strlen(c)>10) break;
            memset(v,0,sizeof(v));
            int flag = 1;
            for (int i=0;i<10;++i) {
                if (c[i]=='0') continue;
                if (v[c[i]]==0) {
                    v[c[i]] = 1;
                }
                else {
                    flag=0;
                    break;
                }
            }
            if (flag) {
                printf("%05lld/%05lld=%lld\n",a,b,n);
            }
        }
        printf("\n");
    }
    return 0;
}
