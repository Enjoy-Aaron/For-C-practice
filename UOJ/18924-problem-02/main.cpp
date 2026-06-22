#include <iostream>
#include <cstdio>
#define MAX(a,b) (a>b? a:b)
using namespace std;

typedef struct BiTNode {
    int data;
    int lchild;
    int rchild;
}BiTNode;

typedef struct BiTree {
    BiTNode *elem;
    int vexnum;
}BiTree;

void InitBiTree(BiTree &T) {
    T.vexnum = 0;
    T.elem = new BiTNode[110];
    for (int i=0; i<110; ++i) {
        T.elem[i].data = 0;
        T.elem[i].lchild = 0;
        T.elem[i].rchild = 0;
    }
}

void CreateBiTree(BiTree &T) {
    cin >> T.vexnum;
    T.elem[T.vexnum].data = T.vexnum;
    for (int i=1;i<T.vexnum;++i) {
        T.elem[i].data = i;
        int f,c;
        cin >> f >> c;
        if (T.elem[f].lchild == 0) {
            T.elem[f].lchild = c;
        }
        else {
            T.elem[f].rchild = c;
        }
    }
}

void solve(BiTree T, int idx, int dep, int a[], int &maxn) {
    if (T.elem[idx].data==0) return;
    a[dep]++;
    maxn = MAX(maxn, a[dep]);
    solve(T, T.elem[idx].lchild, dep+1, a, maxn);
    solve(T, T.elem[idx].rchild, dep+1, a, maxn);
}

int main() {
    BiTree T;
    InitBiTree(T);
    CreateBiTree(T);
    int a[110]={}, maxn=0;
    solve(T,1,1,a,maxn);
    printf("%d\n",maxn);
   return 0;
}