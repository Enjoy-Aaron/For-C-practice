#include <iostream>
#include <cstdio>
#define MAXN 1100
using namespace std;

typedef struct SSTable {
    int *elem;
    int length;
}SSTable;

void Create(SSTable &ST) {
    ST.elem = new int[MAXN];
    cin >> ST.length;
    for (int i=0; i<ST.length; ++i) {
        scanf("%d",&ST.elem[i]);
    }
    return;
}

int BiSearch_Sq(SSTable ST, int key) {
    int low = 0, high = ST.length - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (ST.elem[mid] == key) return mid;
        if (ST.elem[mid] > key) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main() {
    SSTable ST;
    Create(ST);
    int key;
    scanf("%d",&key);
    int loc = BiSearch_Sq(ST, key);
    if (loc == -1) {
        printf("The element is not exist.\n");
    }
    else {
        printf("The element position is %d.\n",loc);
    }
    return 0;
}