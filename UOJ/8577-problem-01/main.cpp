#include <iostream>
#include <cstdio>
#define OK 1
#define ERROR 0
#define LIST_MAX_SIZE 100
using namespace std;

typedef struct {
    int *elem;
    int length;
    int listsize;
}SqList;

int InitList_Sq(SqList &L) {
    L.elem = new int[LIST_MAX_SIZE];
    L.length = 0;
    L.listsize = LIST_MAX_SIZE;
    return OK;
}

int MergeList_Sq(SqList LA, SqList LB, SqList &LC) {
    int i, j;
    for (i=1, j=1; i<=LA.length && j<=LB.length;) {
        if (LA.elem[i] <= LB.elem[j]) LC.elem[++LC.length] = LA.elem[i], ++i;
        else LC.elem[++LC.length] = LB.elem[j], ++j;
    }
    while (i<=LA.length) LC.elem[++LC.length] = LA.elem[i++];
    while (j<=LB.length) LC.elem[++LC.length] = LB.elem[j++];
    return OK;
}

int CreateList_Sq(SqList &L) {
    cin >> L.length;
    for (int i=1;i<=L.length; ++i) {
        cin >> L.elem[i];
    }
    return OK;
}

int LoadList_Sq(SqList L) {
    for (int i=1;i<=L.length; ++i) {
        cout << L.elem[i] << " ";
    }
    cout << endl;
    return OK;
}

int main() {
    SqList LA, LB, LC;
    InitList_Sq(LA);InitList_Sq(LB);InitList_Sq(LC);
    CreateList_Sq(LA);CreateList_Sq(LB);
    printf("List A:");LoadList_Sq(LA);
    printf("List B:");LoadList_Sq(LB);
    MergeList_Sq(LA, LB, LC);
    printf("List C:");LoadList_Sq(LC);
    return 0;
}