#include <iostream>
#include <cstdio>
#define MAXSIZE 100
using namespace std;

typedef struct RedType {
    int key;

    RedType& operator=(const RedType& other) {
        this->key = other.key;
        return *this;
    }
}RedType;

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
        cin >> L.r[i].key;
    }
}

void MergetSortNonr(SqList &L) {
    RedType *tmp = new RedType[MAXSIZE + 1];
    int left = 1, right = L.length;
    int gap = 1;
    while (gap < L.length) {
        for (int i=1; i<=L.length; i+=2*gap) {
            int begin1 = i, end1 = i + gap - 1, mid = i + gap - 1;
            int begin2 = mid + 1, end2 = i + 2 * gap - 1;
            int idx = i;
            if (begin2 > right) break;
            if (end2 > right) end2 = right;
            while (begin1 <= end1 && begin2 <= end2) {
                if (L.r[begin1].key < L.r[begin2].key) tmp[idx++] = L.r[begin1++];
                else tmp[idx++] = L.r[begin2++];
            }
            while (begin1 <= end1) tmp[idx++] = L.r[begin1++];
            while (begin2 <= end2) tmp[idx++] = L.r[begin2++];
            for (int j=i; j<=end2; ++j) L.r[j] = tmp[j];
        }
        gap *= 2;
        L.Load();
    }
}

int main() {
    SqList L;
    Create_Sq(L);
    MergetSortNonr(L);
    return 0;
}