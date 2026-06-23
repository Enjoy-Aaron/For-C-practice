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

void Swap(RedType &a, RedType &b) {
    RedType tmp = a;
    a = b;
    b = tmp;
}

int Partition(SqList &L, int low, int high) {
    RedType *tmp = new RedType[MAXN+1];
    RedType pivot = L.r[low];
    while (low < high) {
        while (low < high && L.r[high].key >= pivot.key) high--;
        L.r[low] = L.r[high];
        while (low < high && L.r[low].key <= pivot.key) low++;
        L.r[high] = L.r[low];
    }
    L.r[low] = pivot;
    return low;
}

void QSort(SqList &L, int low, int high) {
    if (low >= high) return;
    int pivotloc = Partition(L, low, high);
    L.Load();
    QSort(L, low, pivotloc-1);
    QSort(L, pivotloc+1, high);
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