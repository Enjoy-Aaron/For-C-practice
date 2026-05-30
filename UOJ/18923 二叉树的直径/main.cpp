#include <iostream>
#include <cstdio>
#define MAX(a,b) (a>b? a:b)
using namespace std;
const int MAXN = 1e6+10;

struct BiTNode {
    int lchild;
    int rchild;
} BiTree[MAXN];
int fa[MAXN];

void GetTop(int e,int &top)
{
    if (fa[e] != 0) GetTop(fa[e],top);
    else {
        top = e;
    }
    return;
}

void GetDepth(int e,int &ans,int &dep)
{
    if (e==0) {
        dep = 0;
        return;
    }
    int ldep,rdep;
    GetDepth(BiTree[e].lchild,ans,ldep);
    GetDepth(BiTree[e].rchild,ans,rdep);
    ans = MAX(ans,ldep+rdep);
    dep = MAX(ldep,rdep) + 1;
    return;
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<n;++i) {
        int x,y;
        scanf("%d%d",&x,&y);
        fa[y]=x;
        if (BiTree[x].lchild == 0) BiTree[x].lchild = y;
        else BiTree[x].rchild = y;
    }
    int top;
    GetTop(1,top);
    int ans=0,dep;
    GetDepth(top,ans,dep);
    printf("%d",ans);
    return 0;
}
