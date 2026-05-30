#include <iostream>
#include <cstdio>
#include <deque>
#define MAX(a,b) (a>b? a:b)
#define MIN(a,b) (a<b? a:b)
using namespace std;
const int MAXN = 3e5+10,INF=32767;
int d[MAXN];
deque<int> qmax,qmin;

int main()
{
    int n,k,ans = 0;
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;++i) {
            scanf("%d",&d[i]);
    }
    int i=1;
    for (int j=1;j<=n;++j) {
        while (!qmax.empty() && d[qmax.back()] <= d[j]) qmax.pop_back();
        while (!qmin.empty()  && d[qmin.back()] >= d[j]) qmin.pop_back();
        qmax.push_back(j);
        qmin.push_back(j);
        while (d[qmax.front()] - d[qmin.front()] > k) {
            if (qmax.front() == i) qmax.pop_front();
            if (qmin.front() == i) qmin.pop_front();
            i++;
        }
        ans = MAX(ans,j-i+1);
    }
    printf("%d\n",ans);
    return 0;
}
