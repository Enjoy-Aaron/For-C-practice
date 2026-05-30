#include <iostream>
#include <cstdio>
using namespace std;
int n,a[20];

void dfs(int cur, int sum)
{
    if (cur == n) return;
    printf("%d\n",sum+a[cur]);
    dfs(cur+1,sum+a[cur]);
    dfs(cur+1,sum);
    return;
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;++i) {
        scanf("%d",&a[i]);
    }
    dfs(0,0);
    return 0;
}
