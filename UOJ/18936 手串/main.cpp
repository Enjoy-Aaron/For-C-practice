#include <iostream>
#include <cstdio>
#define OK 1
#define ERROR 0
#define COLOR_MAXN 55
using namespace std;
typedef struct LNode{
    int *color = new int[COLOR_MAXN];
    bool *t_color = new bool[COLOR_MAXN];
    int color_cnt;
    struct LNode *next;
}LNode,*LinkList;
typedef int Status;
int n,m,c,cnt;
int t[COLOR_MAXN];

Status InitList_L(LinkList &L)
{
    L = new LNode;
    L->next=NULL;
    return OK;
}

Status CreateList_L(LinkList &L,int n)
{
    LinkList r=L,s;
    while (n--){
        s = new LNode;
        int num_i;
        int color_tmp;
        scanf("%d",&num_i);
        s->color_cnt = num_i;
        for (int j=1;j<=num_i;++j){
            scanf("%d",&color_tmp);
            s->color[j] = color_tmp;
            s->t_color[color_tmp] = 1;
        }
            s->next = NULL;
            r->next = s;
            r = s;
    }
    s->next = L->next;
    L=s->next;
    return OK;
}

bool CheckList_L(LinkList p,int color_tmp)
{
    bool flag = 1;
    LinkList q=p;
    for (int j=1;j<m;++j){
        q=q->next;
        if (q->t_color[color_tmp]==1){
            t[color_tmp] = 1;
            flag = 0;
        }
    }
    return flag;
}

Status Solve_L(LinkList L)
{
    LinkList p = L;
    int i=1;
    while (i++<=n){
        for (int j=1;j<=p->color_cnt;++j){
            int color_tmp = p->color[j];
            if (!t[color_tmp]){
                if (!CheckList_L(p,color_tmp)) cnt++;
            }
        }
        p = p->next;
    }
    return  OK;
}

Status print_L(LinkList L)
{
    LinkList p = L->next;
    int i=0;
    while (++i<=n){
        printf("%d num_i:%d:",i,p->color_cnt);
        for (int i=1;i<=p->color_cnt;++i){
            printf("%d ",p->color[i]);
        }
        printf("t_color:");
        for (int i=1;i<=c;++i){
            printf("%d ",p->t_color[i]);
        }
        printf("\n");
        p = p->next;
    }
    return OK;
}

int main()
{
    LinkList L;
    InitList_L(L);
    scanf("%d%d%d",&n,&m,&c);
    CreateList_L(L,n);
    //print_L(L);
    Solve_L(L);
    printf("%d\n",cnt);
    return 0;
}
