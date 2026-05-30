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


void solve(BiTree T, int &num, int dep, int target)
{
    if (T==NULL) return;
    if (dep == target) {
        if (T->lchild == NULL && T->rchild == NULL)
            num++;
        return;
    }
    solve(T->lchild, num, dep+1, target);
    solve(T->rchild, num, dep+1, target);
    return;
}

int main()   //主函数
{
    BiTree T;
    CreateBiTree(T);
    int n,num=0;
    scanf("%d",&n);
    solve(T,num,1, n);
    printf("%d\n",num);
 }//main
