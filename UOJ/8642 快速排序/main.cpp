#include <iostream>
#include <cstdio>

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;

typedef int KeyType;
typedef int InfoType;
typedef struct {
    KeyType key;
    InfoType otherinfo;
}RedType;
typedef struct {
    RedType r[MAXSIZE+1];
    int length;
}SqList;

int Partition(SqList &L, int low, int high)
{
    int pivotkey = L.r[low].key;
    L.r[0].key = L.r[low].key;
    while (low < high) {
        while (low<high && L.r[high].key>=pivotkey) high--;
        L.r[low].key = L.r[high].key;
        while (low<high && L.r[low].key<=pivotkey) low++;
        L.r[high].key = L.r[low].key;
    }
    L.r[low].key = L.r[0].key;
    return low;
}

void QSort(SqList &L, int low, int high)
{
    if (low<high) {
        int pivotloc = Partition(L, low, high);
        for (int i=1;i<=L.length;++i) printf("%d ",L.r[i].key);
        printf("\n");
        QSort(L, low, pivotloc-1);
        QSort(L, pivotloc+1, high);
    }
    return;
}

void QuickSort(SqList &L)
{
    QSort(L, 1, L.length);
    return;
}

int main()
{
    SqList L;
    int n;
    scanf("%d",&n);
    L.length = n;
    for (int i=1;i<=L.length;++i) scanf("%d",&L.r[i].key);
    QuickSort(L);
    return 0;
}
