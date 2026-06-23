#include <iostream>
#include <cstdio>
#define MAXSIZE 110
using namespace std;

typedef struct RedType {
    int key;
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
        for (int i=1; i<=this->length; ++i) {
            cout << this->r[i].key << " ";
        }
        cout << endl;
    }
}SqList;

void Create_Sq(SqList &L) {
    cin >> L.length;
    for (int i=1;i<=L.length; ++i) cin >> L.r[i].key;
}

void Swap(RedType &a, RedType &b) {
    RedType temp = a;
    a = b;
    b = temp;
}

void BubbleSort(SqList &L) {
    int flag = 1;
    for (int m=L.length-1; m>=1 && flag; m--) {
        flag = 0;
        for (int i=1; i<=m; ++i) {
            if (L.r[i].key > L.r[i+1].key) {
                Swap(L.r[i], L.r[i+1]);
                flag = 1;
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