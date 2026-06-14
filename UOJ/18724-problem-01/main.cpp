#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1e5+10;

typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int Search(char* ios, int is, char e, int n) {
    int k=-1;
    for (int i=is; i<is+n; ++i) {
        if (ios[i] == e) return i;
    }
    return k;
}

void CreateBiTree(BiTree &T, char* pre, char* ios, int ps, int is, int n, bool& flag) {
    if (flag == 0) return;
    if (n <= 0) {
        T = NULL;
        return;
    }
    int k = Search(ios, is, pre[ps], n);
    if (k==-1) {
        T = NULL;
        flag = 0;
        return;
    }
    T = new BiTNode;
    T->data = pre[ps];
    T->lchild = NULL;
    T->rchild = NULL;
    CreateBiTree(T->lchild, pre, ios, ps+1, is, k-is, flag);
    CreateBiTree(T->rchild, pre, ios, ps+k-is+1, k+1, is+n-k-1, flag);
    return;
}

void PostOrderTraverse(BiTree T) {
    if (T == NULL) return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c", T->data);
    return;
}

int main() {
    char ios[MAXN], pre[MAXN];
    BiTree T;
    scanf("%s%s", pre, ios);
    bool flag = 1;
    CreateBiTree(T, pre, ios, 0, 0, strlen(ios), flag);
    if (flag == 0) printf("ERROR\n");
    else PostOrderTraverse(T);
    return 0;
}