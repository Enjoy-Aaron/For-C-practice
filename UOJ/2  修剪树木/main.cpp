#include <iostream>
#include <cstdio>
#define MAX(a,b) (a>b? a:b)
#define MIN(a,b) (a<b? a:b)
using namespace std;
typedef long long ll;
int t[100010];
ll S[100010],ans=1e18;

bool check(ll mid, int n , int m)
{
    int pos = 0,cnt=1;
    for (int i=1;i<=n;++i) {
        if (S[i]-S[pos] > mid) {
            cnt++;
            pos=i-1;
            if (cnt>m) return false;
        }
    }
    return true;
}

int main()
{
    int n,m;
    ll left=0,right=1e10,mid;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i){
        scanf("%d",&t[i]);
        S[i]=S[i-1]+t[i];
        left = MAX(left, (ll)t[i]);
    }
    while (left<right) {
        mid = left+(right-left)/2;
        if (check(mid,n,m)) {
            right=mid;
        }
        else {
            left = mid+1;
        }
    }
    ans = left;
    printf("%lld\n",ans);
    return 0;
}
