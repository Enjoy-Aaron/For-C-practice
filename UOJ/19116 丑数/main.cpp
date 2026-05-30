#include <iostream>
#include <cstdio>
#include <set>
#define MAX(a,b) (a>b? a:b)
#define MIN(a,b) (a<b? a:b)
using namespace std;
const int MAXN = 1e5+10;
typedef long long ll;

int main()
{
    int T,t[MAXN]={},max_i=0;
    scanf("%d",&T);
    for (int i=0;i<T;++i) {
        scanf("%d",t+i);
        max_i = MAX(max_i, t[i]);
    }
    set<ll> nums;
    nums.insert(1);
    int a[3]={2,3,5};
    int idx=0,cnt=0;
    for (auto it : nums) {
        idx++;
        if (idx>max_i) break;
        if (idx==t[cnt]) {
            printf("%lld\n",it);
            cnt++;
        }
        for (int i=0;i<3;++i) {
            nums.insert(it*a[i]);
        }
    }
    return 0;
}
