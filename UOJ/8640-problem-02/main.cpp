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

void ShellInsert(SqList &L, int dk) {
    for (int i=dk+1; i<=L.length; ++i) {
        if (L.r[i].key < L.r[i-dk].key) {
            L.r[0].key = L.r[i].key;
            int j;
            for (j=i-dk; j>=0 && L.r[j].key > L.r[0].key; j-=dk) {
                L.r[j+dk].key = L.r[j].key;
            }
            L.r[j+dk].key = L.r[0].key;
        }
    }
}

void Get_dk(int dk[], int n, int &cnt) {
    cnt = 0;
    while (n>1) {
        dk[cnt++] = n/2;
        n/=2;
    }
}

void ShellSort(SqList &L) {
    int dk[MAXSIZE]={};
    int cnt;
    Get_dk(dk, L.length, cnt);
    for (int i=0;i<cnt; ++i) {
        ShellInsert(L, dk[i]);
        L.Load();
    }
}

int main() {
    SqList L;
    CreateList(L);
    ShellSort(L);
    return 0;
}