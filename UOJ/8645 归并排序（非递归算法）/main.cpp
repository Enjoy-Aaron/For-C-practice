#include <iostream>
#include <cstdio>
#include <malloc.h>
#define MAXSIZE 200
using namespace std;

typedef int KeyType;
typedef int InfoType;
typedef struct RedType{
    KeyType key;
    InfoType otherInfo;
    RedType& operator=(const RedType& other) {
        this->key=other.key;
        this->otherInfo=other.otherInfo;
        return *this;
    }
}RedType;
typedef struct {
    RedType r[MAXSIZE+1];
    int length;
}SqList;

void MergeSortNonr(SqList &L)
{
    int left=1, right=L.length;
    RedType *tmp=new RedType[MAXSIZE+1];
    int gap=1;
    while (gap<L.length) {
        for (int i=left;i<=right;i+=2*gap) {
            int begin1=i, end1=i+gap-1, mid=i+gap-1;
            int begin2=mid+1, end2=i+2*gap-1;
            int idx=i;
            if (begin2>right) break;
            if (end2>right) end2=right;
            while (begin1<=end1 && begin2<=end2) {
                if (L.r[begin1].key<L.r[begin2].key) tmp[idx++]=L.r[begin1++];
                else tmp[idx++]=L.r[begin2++];
            }
            while (begin1<=end1) tmp[idx++]=L.r[begin1++];
            while (begin2<=end2) tmp[idx++]=L.r[begin2++];
            for (int j=i;j<=end2;++j) {
                L.r[j]=tmp[j];
            }
        }
        gap*=2;
        for (int i=1;i<=L.length;++i) {
            printf("%d ",L.r[i].key);
        }
        printf("\n");
    }
}

int main()
{
    SqList L;
    int n;
    scanf("%d",&n);
    L.length=n;
    for (int i=1;i<=L.length;++i) scanf("%d",&L.r[i].key);
    MergeSortNonr(L);
    return 0;
}
