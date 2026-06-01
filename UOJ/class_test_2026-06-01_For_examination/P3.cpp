#include "stdio.h"
#include "malloc.h"
#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX(a, b) (a>b? a:b)
typedef int  Status;

typedef int  ElemType;
typedef struct BiTNode{
  ElemType data;
  struct BiTNode *lchild,*rchild;//左右孩子指针
} BiTNode,*BiTree;

Status InsertBiTree(BiTree &T,int e) //插入新结点
{
	if(T==NULL){
		T=(BiTNode *)malloc(sizeof(BiTNode));
		T->data=e;T->lchild=NULL;
		T->rchild=NULL;
		return 1;
	}
	if(T->data<e)
		InsertBiTree(T->rchild,e);
	else
		InsertBiTree(T->lchild,e);
	return 0;
}

BiTree FindNode_BT(BiTree T, int m)
{
    if (T == NULL) return NULL;
    if (m == T->data) return T;
    if (m < T->data) return FindNode_BT(T->lchild, m);
    return FindNode_BT(T->rchild, m);
}

int GetDepth_BT(BiTree T)
{
    if (T == NULL) return 0;
    if (T->lchild == NULL && T->rchild == NULL) return 1;
    return MAX(GetDepth_BT(T->lchild), GetDepth_BT(T->rchild)) + 1;
}

int main()
{
    BiTree T;
    T = NULL;
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;++i) {
        int tmp;
        scanf("%d",&tmp);
        InsertBiTree(T, tmp);
    }
    int m;
    scanf("%d",&m);
    BiTree TM = FindNode_BT(T, m);
    printf("%d\n",GetDepth_BT(TM));
}
