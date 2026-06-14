#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXSIZE 100
using namespace std;

typedef struct RedType{
    int key;
} RedType;

typedef struct SqList{
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

void BubbleSort(SqList &L) {
    int flag = 1;
    for (int i = L.length-1; i>=1; i--) {
        if (flag == 0) break;
        flag = 0;
        for (int j=1; j<=i; ++j) {
            if (L.r[j].key > L.r[j+1].key) {
                swap(L.r[j].key, L.r[j+1].key);
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