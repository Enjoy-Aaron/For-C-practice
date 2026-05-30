#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
const int MAXN = 330;
void mem_out(bool maze[][MAXN],int sz);

void maze_cpy(bool a[][MAXN], int posr, int posc, bool b[][MAXN], int s)
{
    for (int i=posr,ib=1;i<posr+s,ib<=s;++i,ib++) {
        for (int j=posc,jb=1;j<=posc+s,jb<=s;++j,jb++) {
            a[i][j] = b[ib][jb];
        }
    }
    return;
}

void solve(int n,int &sz,bool maze[][MAXN])
{
    if (n==1) {
        sz = 1; maze[1][1] = 1; return;
    }
    int sz_t;
    bool maze_t[MAXN][MAXN];
    memset(maze_t,false,sizeof(maze_t));
    solve(n-1,sz_t,maze_t);
    sz = sz_t * 3;
    maze_cpy(maze,1,1,maze_t,sz_t);
    maze_cpy(maze,1,sz_t*2+1,maze_t,sz_t);
    maze_cpy(maze,sz_t+1,sz_t+1,maze_t,sz_t);
    maze_cpy(maze,sz_t*2+1,1,maze_t,sz_t);
    maze_cpy(maze,sz_t*2+1,sz_t*2+1,maze_t,sz_t);
    return;
}

void mem_out(bool maze[][MAXN],int sz)
{
    for (int i=1;i<=sz;++i) {
        for (int j=1;j<=sz;++j) {
            if (maze[i][j]) printf("X");
            else printf(" ");
        }
        printf("\n");
    }
    return;
}

int main()
{
    int n;
    scanf("%d",&n);
    int sz;
    bool maze[MAXN][MAXN];
    memset(maze,false,sizeof(maze));
    solve(n,sz,maze);
    mem_out(maze,sz);
    return 0;
}
