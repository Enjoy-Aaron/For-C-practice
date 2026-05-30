#include <iostream>
#include <stdio.h>
#include <malloc.h>
#define OK 1
#define ERROR 0
using namespace std;

typedef char Elemtype;
typedef int Status;
typedef struct LNode{
    Elemtype data;
    struct LNode *next;
}LNode, *LinkList;

Status CreateList_L(LinkList &L,int n)
{
    L=new LNode;
    L->next=NULL;
    LinkList r=L;
    for (int i=1;i<=n;++i){
        LinkList s=new LNode;
        scanf("%c",&s->data);
        s->next=NULL;
        r->next=s;
        r=s;
    }
    return OK;
}

Status LoadList_L(LinkList &L)
{
    LinkList p=L->next;
    while (p){
        printf("%c",p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}

Status ListDelete_L(LinkList &L,int i,Elemtype &e)
{
    LinkList p=L;
    int j=0;
    while (p->next && j<i-1){
        p=p->next;
        j++;
    }
    if (!p->next || j>i-1) return ERROR;
    LinkList q=p->next;
    p->next=q->next;
    e=q->data;
    delete q;
    return OK;
}

Status ListInsert_L(LinkList &L,Elemtype e)
{
    LinkList p=L;
    while (p->next && p->next->data<e){
        p=p->next;
    }
    if (p->next && p->next->data==e) return ERROR;
    LinkList s=new LNode;
    s->data=e;
    s->next=p->next;
    p->next=s;
    return OK;
}

Status ReSetList_L(LinkList &LA,LinkList &LB)
{
    Elemtype e;
    LB=new LNode;
    LB->next=NULL;
    while (LA->next){
        ListDelete_L(LA,1,e);
        ListInsert_L(LB,e);
    }
    delete LA;
    return OK;
}

int main()
{
    LinkList LA,LB;
    int n;
    scanf("%d\n",&n);
    CreateList_L(LA,n);
    ReSetList_L(LA,LB);
    LoadList_L(LB);
    return 0;
}
