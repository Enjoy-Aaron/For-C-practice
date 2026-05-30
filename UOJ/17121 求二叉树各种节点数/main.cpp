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
    CreateBiTree(T->rchild); // 构造右子树
  }
  return OK;
} // CreateBiTree

int solve(BiTree T,int target,int &ans)
{
    if (T==NULL) return 0;
    if (solve(T->lchild,target,ans) + solve(T->rchild,target,ans) == target) {
        ans++;
    }
    return 1;
}

int main()   //主函数
{
    BiTree T;
    CreateBiTree(T);
    int ans[3]={};
    for (int i=2;i>=0;i--) {
        solve(T,i,ans[i]);
        printf("%d\n",ans[i]);
    }
    return 0;
 }//main
