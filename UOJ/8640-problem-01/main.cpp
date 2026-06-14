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

void Shell_Insert(SqList &L, int dk) {
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

void ShellSort(SqList &L, int dk[], int cnt) {
    for (int k=0; k<cnt; ++k) {
        Shell_Insert(L, dk[k]);
        L.Load();
    }
}

void Create_Sq(SqList &L) {
    cin >> L.length;
    for (int i=1;i<=L.length; ++i) {
        cin >> L.r[i];
    }
}

void Get_dk(int n, int dk[], int &cnt) {
    while (n > 1) {
        dk[cnt++] = n/2;
        n/=2;
    }
}

int main() {
    SqList L;
    Create_Sq(L);
    int dk[MAXSIZE + 1], cnt=0;
    Get_dk(L.length, dk, cnt);
    ShellSort(L, dk, cnt);
    return 0;
}