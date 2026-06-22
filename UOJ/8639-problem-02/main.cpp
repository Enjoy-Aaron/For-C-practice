#include <iostream>
#include <cstdio>
#define MAXSIZE 110
using namespace std;

typedef int KeyType;
typedef struct RedType {
    KeyType key;
}RedType;
typedef struct SqList {
    RedType r[MAXSIZE + 1];
    int length;
    void Load() {
        for (int i=1;i<=length; ++i) {
            cout << r[i].key << " ";
        }
        cout << endl;
    }
}SqList;

void CreateList(SqList &L) {
    cin >> L.length;
    for (int i=1;i<=L.length; ++i) {
        cin >> L.r[i].key;
    }
}

void BiInsertSort(SqList &L) {
    int low, high, mid;
    for (int i=2; i<=L.length; ++i) {
        if (L.r[i].key < L.r[i-1].key) {
            L.r[0].key = L.r[i].key;
            low = 1; high = i-1;
            while (low <= high) {
                mid = low + ((high - low) >> 1);
                if (L.r[mid].key <= L.r[0].key) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            for (int j=i-1; j>=low; j--) {
                L.r[j+1].key = L.r[j].key;
            }
            L.r[low].key = L.r[0].key;
        }
        L.Load();
    }
}

int main() {
    SqList L;
    CreateList(L);
    BiInsertSort(L);
    return 0;
}