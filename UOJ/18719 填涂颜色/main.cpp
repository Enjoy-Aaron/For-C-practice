#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
bool isv[50][50];
int maze[50][50];
int n;
int dxy[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
typedef struct {
    int x;
    int y;
}Point;
queue<Point> points;

bool is_hole(int x,int y)
{
    Point temp;
    temp.x=x;temp.y=y;
    points.push(temp);
    isv[x][y] = 1;
    bool flag = 1;
    while (!points.empty()) {
        temp = points.front();points.pop();
        for (int i=0;i<4;++i) {
            int dx = temp.x + dxy[i][0];
            int dy = temp.y + dxy[i][1];
            if (maze[dx][dy]==-1) {
                flag = 0;continue;
            }
            if (maze[dx][dy]==1 || isv[dx][dy]) continue;
            isv[dx][dy] = 1;
            points.push({dx,dy});
        }
    }
    return flag;
}

void bfs(int x,int y)
{
    Point temp;
    temp.x=x;temp.y=y;
    points.push(temp);
    maze[x][y] = 2;
    while (!points.empty()) {
        temp = points.front();points.pop();
        for (int i=0;i<4;++i) {
            int dx = temp.x + dxy[i][0];
            int dy = temp.y + dxy[i][1];
            if (maze[dx][dy]==1 || maze[dx][dy] == 2) continue;
            maze[dx][dy] = 2;
            points.push({dx,dy});
        }
    }
    return;
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<=n+1;++i) {
        for (int j=0;j<=n+1;++j) {
            if (i==0 || i==n+1 || j==0 || j==n+1) {
                maze[i][j]=-1;continue;
            }
            scanf("%d",&maze[i][j]);
        }
    }
    Point target;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            if (isv[i][j] || maze[i][j] == 1) continue;
            if (is_hole(i,j)) {
                target.x = i;
                target.y = j;
                break;
            }
        }
    }
    bfs(target.x, target.y);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            printf("%d ",maze[i][j]);
        }
        printf("\n");
    }
    return 0;
}
