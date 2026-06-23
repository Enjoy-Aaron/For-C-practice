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

void Get_dk(int n, int dk[], int &size) {
    size = 0;
    while (n>1) {
        dk[size++] = n/2;
        n/=2;
    }
}

void ShellInsert(SqList &L, int dk) {
    for (int i=dk+1; i<=L.length; ++i) {
        if (L.r[i].key < L.r[i-dk].key) {
            L.r[0] = L.r[i];
            int j;
            for (j=i-dk; j>0 && L.r[j].key > L.r[0].key; j-=dk) {
                L.r[j+dk] = L.r[j];
            }
            L.r[j+dk] = L.r[0];
        }
    }
}

void ShellSort(SqList &L) {
    int n = L.length;
    int dk[1010]={}, size=0;
    Get_dk(n, dk, size);
    for (int i=0; i<size; ++i) {
        ShellInsert(L, dk[i]);
        L.Load();
    }
}

int main() {
    SqList L;
    Create_Sq(L);
    ShellSort(L);
    return 0;
}