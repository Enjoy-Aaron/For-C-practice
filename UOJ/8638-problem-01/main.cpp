#include <iostream>
#include <cstdio>
#define MAXNSIZE 320
using namespace std;
typedef int KeyType;
typedef struct RedType{
    KeyType key;
}RedType;
typedef struct {
    RedType r[MAXNSIZE + 1];
    int length;
}SqList;
void Load_Sq(SqList &L);
void InsertSort(SqList &L) {
    for (int i=2; i<=L.length; ++i) {
        if (L.r[i].key < L.r[i-1].key) {
            L.r[0].key = L.r[i].key;
            int j;
            for (j=i-1; L.r[j].key > L.r[0].key; j--) {
                L.r[j+1].key = L.r[j].key;
            }
            L.r[j+1].key = L.r[0].key;
        }
        Load_Sq(L);
    }
}

void Load_Sq(SqList &L) {
    for (int i=1;i<=L.length; ++i) cout << L.r[i].key << " ";
    cout << endl;
}

int main() {
    SqList L;
    cin >> L.length;
    for (int i=1;i<=L.length;++i) cin >> L.r[i].key;
    InsertSort(L);
    return 0;
}