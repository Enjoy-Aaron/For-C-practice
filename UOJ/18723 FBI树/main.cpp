#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef struct BTNode{
    char data;
    struct BTNode *lchild, *rchild;
}BTNode, *BTree;

void solve(char *s,int left, int right, BTree &T)
{
    T = new BTNode;
    T->lchild=NULL;
    T->rchild=NULL;
    int mid=(left+right) / 2;
    if (left>=right) {
        if (s[mid]=='0') T->data='B';
        else T->data = 'I';
        return;
    }
    solve(s,left,mid,T->lchild);
    solve(s,mid+1,right,T->rchild);
    if (T->lchild->data=='B' && T->rchild->data=='B') T->data='B';
    else if (T->lchild->data == 'I' && T->rchild->data == 'I') T->data = 'I';
    else T->data = 'F';
    return;
}

void PostTraverse(BTree T)
{
    if (T==NULL) return;
    PostTraverse(T->lchild);
    PostTraverse(T->rchild);
    printf("%c",T->data);
    return;
}

int main()
{
    char s[2049]={};
    BTree T;
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    solve(s,0,strlen(s)-1,T);
    PostTraverse(T);
    return 0;
}
