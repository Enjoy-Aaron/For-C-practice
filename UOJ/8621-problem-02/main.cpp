#include <iostream>
#include <cstdio>
using namespace std;

typedef int ElemType;
typedef struct {
    ElemType *elem;
    int length;
}SSTable;

void Create_Seq(SSTable &ST, int n) {
    ST.length = n;
    ST.elem = new ElemType[ST.length + 1];
    int temp;
    for (int i=1;i<=n;++i) {
        scanf("%d",&temp);
        *(ST.elem+i) = temp;
    }
}

int Binary_Search(SSTable ST, ElemType key) {
    int low = 1, high = ST.length;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (ST.elem[mid] == key) return mid;
        if (ST.elem[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return 0;
}

int main() {
    SSTable ST;
    int n;
    scanf("%d",&n);
    Create_Seq(ST, n);
    int loc, key;
    scanf("%d",&key);
    loc = Binary_Search(ST, key);
    if (loc == 0) {
        printf("The element is not exist.\n");
    }
    else {
        printf("The element position is %d.\n",loc);
    }
    return 0;
}