#include <iostream>//C++
using namespace std;
struct LNode
{
    int data;
    LNode * next;
};
void createList(LNode * &L,int n)
{/**< 尾插法创建单链表 */
    LNode *r, *p;
    r=L=new LNode;/**< 创建头结点 */
    L->next=NULL;
    for(int i=1;i<=n;i++)
    {
        p=new LNode;
        cin>>p->data;
        p->next=NULL;
        r->next=p;
        r=p;
    }
}
void trv(LNode * L)
{ /**< 一个简单的链表遍历函数，供编程过程中测试使用 */
    L=L->next;
    while(L)
    {
        cout<<L->data<<' ';
        L=L->next;
    }
}
int getK(LNode * L,int k)
{
    int Lenth=0;
    LNode *p=L->next;
    while (p){
        ++Lenth;
        p=p->next;
    }
    int i=Lenth-k+1;
    p=L->next;
    int j=1;
    while (p && j<i){
        p=p->next;
        j++;
    }
    if (!p || j>i) return -1;
    return p->data;
}
int main()
{
    int n,k;
    LNode *L;
    cin>>n>>k;
    createList(L,n);
    //trv(L);
    cout<<getK(L,k);
    return 0;
}
