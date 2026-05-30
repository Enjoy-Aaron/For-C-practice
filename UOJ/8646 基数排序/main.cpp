#include <iostream>
#include <cstdio>
#define MAX_NUM_OF_KEY 8
#define RADIX 10
#define MAX_SPACE 10000
using namespace std;

typedef int KeyType;
typedef int InfoType;
typedef struct {
    KeyType keys[MAX_NUM_OF_KEY];
    InfoType otheritems;
    int next;
}SLCell;
typedef struct {
    SLCell r[MAX_SPACE];
    int keynum;
    int recnum;
}SLList;
typedef int ArrType[RADIX];

void Distribute(SLList &L, int i, ArrType &f, ArrType &e)
{
    for (int j=0;j<RADIX;++j) f[j]=0;
    int p=L.r[0].next;
    L.r[0].next=0;
    while (p) {
        int next=L.r[p].next;
        int j=L.r[p].keys[i];
        L.r[p].next=0;
        if (!f[j]) f[j]=p;
        else L.r[e[j]].next=p;
        e[j]=p;
        p=next;
    }
}

void Collect(SLList &L, int i, ArrType f, ArrType e)
{
    int j=0;
    while (j<RADIX && f[j]==0) ++j;
    L.r[0].next=f[j];
    int t=e[j];
    j++;
    while (j<RADIX) {
        if (f[j]!=0) {
            L.r[t].next=f[j];
            t=e[j];
        }
        ++j;
    }
    L.r[t].next=0;
}

void print_SLList(SLList L)
{
    for (int p=L.r[0].next;p!=0;p=L.r[p].next) {
        for (int j=0;j<L.keynum;++j) {
            printf("%d",L.r[p].keys[j]);
        }
        printf(" ");
    }
    printf("\n");
}

void RadixSort(SLList &L)
{
    ArrType f,e;
    for (int i=0;i<L.recnum;++i) L.r[i].next=i+1;
    L.r[L.recnum].next=0;
    for (int i=L.keynum-1;i>=0;--i) {
        Distribute(L,i,f,e);
        Collect(L,i,f,e);
        print_SLList(L);
    }
}

int main()
{
    SLList L;
    scanf("%d",&L.recnum);
    L.keynum=3;
    for (int i=1;i<=L.recnum;++i) {
        int tmp,a[MAX_NUM_OF_KEY]={},cnt=0;
        scanf("%d",&tmp);
        while (cnt<L.keynum) {
            a[cnt++]=tmp%10;
            tmp/=10;
        }
        for (int j=0;j<L.keynum;++j) {
            L.r[i].keys[j]=a[L.keynum-j-1];
        }
    }
    RadixSort(L);
    return 0;
}
