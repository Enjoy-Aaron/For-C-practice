#include <iostream>
#include <cstdio>
#define MAXSIZE 100
using namespace std;

typedef struct RedType {
    int key;
}RedType;

typedef struct SqList {
    RedType r[MAXSIZE + 1];
    int length;

    void Load() {
        for (int i=1;i<=this->length; ++i) {
            cout << this->r[i].key << " ";
        }
        cout << endl;
    }
}SqList;

void Create_Sq(SqList &L) {
    cin >> L.length;
    for (int i=1;i<=L.length; ++i) {
        cin >> L.r[i].key;
    }
}

void HeapAdjust(SqList &L, int s, int m) {
    int rc = L.r[s].key;
    for (int j=2*s; j<=m; j*=2) {
        if (j<m && L.r[j].key < L.r[j+1].key) ++j;
        if (rc >= L.r[j].key) break;
        L.r[s].key = L.r[j].key;
        s = j;
    }
    L.r[s].key = rc;
}

void CreateHeap(SqList &L) {
    for (int s=L.length/2;s>=1;s--) {
        HeapAdjust(L,s,L.length);
    }
}

void HeapSort(SqList &L) {
    CreateHeap(L);
    L.Load();
    for (int s=L.length; s>1; s--) {
        swap(L.r[1].key, L.r[s].key);
        HeapAdjust(L, 1, s-1);
        L.Load();
    }
}

int main () {
    SqList L;
    Create_Sq(L);
    HeapSort(L);
    return 0;
}