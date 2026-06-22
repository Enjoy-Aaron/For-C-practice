#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    char a[50]={};
    while (scanf("%lld",&n) == 1 && n != 0) {
        for (int y=1; y<=98765; ++y) {
            ll x = n * y;
            sprintf(a,"%05lld%05lld",x,y);
            if (strlen(a) > 10) break;
            bool vis[256]={}, flag=1;
            for (int i=0; i<10; ++i) {
                if (a[i]=='0') continue;
                if (vis[a[i]]) {
                    flag = 0;
                    break;
                }
                vis[a[i]] = 1;
            }
            if (flag == 1) {
                printf("%05lld/%05lld=%lld\n",x,y,n);
            }
        }
        printf("\n");
    }
    return 0;
}