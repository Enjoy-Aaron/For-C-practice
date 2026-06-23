#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1010;
typedef long long ll;
int vis[MAXN];

bool check(char *s, int len) {
    memset(vis, 0, sizeof(vis));
    for (int i=0; i<10; ++i) {
        if (s[i] == '0') continue;
        if (vis[s[i]]==1) return false;
        vis[s[i]] = 1;
    }
    return true;
}

int main() {
    ll n;
    char s[MAXN];
    while (scanf("%lld",&n)==1 && n!=0) {
        for (ll b = 1; b <= 98765; ++b) {
            ll a = b * n;
            sprintf(s, "%05lld%05lld", a, b);
            int len = strlen(s);
            if (len > 10) break;
            if (check(s, len)) {
                printf("%05lld/%05lld=%lld\n", a, b, n);
            }
        }
        printf("\n");
    }
    return 0;
}