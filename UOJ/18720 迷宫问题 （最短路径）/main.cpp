#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
using namespace std;
int n,m;
string maze[20];
int dxy[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
typedef struct {
    int x;
    int y;
    int step;
}Point;
queue<Point> points;

void bfs(int x,int y)
{
    bool flag=0;
    Point temp;
    temp.x = x; temp.y = y; temp.step = 0;
    points.push({temp.x,temp.y,temp.step});
    while (!points.empty()) {
        temp = points.front();points.pop();
        if (temp.x == n && temp.y == m) {
            flag=1;
            break;
        }
        for (int i=0;i<4;++i) {
            int dx = temp.x + dxy[i][0];
            int dy = temp.y + dxy[i][1];
            if (maze[dx][dy] == '1') continue;
            maze[dx][dy] = '1';
            points.push({dx,dy,temp.step+1});
        }
    }
    if (flag) printf("%d\n",temp.step);
    else printf("-1\n");
}

int main()
{
    string str;
    scanf("%d%d",&n,&m);
    for (int i=0; i<=n+1;++i) {
        if (i==0 || i==n+1) {
            maze[i].insert(maze[i].begin(),m+2,'1');
            continue;
        }
        cin >> str;
        maze[i] = '1' + str + '1';
    }
    bfs(1,1);
    return 0;
}
