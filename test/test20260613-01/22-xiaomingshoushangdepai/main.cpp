#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
priority_queue<int, vector<int>, greater<int> > pq;

int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i) {
        int tmp;
        scanf("%d",&tmp);
        if (i>m) {
            pq.pop();
            pq.push(tmp);
        }
        else pq.push(tmp);
    }
    printf("%d\n",pq.top());
    return 0;
}