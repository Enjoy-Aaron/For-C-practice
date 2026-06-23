#include <iostream>
#include <cstdio>
#define MAXSIZE 1010
using namespace std;

typedef int KeyType;
typedef struct RedType{
    KeyType key;
    RedType& operator=(const RedType& other) {
        if (this != &other) {
            this->key = other.key;
        }
        return *this;
    }
}RedType;
typedef struct SqList {
    RedType r[MAXSIZE+1];
    int length;
    void Load() {
        for (int i=1; i<=length; ++i) {
            cout << r[i].key << " ";
        }
        cout << endl;
    }
}SqList;

void Create_Sq(SqList &L) {
    cin >> L.length;
    for (int i=1; i<=L.length; ++i) {
        cin >> L.r[i].key;
    }
}

void InsertSort(SqList &L) {
    for (int i=2; i<=L.length; ++i) {
        if (L.r[i].key < L.r[i-1].key) {
            L.r[0] = L.r[i];
            int j;
            for (j=i-1; L.r[j].key>L.r[0].key; j--) {
                L.r[j+1] = L.r[j];
            }
            L.r[j+1] = L.r[0];
        }
        L.Load();
    }
}

int main() {
    SqList L;
    Create_Sq(L);
    InsertSort(L);
    return 0;
}