#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int A[3][1001],x,y;
long long cnt=0;

void solve(int row, int n)
{
    if (row==n) {
        cnt++;
        return;
    }
    for (int col=0;col<n;++col) {
        if (A[0][col] || A[1][col+row] || A[2][row-col+n]) continue;
        if (row==x && col==y) continue;
        A[0][col] = A[1][col+row] = A[2][row-col+n] = 1;
        solve(row+1,n);
        A[0][col] = A[1][col+row] = A[2][row-col+n] = 0;
    }
}

int main()
{
    int T,m;
    scanf("%d",&T);
    while (T--) {
        memset(A,0,sizeof(A));
        cnt=0;
        scanf("%d%d%d",&m,&x,&y);
        x--;y--;
        solve(0,m);
        printf("%lld\n",cnt);
    }
    return 0;
}
