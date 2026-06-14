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

void SelectSort(SqList &L) {
    for (int i=1;i<=L.length-1; ++i) {
        int k=i;
        for (int j=i+1; j<=L.length; ++j) {
            if (L.r[j].key < L.r[k].key) {
                k=j;
            }
        }
        swap(L.r[i].key, L.r[k].key);
        L.Load();
    }
}

int main() {
    SqList L;
    Create_Sq(L);
    SelectSort(L);
    return 0;
}