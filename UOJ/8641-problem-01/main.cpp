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

void BubbleSort(SqList &L) {
    bool flag = true;
    for (int i=L.length-1; i>=1 && flag == true; --i) {
        flag = false;
        for (int j=1; j<=i; ++j) {
            if (L.r[j].key > L.r[j+1].key) {
                L.r[0] = L.r[j];
                L.r[j] = L.r[j+1];
                L.r[j+1] = L.r[0];
                flag = true;
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