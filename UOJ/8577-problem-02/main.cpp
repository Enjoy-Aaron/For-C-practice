#include <iostream>
#include <cstdio>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
using namespace std;

typedef struct {
    int *elem;
    int length;
}SqList;

int InitList(SqList &L) {
    L.elem = new int[MAXSIZE];
    L.length = 0;
    return OK;
}

int CreateList(SqList &L) {
    cin >> L.length;
    for (int i=1; i<=L.length; ++i) {
        cin >> L.elem[i];
    }
    return OK;
}

int MergeList(SqList &LA, SqList &LB, SqList &LC) {
    int i=1, j=1, k=1;
    while (i<=LA.length && j<=LB.length) {
        if (LA.elem[i] <= LB.elem[j]) {
            LC.elem[k++] = LA.elem[i++];
        }
        else {
            LC.elem[k++] = LB.elem[j++];
        }
    }
    while (i<=LA.length) LC.elem[k++] = LA.elem[i++];
    while (j<=LB.length) LC.elem[k++] = LB.elem[j++];
    LC.length = LA.length + LB.length;
    return OK;
}

int LoadList(SqList L) {
    for (int i=1; i<=L.length; ++i) {
        printf("%d ",L.elem[i]);
    }
    printf("\n");
    return OK;
}

int main() {
    SqList LA, LB, LC;
    InitList(LA);
    InitList(LB);
    InitList(LC);
    CreateList(LA);CreateList(LB);
    printf("List A:");LoadList(LA);
    printf("List B:");LoadList(LB);
    MergeList(LA, LB, LC);
    printf("List C:");LoadList(LC);
    return 0;
}