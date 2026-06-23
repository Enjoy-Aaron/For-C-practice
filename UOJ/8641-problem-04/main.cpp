#include <iostream>
#include <cstdio>
#define MAXN 1010
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
    RedType r[MAXN+1];
    int length;
    void Load() {
        for(int i=1; i<=this->length; ++i) {
            cout << this->r[i].key << " ";
        }
        cout << endl;
    }
}SqList;

void Create_Sq(SqList &L){
    cin >> L.length;
    for (int i=1; i<=L.length; ++i) cin >> L.r[i].key;
}

void BubbleSort(SqList &L) {
    int flag=1;
    for (int m=L.length-1; m>=1 && flag; m--) {
        flag=0;
        for (int i=1; i<=m; ++i) {
            if (L.r[i].key > L.r[i+1].key) {
                L.r[0] = L.r[i];
                L.r[i] = L.r[i+1];
                L.r[i+1] = L.r[0];
                flag=1;
            }
        }
        L.Load();
    }
}

int main() {
    SqList L;
    Create_Sq(L);
    BubbleSort(L);
    return 0;
}