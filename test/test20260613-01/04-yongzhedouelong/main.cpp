#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, m;
    while (scanf("%d%d",&n,&m)==2) {
        if (n==0 && m==0) break;
        priority_queue<int, vector<int>, greater<int> > lon, qis;
        for (int i=0;i<n;++i) {
            int tmp;
            scanf("%d",&tmp);
            lon.push(tmp);
        }
        for (int i=0;i<m;++i) {
            int tmp;
            scanf("%d",&tmp);
            qis.push(tmp);
        }
        int ans=0;
        while(!lon.empty() && !qis.empty()) {
            int q = qis.top();
            int l = lon.top();
            if (q >= l) {
                qis.pop();
                lon.pop();
                ans += q;
            }
            else {
                qis.pop();
            }
        }
        if (lon.empty()) {
            printf("%d\n",ans);
        }
        else {
            printf("Loowater is doomed!\n");
        }
    }
    return 0;
}