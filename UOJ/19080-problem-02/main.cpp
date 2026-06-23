#include <iostream>//C++
using namespace std;
struct LNode
{
    int data;
    LNode * next;
};
void createList(LNode * &L,int n)
{
    /**< 尾插法创建单链表 */
    LNode *r, *p;
    r=L=new LNode;/**< 创建头结点 */
    L->next=NULL;
    for(int i=1; i<=n; i++)
    {
        p=new LNode;
        cin>>p->data;
        p->next=NULL;
        r->next=p;
        r=p;
    }
}
void trv(LNode * L)
{
    /**< 一个简单的链表遍历函数，供编程过程中测试使用 */
    L=L->next;
    while(L)
    {
        cout<<L->data<<' ';
        L=L->next;
    }
}
void reverseList(LNode * &L) 
{
    LNode *pre = NULL, *now = L->next, *next;
    while (now) {
        next = now->next;
        now->next = pre;
        pre = now;
        now = next;
    }
    L->next = pre;
}
int main()
{
    int n;
    LNode *L;
    cin>>n;
    createList(L,n);
    reverseList(L);
    trv(L);
    return 0;
}