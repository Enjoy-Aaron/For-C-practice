#include <iostream>
#include <cstdio>
#define MAX(a,b) (a>b? a:b)
using namespace std;
const int MAXN = 1e5+10;

typedef struct BiTNode{
    int lchild;
    int rchild;
}BiTNode;
BiTNode BiTree[MAXN]; 
int fa[MAXN];

void GetTop(int x, int &top) {
    if (fa[x] == 0) {
        top = x;
        return;
    }
    GetTop(fa[x], top);
}

void GetLenth(int x, int &dep, int &ans){
    if (x == 0){
        dep = 0;
        return;
    }
    int ldep, rdep;
    GetLenth(BiTree[x].lchild, ldep, ans);
    GetLenth(BiTree[x].rchild, rdep, ans);
    ans = MAX(ans, ldep + rdep);
    dep = MAX(ldep, rdep) + 1;
}

int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;++i) {
        int x, y;
        scanf("%d%d",&x,&y);
        fa[y] = x;
        if (BiTree[x].lchild == 0) BiTree[x].lchild = y;
        else BiTree[x].rchild = y;
    }
    int top, ans=0, dep;
    GetTop(1, top);
    GetLenth(top, dep, ans);
    printf("%d\n",ans);
    return 0;
}