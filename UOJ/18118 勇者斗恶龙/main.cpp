#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 2e6+10;

priority_queue<int, vector<int>, greater<int> > pql,pqq;

int main()
{
    int temp,n,m;
    while (scanf("%d%d",&n,&m)) {
        if (n==0 && m==0) break;
        long long tot=0;
        while (!pql.empty()) pql.pop();
        while (!pqq.empty()) pqq.pop();
        for (int i=0;i<n;++i) {
            scanf("%d",&temp);
            pql.push(temp);
        }
        for (int i=0;i<m;++i) {
            scanf("%d",&temp);
            pqq.push(temp);
        }
        if (n>m) {
            printf("Loowater is doomed!\n");
            continue;
        }
        while (!pql.empty() && !pqq.empty()) {
            int ls = pql.top();
            int qs = pqq.top();
            if (qs >= ls) {
                tot+=qs;
                pql.pop();
            }
            pqq.pop();
        }
        if (pql.empty()) printf("%lld\n",tot);
        else printf("Loowater is doomed!\n");
    }
    return 0;
}
