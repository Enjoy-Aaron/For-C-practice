#include <stdio.h>
#include <malloc.h>
typedef long long ll;
using namespace std;
typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild,*rchild;//左右孩子指针
} BiTNode,*BiTree;

void  CreateBiTree(BiTree &T)
{ /**< 先序建树算法 */
    char ch;
    scanf("%c",&ch);
    if (ch=='#') T = NULL;
    else
    {
        T = (BiTNode *)malloc(sizeof(BiTNode));
        T->data=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

// ===================== 补全的右视图核心代码 =====================
void Rview(BiTree T)
{/**< 右视图算法，用队列作为辅助存储结构 */
    // 空树直接返回
    if(T == NULL) return;
    
    // 用数组模拟队列（存储二叉树节点指针）
    BiTree queue[1005];
    int front = 0, rear = 0;
    // 根节点入队
    queue[rear++] = T;

    // 层序遍历核心循环
    while(front < rear)
    {
        // 获取当前层的节点总数
        int level_size = rear - front;
        // 遍历当前层所有节点
        for(int i=0; i<level_size; i++)
        {
            // 队首节点出队
            BiTree node = queue[front++];
            
            // 关键：每一层的最后一个节点 = 右视图节点
            if(i == level_size - 1)
            {
                printf("%c", node->data);
            }

            // 左孩子非空则入队
            if(node->lchild != NULL)
                queue[rear++] = node->lchild;
            // 右孩子非空则入队
            if(node->rchild != NULL)
                queue[rear++] = node->rchild;
        }
    }
}
// ==============================================================

int main()
{
    BiTree T;
    CreateBiTree(T);
    Rview(T);
    return 0;
}