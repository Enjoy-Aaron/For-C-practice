#include <iostream>
#include <cstdio>
#define MAXISZE 110
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
typedef struct SqList{
    RedType r[MAXISZE + 1];
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

void SelctSort(SqList &L) {
    for (int i=1; i<L.length; ++i) {
        int k = i;
        for (int j=i+1; j<=L.length; ++j) {
            if (L.r[j].key < L.r[k].key) {
                k = j;
            }
        }
        Swap(L.r[i], L.r[k]);
        L.Load();
    }
}

int main() {
    SqList L;
    Create_Sq(L);
    SelctSort(L);
    return 0;
}