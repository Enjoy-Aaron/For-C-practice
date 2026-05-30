#include <iostream>
#include <string>
#define OK 1
#define ERROR 0
#define MAXN 50
using namespace std;
typedef int Status;
typedef struct LNode{
    char data;
    struct LNode *next;
}LNode,*LinkList;

Status CreateList_L(LinkList &L)
{
    L = new LNode;
    L->next = NULL;
    LinkList r=L,s;
    string str;
    cin>>str;
    for (int i=0;i<str.size();++i){
        s = new LNode;
        s->next = NULL;
        s->data = str[i];
        r->next = s;
        r = s;
    }
    return OK;
}

Status ListDelete_L(LinkList &L,int i)
{
    LinkList p=L;
    int j=0;
    while (p->next && j<i-1){
        p = p->next;
        j++;
    }
    if (!p->next || j>i-1) return ERROR;
    LinkList q=p->next;
    p->next=q->next;
    delete q;
    return OK;
}

Status check1(LinkList p)
{
    if (!p->next || !p->next->next) return 2;
    if (p->data == p->next->data && p->data == p->next->next->data) return 0;
    return 1;
}

Status check2(LinkList p)
{
    if(!p->next || !p->next->next || !p->next->next->next) return 2;
    if(p->data == p->next->data && p->next->next->data == p->next->next->next->data) return 0;
    return 1;
}

Status LocateCheck_L(LinkList &L)
{
    LinkList p=L->next;
    int j=1;
    while (p){
        if (check1(p) && check2(p)){
            p=p->next;
            j++;
        }
        else{
            ListDelete_L(L,j+2);
        }
    }
    return OK;
}

Status print_L(LinkList L)
{
    LinkList p = L->next;
    while (p){
        printf("%c",p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    scanf("%d",&n);
    LinkList L;
    while (n--){
        CreateList_L(L);
        LocateCheck_L(L);
        print_L(L);
    }
    return 0;
}
