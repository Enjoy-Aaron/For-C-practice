#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1010;

typedef struct {
    int *r = new int[MAXN];
    int length = 0;
}SqList;

void Shell_Insert(SqList &L, int dk)
{
    for (int i=dk+1; i<=L.length; ++i) {
        if (L.r[i] < L.r[i-dk]) {
            L.r[0] = L.r[i];
            int j=0;
            for (j=i-dk; j>0 && L.r[j]>L.r[0]; j-=dk) {
                L.r[j+dk] = L.r[j];
            }
            L.r[j+dk] = L.r[0];
        }
    }
}

void ShellSort(SqList &L, int dk[], int cnt)
{
    for (int k=0; k<cnt;++k) {
        Shell_Insert(L, dk[k]);
        for (int i=1;i<=L.length;++i) printf("%d ", L.r[i]);
        printf("\n");
    }
}

int main()
{
    SqList L;
    int n, dk[MAXN], cnt=0;
    scanf("%d",&n);
    L.length = n;
    for (int i=1;i<=n;++i) {
        scanf("%d",&L.r[i]);
    }
    while (n>1) {
        dk[cnt++] = n/2;
        n/=2;
    }
    ShellSort(L, dk, cnt);
    return 0;
}
