#include <iostream>
#include <cstdio>
#define MAXN 1010
#define MAX(a, b) (a>b? a:b)
using namespace std;

typedef struct BiTNode {
    int data;
    int lchild, rchild;
}BiTNode;
typedef struct BiTree {
    BiTNode *elem;
    int vexnum;
}BiTree;

void InitBiTree(BiTree &T) {
    T.elem = new BiTNode[MAXN];
    T.vexnum = 0;
    for (int i=0; i<MAXN; ++i) {
        T.elem[i].data = 0;
        T.elem[i].lchild = 0;
        T.elem[i].rchild = 0;
    }
}

void Create(BiTree &T) {
    InitBiTree(T);
    cin >> T.vexnum;
    for (int i=1; i<=T.vexnum; ++i) {
        T.elem[i].data = i;
    }
    for (int i=1; i<T.vexnum; ++i) {
        int x, y;
        cin >> x >> y;
        if (T.elem[x].lchild == 0) {
            T.elem[x].lchild = y;
        }
        else {
            T.elem[x].rchild = y;
        }
    }
}

int solve(BiTree T, int idx, int &maxn) {
    if (T.elem[idx].data == 0) return 0;
    int ld = solve(T, T.elem[idx].lchild, maxn);
    int rd = solve(T, T.elem[idx].rchild, maxn);
    maxn = MAX(maxn, ld + rd);
    return MAX(ld, rd) + 1;
}

int main() {
    BiTree T;
    Create(T);
    int maxn = 0;
    solve(T, 1, maxn);
    printf("%d\n",maxn);    
    return 0;
}