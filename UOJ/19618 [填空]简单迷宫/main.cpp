#include <stdio.h>
#include <queue>
using namespace std;
typedef struct{
    int r; // row
    int c; // column
    int s; // step
}LOC;
int sr,sc,dr,dc;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
char d[100][100];
void solve(){
    int m,n,i,nr,nc;
    queue<LOC> q;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++) scanf("%s",d[i]);
    scanf("%d%d%d%d",&sr,&sc,&dr,&dc);
    LOC first={sr,sc,0};
    q.push(first);
    while(!q.empty()) {
        LOC temp = q.front();q.pop();
        if (d[temp.r][temp.c] == '1') continue;
        d[temp.r][temp.c] = '1';
        if (temp.r == dr && temp.c == dc) {
            printf("%d\n",temp.s);
            return;
        }
        for (int i=0;i<4;++i) {
            int dx = temp.r + dir[i][0];
            int dy = temp.c + dir[i][1];
            if (dx < 0 || dy < 0 || dx >=m || dy>=n) continue;
            LOC t;
            t.r = dx; t.c = dy; t.s = temp.s+1;
            q.push(t);
         }
    }
    printf("die\n");
}

int main(){
    int n;
    scanf("%d",&n);
    while(n--) solve();
    return 0;
}
