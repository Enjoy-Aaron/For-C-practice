#include <iostream>
#include <cstdio>
#define OK 1
#define ERROR 0
using namespace std;
typedef int Status;
typedef struct DuLNode{
    int data;
    struct DuLNode *prev;
    struct DuLNode *next;
}DuLNode,*LinkList;
const int MAXN = 1e5+10;
LinkList t[MAXN];

Status InitList_DuL(LinkList &LH,LinkList &LR)
{
    LH = new DuLNode;
    LR = new DuLNode;
    LinkList s = new DuLNode;
    s->data = 1;
    s->prev = LH;
    s->next = LR;
    t[1] = s;
    LH->next = s;
    LH->prev = NULL;
    LR->next = NULL;
    LR->prev = s;
    return OK;
}
/**
LinkList LocateList_DuL(LinkList LH,LinkList LR,int e)
{
    LinkList p = LH->next;
    while (p != LR && p->data!=e){
        p = p->next;
    }
    if (p != LR && p->data == e) return p;
    return NULL;
}
**/
Status ListInsert_DuL(LinkList &LH,LinkList &LR,int i,int e,int sta)
{
    LinkList p = LH->next;
    p = t[e];
    LinkList s = new DuLNode;
    s->data = i;
    t[i] = s;
    if (sta){
        p->next->prev = s;
        s->next = p->next;
        p->next = s;
        s->prev = p;
    }
    else{
        p->prev->next = s;
        s->prev = p->prev;
        p->prev = s;
        s->next = p;
    }
    return OK;
}

Status print_DuL(LinkList LH,LinkList LR)
{
    LinkList s=LH->next;
    while (s != LR){
        printf("%d ",s->data);
        s = s->next;
    }
    printf("\n");
    return OK;
}

int main()
{
    LinkList LH,LR;
    InitList_DuL(LH,LR);
   int n,x,p;
   scanf("%d",&n);
   for (int i=2;i<=n;++i){
        scanf("%d%d",&x,&p);
        ListInsert_DuL(LH,LR,i,x,p);
        //print_DuL(LH,LR);
   }
   print_DuL(LH,LR);
    return 0;
}
