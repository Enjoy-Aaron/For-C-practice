#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 45;
int n;
bool is_prime[MAXN];
int ans[MAXN];
bool isv[MAXN];

void get_prime(int x)
{
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i=2;i<=x;++i) {
        if (is_prime[i]) {
            for (int j=i*i; j<=x; j+=i) {
                is_prime[j] = false;
            }
        }
    }
    return;
}

bool dfs(int cur)
{
    if (cur == n) {
        if (is_prime[ans[n-1] + ans[0]]) return true;
        return false;
    }

    for (int i=2;i<=n;++i) {
        if (!isv[i] && is_prime[ans[cur-1]+i]) {
            isv[i] = true;
            ans[cur] = i;
            if (dfs(cur+1)) return true;
            isv[i] = false;
        }
    }
    return false;
}

int main()
{
    scanf("%d",&n);
    get_prime(n<<1);
    ans[0] = 1;
    isv[1] = true;
    if (dfs(1)) {
        for (int i=0;i<n;++i) printf("%d ",ans[i]);
        printf("\n");
    }
    else printf("-1\n");
    return 0;
}
