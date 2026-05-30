#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int MAXN = 1010;
int n,m,k;
int maze[MAXN][MAXN];
int dxy[8][2] = {
    {-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}
};

typedef struct {
    int x;
    int y;
    int step;
} Point;

void mem_out(int ma[][MAXN])
{
    for (int i=0;i<=n+1;++i) {
        for (int j=0;j<=m+1;++j) {
            printf("%d ",ma[i][j]);
        }
        printf("\n");
    }
    return;
}

void bfs(int x,int y)
{

    return;
}

int main()
{
    queue<Point> points;
    scanf("%d%d%d\n",&n,&m,&k);
    for (int i = 1; i <= n; i++) {
        char s[MAXN];
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++) {
            if (s[j] == '*') maze[i][j] = 0;
            else if (s[j] == '#') maze[i][j] = 1;
            else if (s[j] == '@') {
                maze[i][j] = 2;
                points.push({i, j, 0});
            }
        }
    }
    Point temp;
    while (!points.empty()) {
        temp = points.front(); points.pop();
        if (temp.step == k) continue;
        for (int i=0;i<8;++i) {
            int dx = temp.x + dxy[i][0];
            int dy = temp.y + dxy[i][1];
            if (dx < 1 || dx > n || dy < 1 || dy > m) continue;
            if (maze[dx][dy] == 0) {
                maze[dx][dy] = 3;
                points.push({dx,dy,temp.step+1});
            }
        }
    }
    int cnt = 0;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            if (maze[i][j] == 2 || maze[i][j] == 3) cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}
