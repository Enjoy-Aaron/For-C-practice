#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int MAXN = 2e6+10;

int main() {
    int n,m,tmp;
    while (scanf("%d%d",&n,&m)==2 && !(n==0 && m==0)) {    
        priority_queue<int, vector<int>, greater<int> > qishi, longtou;
        for (int i=0;i<n;++i) {
            scanf("%d",&tmp);
            longtou.push(tmp);
        }
        for (int i=0; i<m; ++i) {
            scanf("%d",&tmp);
            qishi.push(tmp);
        }
        int ans = 0;
        while (!qishi.empty() && !longtou.empty()) {
            int qt = qishi.top();qishi.pop();
            int lt = longtou.top();
            if (qt >= lt) {
                ans += qt;
                longtou.pop();
            }
        }
        if (longtou.empty()) {
            printf("%d\n",ans);
        }
        else {
            printf("Loowater is doomed!\n");
        }
    }
    return 0;
}