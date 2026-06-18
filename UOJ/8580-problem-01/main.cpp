#include<stdio.h>
#include<malloc.h>
#include <iostream>
#include <cstdio>
using namespace std;
#define ERROR 0
#define OK 1 
#define ElemType int

typedef int Status;
typedef struct LNode {
 int data;
 struct LNode *next;
}LNode,*LinkList;

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

Status CreateList_L(LinkList &L, int n) {
    L = new LNode;
    L->next = NULL;
    LinkList q = L;
    for (int i=0; i<n; ++i) {
      LinkList p = new LNode;
      cin >> p->data;
      p->next = NULL;
      q->next = p;
      q = p;
    }
    return OK;
}

Status LoadList(LinkList L) {
  LinkList p = L->next;
  while (p) {
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
  return OK;
}

Status MergeList(LinkList &LA, LinkList &LB, LinkList &LC) {
  LinkList pa = LA->next, pb = LB->next, pc;
  LC = LA;pc = LC;
  while (pa && pb) {
    if (pa->data <= pb->data) {
      pc->next = pa;
      pc = pa;
      pa = pa->next;
    }
    else {
      pc->next = pb;
      pc = pb;
      pb = pb->next;
    }
  }
  if (pa) pc->next = pa;
  else pc->next = pb;
  return OK;
}

int main() {
  LinkList LA, LB, LC;
  int a,b;
  cin >> a;
  CreateList_L(LA, a);
  cin >> b;
  CreateList_L(LB, b);
  printf("List A:");LoadList(LA);
  printf("List B:");LoadList(LB);
  MergeList(LA, LB, LC);
  printf("List C:");LoadList(LC);
  return 0;
}