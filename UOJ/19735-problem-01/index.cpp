#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int MAXN = 1e5+10;
int T, M, X, Y, A[3][MAXN];
ll ans=0;

void DFS(int row) {
    if (row == M) {
        ans++;
        return;
    }
    for (int col = 0; col < M; ++col) {
        if (row == X - 1 && col == Y - 1) continue;
        if (A[0][col] == 1 || A[1][row + col] == 1 || A[2][row - col + M] == 1) continue;
        A[0][col] = A[1][row + col] = A[2][row - col + M] = 1;
        DFS(row + 1);
        A[0][col] = A[1][row + col] = A[2][row - col + M] = 0;
    }
}

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d%d",&M, &X, &Y);
        ans = 0;
        DFS(0);
        printf("%lld\n", ans);
    }
    return 0;
}