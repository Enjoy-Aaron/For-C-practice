#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAXN = 1010;
bool A[MAXN][3];
int m, x, y;
ll res = 0;

void solve(int row) {
    if (row > m) {
        res++;
        return;
    }
    for (int col=1; col<=m; col++) {
        if (row==x && col==y) continue;
        if(A[col][0]==1 || A[row+col][1] == 1 || A[row-col+m][2] == 1) continue;
        A[col][0] = A[row+col][1] = A[row-col+m][2] = 1;
        solve(row+1);
        A[col][0] = A[row+col][1] = A[row-col+m][2] = 0;
    }
}

int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        memset(A, 0, sizeof(A));
        res = 0;
        scanf("%d%d%d",&m,&x,&y);
        solve(1);
        printf("%lld\n",res);
    }
    return 0;
}