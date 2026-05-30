#include <iostream>
#include <cstdio>
using namespace std;
int n,k,a[20],ans[20];
bool isv[20];

void dfs(int dep)
{
    if (dep == k) {
        for (int i=1;i<=k;++i) {
            printf("%d ",ans[i]);
        }
        printf("\n");
        return;
    }
    for (int i=ans[dep]==0? 1:ans[dep];i<=n;++i) {
        if (!isv[i]) {
            isv[i]=1;
            ans[dep+1] = i;
            dfs(dep+1);
            isv[i]=0;
        }
    }
    return;
}

int main()
{
    scanf("%d%d",&n,&k);
    dfs(0);
    return 0;
}
