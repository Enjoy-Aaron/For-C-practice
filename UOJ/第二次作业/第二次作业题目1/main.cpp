#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define MIN(a,b) (a<b ? a:b)
using namespace std;
const int MAXN = 110;
const int INF = 1e7;
typedef struct {
    int current_x;
    int current_y;
    int current_step;
}Point;

//全局变量----------------------------
int n,m,sx,sy,ex,ey;
int ans_step;
int map_information[MAXN][MAXN];
int dxy[4][2] = {
    {-1,0}, {0,1}, {1,0}, {0,-1}
};
bool is_visit[MAXN][MAXN];
queue<Point> approach_Q;
//--------------------------------------

bool is_ok(int x, int y)
{
    if (map_information[x][y] == 0 && is_visit[x][y] == 0) return 1;
    return 0;
}

bool bfs()
{
    Point tmp_point;
    while (!approach_Q.empty()) {
        tmp_point = approach_Q.front(); approach_Q.pop();
        //printf("%d %d\n",tmp_point.current_x, tmp_point.current_y);
        if (tmp_point.current_x == ex && tmp_point.current_y == ey) {
            ans_step = tmp_point.current_step;
            return 1;
        }
        for (int i=0;i<4;++i) {
            int dx = tmp_point.current_x + dxy[i][0];
            int dy = tmp_point.current_y + dxy[i][1];
            if (is_ok(dx,dy)) {
                approach_Q.push({dx,dy,tmp_point.current_step + 1});
                is_visit[dx][dy] = 1;
            }
        }
    }
    return 0;
}

void dfs(int x,int y,int step)
{
    if (x == ex && y == ey) {
        ans_step = MIN(ans_step, step);
    }
    for (int i=0;i<4; ++i) {
        int dx = x + dxy[i][0];
        int dy = y + dxy[i][1];
        if (is_ok(dx,dy)) {
            is_visit[dx][dy] = 1;
            dfs(dx, dy, step + 1);
            is_visit[dx][dy] = 0;
        }
    }
    return;
}

int main()
{
    cin >> n >> m;
    cin >> sx >> sy >> ex >>ey;
    //初始化地图
    for (int i=0;i<=n+1;++i) {
        for (int j=0;j<=m+1;++j) {
            if (i==0 || j==0 || i == n+1 || j == m+1) {
                map_information[i][j] = 1; continue;    //设置边界
            }
            cin >> map_information[i][j];
        }
    }

    sx++;sy++;ex++;ey++;//行列从(0,0)开始编号

    //bfs实现-------------------------
    approach_Q.push({sx,sy,0}); //初始化开始点
    is_visit[sx][sy] = 1;   //标记开始点
    if (bfs()) cout << ans_step << endl;
    else printf("-1\n");
    //---------------------------------

    //dfs实现-------------------------
    ans_step = INF;
    memset(is_visit,0,sizeof(is_visit));
    is_visit[sx][sy] = 1; //标记点S
    dfs(sx,sy,0);
    if (ans_step == INF) printf("-1\n");
    else cout << ans_step << endl;
    //---------------------------------

    return 0;
}
