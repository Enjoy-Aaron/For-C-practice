#include "stdio.h"
#include "malloc.h"
#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int  Status;

typedef char  ElemType;
typedef struct BiTNode{
  ElemType data;
  struct BiTNode *lchild,*rchild;//左右孩子指针
} BiTNode,*BiTree;

Status CreateBiTree(BiTree &T) {  // 算法6.4
  // 按先序次序输入二叉树中结点的值（一个字符），’#’字符表示空树，
  // 构造二叉链表表示的二叉树T。
  char ch;
  scanf("%c",&ch);
  if (ch=='#') T = NULL;
  else {
    if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;
    T->data = ch; // 生成根结点
    CreateBiTree(T->lchild);   // 构造左子树
    CreateBiTree(T->rchild);  // 构造右子树
  }
  return OK;
} // CreateBiTree

void solve(BiTree T, int &a, int &b, int &c) {
    if (T==NULL) return;
    if (T->lchild!=NULL && T->rchild!=NULL) a++;
    else if (T->lchild != NULL || T->rchild != NULL) b++;
    else c++;
    solve(T->lchild,a,b,c);
    solve(T->rchild,a,b,c);
    return;
}

int main()   //主函数
{
    BiTree T;//补充代码
    CreateBiTree(T);
    int a=0, b=0, c=0;
    solve(T,a,b,c);
    printf("%d\n%d\n%d\n",a,b,c);
 }//main