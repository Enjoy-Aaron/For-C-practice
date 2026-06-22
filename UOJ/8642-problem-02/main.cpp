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

int Partition(SqList &L, int low ,int high) {
    KeyType pivotkey=L.r[low].key;
    L.r[0] = L.r[low];
    while (low < high) {
        while (low < high && L.r[high].key >= pivotkey) high--;
        L.r[low] = L.r[high];
        while (low < high && L.r[low].key <= pivotkey) low++;
        L.r[high] = L.r[low];
    }
    L.r[low] = L.r[0];
    return low;
}

void QSort(SqList &L, int low, int high) {
    if (low >= high) return;
    int pivotloc = Partition(L, low, high);
    L.Load();
    QSort(L, low, pivotloc - 1);
    QSort(L, pivotloc + 1, high);
    return;
}

void QuickSort(SqList &L) {
    QSort(L, 1, L.length);
}

int main() {
    SqList L;
    Create_Sq(L);
    QuickSort(L);
    return 0;
}