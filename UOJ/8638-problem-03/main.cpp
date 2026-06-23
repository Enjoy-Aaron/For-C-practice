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

void BiInsertSort(SqList &L) {
    for (int i=2; i<=L.length; ++i) {
        if (L.r[i].key < L.r[i-1].key) {
            L.r[0] = L.r[i];
            int low = 1, high = i-1, mid;
            while (low <= high) {
                mid = (low + high) / 2;
                if (L.r[mid].key <= L.r[0].key) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }   
            for (int j=i-1; j>=low; j--) {
                L.r[j+1] = L.r[j];
            }
            L.r[low] = L.r[0];
        }
        L.Load();
    }
}

int main() {
    SqList L;
    Create_Sq(L);
    BiInsertSort(L);
    return 0;
}