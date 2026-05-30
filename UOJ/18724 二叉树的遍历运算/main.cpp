#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 50;

typedef struct BiTNode {
    char data;
    struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;

int Search(char ino[],char e,int is,int n)
{
    int k=-1;
    for (int i=is;i<is+n;++i) {
        if (ino[i] == e) {
            k = i;
            break;
        }
    }
    return k;
}

void CrtBT(BiTree &T,char pre[],char ino[],int ps,int is,int n)
{
    if (n==0) T=NULL;
    else {
        int k = Search(ino,pre[ps],is,n);
        if (k==-1) T=NULL;
        else {
            T = new BiTNode;
            T->data = pre[ps];
            CrtBT(T->lchild,pre,ino,ps+1,is,k-is);
            CrtBT(T->rchild,pre,ino,ps+1+k-is,k+1,is+n-1-k);
        }
    }
    return;
}

void PostOrderTraverse(BiTree T)
{
    if (T==NULL) return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c",T->data);
    return;
}

int main()
{
    char ino[MAXN],pre[MAXN];
    BiTree T;
    scanf("%s%s",pre,ino);
    CrtBT(T,pre,ino,0,0,strlen(ino));
    PostOrderTraverse(T);
    return 0;
}
