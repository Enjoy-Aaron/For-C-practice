#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
const int mod = 1000000007;
typedef long long ll;
const int MAXN = 1010;
map<int,ll> A;

ll pow(ll a, ll b)
{
    ll res = 1;
    while (b) {
        if (b&1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b>>=1;
    }
    return res;
}

ll inv(int x)
{
    return pow(x, mod-2);
}

ll get_A(int n)
{
    if (n==1 || n==0) return 1;
    if (A.find(n-1) != A.end()) {
        return (1L * n * A[n-1]) % mod;
    }
    A[n] = (1L * n * get_A(n-1)) % mod;
    return A[n];
}

ll C(int n,int m)
{
    if (A.find(n) == A.end()) A[n] = get_A(n);
    if (A.find(m) == A.end()) A[m] = get_A(m);
    if (A.find(n-m) == A.end()) A[n-m] = get_A(n-m);
    return A[n] * inv(A[m]) % mod * inv(A[n-m]) % mod % mod;
}

int main()
{
    int n;
    A[0]=1;A[1]=1;A[2]=2;
    scanf("%d",&n);
    for (int m=1;m<=n;++m) {
        printf("%lld ", C(n-1,m-1));
    }
    printf("\n");
    return 0;
}
