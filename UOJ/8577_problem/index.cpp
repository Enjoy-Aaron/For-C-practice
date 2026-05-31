#include <iostream>
#include <cstdio>
#define MAXSIZE 110
using namespace std;

typedef struct {
    int *elem;
    int length;
}SqList;

void InitList_Sq(SqList &L)
{
    L.elem = new int[MAXSIZE];
    L.length = 0;
}

void CreateList_Sq(SqList &L)
{
    scanf("%d",&L.length);
    for (int i=0; i<L.length; ++i) {
        scanf("%d",&L.elem[i]);
    }
}

void PrintList_Sq(SqList L)
{
    for (int i=0; i<L.length; ++i) {
        printf("%d ",L.elem[i]);
    }
    printf("\n");
}

void MergeList_Sq(SqList LA, SqList LB, SqList &LC)
{
    int i=0, j=0;
    while (i<LA.length && j<LB.length) {
        if (LA.elem[i] <= LB.elem[j]) {
            LC.elem[LC.length++] = LA.elem[i];
            i++;
        }
        else {
            LC.elem[LC.length++] = LB.elem[j];
            j++;
        }
    }
    while (i<LA.length) {
        LC.elem[LC.length++] = LA.elem[i++];
    }
    while (j<LB.length) {
        LC.elem[LC.length++] = LB.elem[j++];
    }
}

int main()
{
    SqList A, B, C;
    InitList_Sq(A);
    InitList_Sq(B);
    InitList_Sq(C);
    CreateList_Sq(A);
    CreateList_Sq(B);
    printf("List A:");
    PrintList_Sq(A);
    printf("List B:");
    PrintList_Sq(B);
    MergeList_Sq(A, B, C);
    printf("List C:");
    PrintList_Sq(C);
    return 0;
}
