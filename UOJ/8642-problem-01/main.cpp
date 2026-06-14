#include <iostream>
#include <cstdio>
#define MAXSIZE 100
using namespace std;

typedef int KeyType;
typedef struct RedType {
    KeyType key;

    RedType(KeyType init_key=0) : key(init_key) {}

    RedType& operator=(const RedType& new_red) {
        if (this != &new_red) {
            this->key = new_red.key;
        }
        return *this;
    }

    friend istream& operator>>(istream& in, RedType& rt);
}RedType;
istream& operator>>(istream& in, RedType& rt) {
    in >> rt.key;
    return in;
}
typedef struct SqList {
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
        cin >> L.r[i];
    }
}

int Partition(SqList &L, int low, int high) {
    int pivotkey = L.r[low].key;
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
    if (low < high) {
        int pivotloc = Partition(L, low, high);
        L.Load();
        QSort(L, low, pivotloc-1);
        QSort(L, pivotloc+1, high);
    }
    return;
}

void QuickSort(SqList &L) {
    QSort(L, 1, L.length);
    return;
}

int main() {
    SqList L;
    Create_Sq(L);
    QuickSort(L);
    return 0;
}