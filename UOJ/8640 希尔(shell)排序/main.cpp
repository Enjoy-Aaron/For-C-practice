#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1010;

typedef struct {
    int *r = new int[MAXN];
    int length = 0;
}SqList;

int main()
{
    SqList T:
    int n;
    scanf("%d",&n);
    T.length = n;
    for (int i=1;i<=n;++i) {
        scanf("%d",&T.r[i]);
    }
    return 0;
}
