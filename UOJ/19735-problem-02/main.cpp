#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 100;
typedef long long ll;
int m, x, y;
ll ans;
bool A[MAXN][3];

void solve(int row) {
    if (row > m) {
        ans++;
        return;
    }
    for (int col=1; col<=m; ++col) {
        if (A[col][0]==1 || A[row+col][1]==1 || A[row-col+m][2]==1) continue;
        if (row == x && col == y) continue;
        A[col][0]=A[row+col][1]=A[row-col+m][2]=1;
        solve(row+1);
        A[col][0]=A[row+col][1]=A[row-col+m][2]=0;
    }
}

int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        ans=0;
        scanf("%d%d%d",&m,&x,&y);
        memset(A, 0, sizeof(A));
        solve(1);
        printf("%lld\n",ans);
    }
    return 0;
}