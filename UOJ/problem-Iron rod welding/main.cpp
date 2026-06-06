#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
const int MAXN = 110;
int n;
bool visn[MAXN];
ll a[MAXN];
map<ll, bool> visit;
priority_queue<ll, vector<ll>, greater<ll> > ans;

void dfs(int dep, ll tot) {
    if (dep == n) {
        if (tot != 0 && visit.find(tot) == visit.end()) {
            visit[tot] = true;
            ans.push(tot);
        }
        return;
    }
    dfs(dep + 1, tot + a[dep]);
    dfs(dep + 1, tot);
}


int main() {
    scanf("%d",&n);
    for (int i=0;i<n;++i) {
        scanf("%lld", &a[i]);
    }
    dfs(0,0);
    while (!ans.empty()) {
        ll tmp = ans.top();
        ans.pop();
        printf("%lld ",tmp);
    }
    return 0;
}