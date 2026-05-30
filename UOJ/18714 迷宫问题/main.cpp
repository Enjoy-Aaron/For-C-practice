#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
const int MAXN = 20;
string mape[MAXN];
bool is_visit[MAXN][MAXN];
int n,m;
int dxy[4][2]={
    {-1,0},{0,1},{1,0},{0,-1}
};

bool is_ok(int x,int y)
{
    return is_visit[x][y]==0 && mape[x][y]=='0';
}

bool flag = 0;
bool dfs(int x,int y)
{
    if (x==n && y==m || flag == 1) {
        flag = 1;
        return 1;
    }
    for (int i=0;i<4;++i) {
        int dx = x + dxy[i][0];
        int dy = y + dxy[i][1];
        if (is_ok(dx,dy)) {
            is_visit[dx][dy] = 1;
            dfs(dx,dy);
            is_visit[dx][dy] = 0;
        }
    }
    return flag;
}

int main()
{
    cin >> n >> m;
    for (int i=0;i<=n+1;++i) {
        if (i==0 || i==n+1) {
            for (int j=0; j<=m+1; ++j){
                mape[i] += '1';
            }
            continue;
        }
        string str;
        cin >> str;
        mape[i] = '1' + str +'1';
    }
    is_visit[1][1]=1;
    if (dfs(1,1)) printf("yes");
    else printf("no");
    return 0;
}
