#include <iostream>
#include <cstdio>
#define MAX(a,b) (a>b? a:b)
using namespace std;
const int MAXN = 110;

typedef struct BiTNode {
    int data;
    int lchild;
    int rchild;
} BiTNode;

typedef struct BiTree {
    BiTNode* elem;
    int vexnum;
} BiTree;

void InitCreate(BiTree &T) {
    T.vexnum = 0;
    T.elem = new BiTNode[MAXN];
    for (int i=0; i<MAXN; ++i) {
        T.elem[i].data = 0;
        T.elem[i].lchild = 0;
        T.elem[i].rchild = 0;
    }
}

void CreateBiTree(BiTree &T) {
    cin >> T.vexnum;
    T.elem[T.vexnum].data = T.vexnum;
    for (int i=1; i<T.vexnum; ++i) {
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

void solve(BiTree T, int idx, int dep, int weight[], int &depth) {
    if (T.elem[idx].data == 0) return;
    weight[dep]++;
    depth = MAX(depth, dep);
    solve(T, T.elem[idx].lchild, dep + 1, weight, depth);
    solve(T, T.elem[idx].rchild, dep + 1, weight, depth);
}

int main() {
    BiTree T;
    InitCreate(T);
    CreateBiTree(T);
    int weight[MAXN]={};
    int depth = 0;
    int width = 0;
    solve(T,1,1,weight, depth);
    for (int i=1;i<=depth;++i) {
        width = MAX(width, weight[i]);
    }
    printf("%d\n",width);
    return 0;
}