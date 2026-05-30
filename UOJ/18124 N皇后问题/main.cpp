#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 110;
int A[3][MAXN];

void solve(int row, int n, long long &cnt)
{
    if (row==n) {
        cnt++;
        return;
    }
    for (int col=0;col<n;++col) {
        if (A[0][col] || A[1][row+col] || A[2][row-col+n]) continue;
        A[0][col] = A[1][row+col] = A[2][row-col+n] = 1;
        solve(row+1, n, cnt);
        A[0][col] = A[1][row+col] = A[2][row-col+n] = 0;
    }
    return;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        long long cnt=0;
        solve(0,n,cnt);
        printf("%lld\n",cnt);
    }
    return 0;
}
