#include <iostream>
#include <cstdio>
#define MAXSIZE 110
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
    RedType r[MAXSIZE + 1];
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

void MergeSort_Nonr(SqList &L) {
    int left = 1, right = L.length, gap = 1;
    RedType *temp = new RedType[MAXSIZE + 1];
    while (gap < L.length) {
        for (int i=1; i<=L.length; i+=2*gap) {
            int begin1 = i, end1 = i + gap - 1, mid = end1;
            int begin2 = mid + 1, end2 = begin2 + gap - 1;
            int idx = i;
            if (begin2 > right) break;
            if (end2 > right) end2 = right;
            while (begin1 <= end1 && begin2 <= end2) {
                if (L.r[begin1].key <= L.r[begin2].key) {
                    temp[idx++] = L.r[begin1++];
                }
                else {
                    temp[idx++] = L.r[begin2++];
                }
            }
            while (begin1 <= end1) temp[idx++] = L.r[begin1++];
            while (begin2 <= end2) temp[idx++] = L.r[begin2++];
            for (int j=i; j<=end2; ++j) {
                L.r[j] = temp[j];
            }
        }
        gap *= 2;
        L.Load();
    }
}

int main() {
    SqList L;
    Create_Sq(L);
    MergeSort_Nonr(L);
    return 0;
}