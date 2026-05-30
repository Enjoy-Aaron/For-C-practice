#include <iostream>
#include <cstdio>
#define MAX(a,b) (a>b? a:b)
using namespace std;
const int MAXN = 100;

struct BiTNode {
    int data;
    int lchild;
    int rchild;
}BiTree[MAXN];

int TreeWidth[MAXN],ans;
void solve(int dep,int node)
{
    if (BiTree[node].data == 0) return;
    TreeWidth[dep]++;
    solve(dep+1,BiTree[node].lchild);
    solve(dep+1,BiTree[node].rchild);
    return;
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        BiTree[i].data = i;
        BiTree[i].lchild = 0;
        BiTree[i].rchild = 0;
    }
    for (int i=1;i<n;++i) {
        int x,y;
        scanf("%d%d",&x,&y);
        if (BiTree[x].lchild == 0) {
            BiTree[x].lchild = y;
        }
        else {

            BiTree[x].rchild = y;
        }
    }
    solve(1,1);
    for (int i=1;i<=n;++i) {
        ans = MAX(ans,TreeWidth[i]);
    }
    printf("%d\n",ans);
    return 0;
}
