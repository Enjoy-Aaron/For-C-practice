#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    ll r = a%b;
    while (r) {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main()
{
    int T;
    ll a,b;
    cin >> T;
    while (T--) {
        scanf("%lld%lld",&a,&b);
        cout << a*b/gcd(a,b) << endl;
    }
    printf("group 1 done\n");;
    while (scanf("%lld%lld",&a,&b) && a!=0 && b!=0) {
        cout << a*b/gcd(a,b) << endl;
    }
    printf("group 2 done\n");
    while (scanf("%lld%lld",&a,&b) == 2) {
        cout<<a*b/gcd(a,b)<<endl;
    }
    printf("gruop 3 done\n");
    return 0;
}
