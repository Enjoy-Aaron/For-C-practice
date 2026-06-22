#include <iostream>
#include <cstdio>
#define MAXSIZE 110
using namespace std;

typedef int KeyType;
typedef struct RedType {
    KeyType key;
    RedType& operator=(const RedType& other) {
        if (this != &other) {
            this->key = other.key;
        }
        return *this;
    }
}RedType;
typedef struct SqList {
    RedType r[MAXSIZE + 1];
    int length;
    void Load() {
        for (int i=1; i<=this->length; ++i) {
            cout << this->r[i].key << " ";
        }
        cout << endl;
    }
}SqList;

void Create_Sq(SqList &L) {
    cin >> L.length;
    for (int i=1;i<=L.length; ++i) cin >> L.r[i].key;
    return;
}

void Swap(RedType &a, RedType &b) {
    RedType temp = a;
    a = b;
    b = temp;
    return;
}

void HeapAdjust(SqList &L, int s, int m) {
    L.r[0] = L.r[s];
    for (int j=2*s; j<=m; j*=2) {
        if (j<m && L.r[j].key < L.r[j+1].key) j++;
        if (L.r[0].key >= L.r[j].key) break;
        L.r[s] = L.r[j];
        s = j;
    }
    L.r[s] = L.r[0];
    return;
}

void CreateHeap(SqList &L) {
    for (int i=L.length/2; i>=1; i--) {
        HeapAdjust(L, i, L.length);
    }
    return;
}

void HeapSort(SqList &L) {
    CreateHeap(L);
    L.Load();
    for (int s = L.length; s>1; s--) {
        Swap(L.r[1], L.r[s]);
        HeapAdjust(L, 1, s-1);
        L.Load();
    }
    return;
}

int main() {
    SqList L;
    Create_Sq(L);
    HeapSort(L);
    return 0;
}