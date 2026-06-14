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
            int low = 1, high = i - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
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