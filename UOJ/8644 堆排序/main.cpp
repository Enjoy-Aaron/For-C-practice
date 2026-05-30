#include <iostream>
#include <cstdio>
#define MAXSIZE 20
using namespace std;

typedef int KeyType;
typedef struct {
    KeyType key;
}RedType;
typedef struct {
    RedType r[MAXSIZE+1];
    int length;
}SqList;

void HeapAdjust(SqList &L, int s, int m)
{
    KeyType rc = L.r[s].key;
    for (int j=2*s; j<=m; j*=2) {
        if (j<m && L.r[j].key<L.r[j+1].key) ++j;
        if (rc>=L.r[j].key) break;
        L.r[s].key = L.r[j].key;
        s=j;
    }
    L.r[s].key = rc;
}

void CreateHeap(SqList &L)
{
    int n = L.length;
    for (int i=n/2;i>0;i--) {
        HeapAdjust(L,i,n);
    }
}

void HeapSort(SqList &L)
{
    CreateHeap(L);
    for (int j=1;j<=L.length;++j) printf("%d ",L.r[j].key);
        printf("\n");
    for (int i=L.length;i>1;--i) {
        int x=L.r[1].key;
        L.r[1].key=L.r[i].key;
        L.r[i].key=x;
        HeapAdjust(L, 1, i-1);
        for (int j=1;j<=L.length;++j) printf("%d ",L.r[j].key);
        printf("\n");
    }
}

int main()
{
    SqList L;
    int n;
    scanf("%d",&n);
    L.length=n;
    for (int i=1;i<=n;++i) {
        int tmp;
        scanf("%d",&tmp);
        L.r[i].key=tmp;
    }
    HeapSort(L);
    return 0;
}
