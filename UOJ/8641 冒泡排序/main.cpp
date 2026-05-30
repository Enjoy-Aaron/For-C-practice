#include <iostream>
#include <cstdio>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 20

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

void BubbleSort(SqList &L)
{
    int m = L.length-1, flag=1;
    while (m>0 && flag==1) {
        flag=0;
        for (int j=1;j<=m;++j) {
            if (L.r[j].key > L.r[j+1].key) {
                int t = L.r[j].key;
                L.r[j].key = L.r[j+1].key;
                L.r[j+1].key = t;
                flag=1;
            }
        }
        for (int i=1;i<=L.length;++i) printf("%d ",L.r[i].key);
        printf("\n");
        m--;
    }
}

int main()
{
    SqList L;
    int n;
    scanf("%d",&n);
    L.length = n;
    for (int i=1;i<=L.length;++i) {
        scanf("%d",&L.r[i].key);
    }
    BubbleSort(L);
    return 0;
}
