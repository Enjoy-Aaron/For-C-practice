#include <iostream>
#include <cstdio>
using namespace std;
int n,app[20];
bool isv[20];

void dfs(int dep)
{
    if (dep == n) {
        for (int i=1;i<=n;++i) {
            printf("%d ",app[i]);
        }
        printf("\n");
        return;
    }
    for (int i=1;i<=n;++i) {
        if (!isv[i]) {
            isv[i] = 1;
            app[dep+1]=i;
            dfs(dep +1 );
            isv[i]=0;
        }
    }
    return;
}

int main()
{
    scanf("%d",&n);
    dfs(0);
    return 0;
}
