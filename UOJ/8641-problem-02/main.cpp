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

void BubbleSort(SqList &L) {
    int flag = 1;
    for (int m = L.length - 1; m>=1 && flag == 1; m--) {
        flag = 0;
        for (int i=1; i<=m; ++i) {
            if (L.r[i].key > L.r[i+1].key) {
                Swap(L.r[i], L.r[i+1]);
                flag = 1;
            }
        }
        L.Load();
    }
    return;
}

int main() {
    SqList L;
    Create_Sq(L);
    BubbleSort(L);
    return 0;
}
