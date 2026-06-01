#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1 
#define ElemType int

typedef int Status;
typedef struct LNode
{
 int data;
 struct LNode *next;
}LNode,*LinkList;

Status InitList_L(LinkList &L)
{
    L = new LNode;
    L->next = NULL;
    return OK;
}

Status CreateList_L(LinkList &L)
{
    int n;
    scanf("%d",&n);
    LinkList p=L, q;
    for (int i=0; i<n; ++i) {
        q = new LNode;
        scanf("%d",&q->data);
        q->next = NULL;
        p->next = q;
        p = q;
    }
    return OK;
}

Status LoadList_L(LinkList L)
{
    LinkList p = L->next;
    while (p) {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

Status ListInsert_L(LinkList &L, int i, ElemType e) {  // 算法2.9
    // 在带头结点的单链线性表L的第i个元素之前插入元素e
    LinkList p,s;
    p = L;   
    int j = 0;
    while (p && j < i-1) {  // 寻找第i-1个结点
        p = p->next;
        ++j;
    } 
    if (!p || j > i-1) return ERROR;      // i小于1或者大于表长
    s = (LinkList)malloc(sizeof(LNode));  // 生成新结点
    s->data = e;  s->next = p->next;      // 插入L中
    p->next = s;
    return OK;
} // LinstInsert_L

Status ListDelete_L(LinkList &L, int i, ElemType &e) {  // 算法2.10
    // 在带头结点的单链线性表L中，删除第i个元素，并由e返回其值
    LinkList p,q;
    p = L;
    int j = 0;
    while (p->next && j < i-1) {  // 寻找第i个结点，并令p指向其前趋
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i-1) return ERROR;  // 删除位置不合理
    q = p->next;
    p->next = q->next;           // 删除并释放结点
    e = q->data;
    free(q);
    return OK;
} // ListDelete_L

Status ReverseList_L(LinkList &L)
{
    LinkList pre = NULL, now = L->next, next;
    while (now) {
        next = now->next;
        now->next = pre;
        pre = now;
        now = next;
    }
    L->next = pre;
    return OK;
}

int main()
{
    LinkList T;
    InitList_L(T);
    CreateList_L(T);
    printf("The List is:");
    LoadList_L(T);
    ReverseList_L(T);
    printf("The turned List is:");
    LoadList_L(T);
    return 0;
}