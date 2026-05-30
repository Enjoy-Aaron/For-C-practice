#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
const int MAXN = 300, MAXS = 2e4+10;
int N,L,M,S;
typedef struct {
    int dist;
    int cost;
} Station;
Station sta[MAXN];
set<int> c[MAXN];

typedef struct {
    bool operator() (const Station &a, const Station &b) const
    {
        if (a.dist != b.dist) return a.dist < b.dist;
        return a.cost < b.cost;
    }
} cmp;

int main()
{
    scanf("%d%d%d%d",&N,&L,&M,&S);
    for (int i=1;i<=N;++i) {
        scanf("%d%d",&sta[i].dist,&sta[i].cost);
    }
    sta[0].dist = 0; sta[0].cost = 0;
    sort(sta+1,sta+N+1,cmp());
    c[0].insert(0);
    for (int i=0;i<N;++i) {
        for (auto temp_c : c[i]) {
            if (L - sta[i].dist <= M) {
                printf("Yes");return 0;
            }
            for (int j=i+1;j<=N;++j) {
                int dist = sta[j].dist - sta[i].dist;
                if (dist > M) break;
                int dc = temp_c + sta[j].cost;
                if (dc <=S) {
                    c[j].insert(dc);
                }
            }
        }
    }
    for (int i=0; i<=N; ++i) {
        if (L - sta[i].dist <= M && !c[i].empty()) {
            printf("Yes"); return 0;
        }
    }
    printf("No");
    return 0;
}
