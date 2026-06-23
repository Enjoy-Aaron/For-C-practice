#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 500010;

typedef struct {
    int num;
    int time;
    char name[50];
    int order;
}stu;
stu s[MAXN];

bool cmp(const stu &a, const stu &b) {
    if (a.num != b.num) return a.num > b.num;
    if (a.time != b.time) return a.time < b.time;
    return a.order < b.order;
}

int main() {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;++i) scanf("%d%d%s",&s[i].num, &s[i].time, s[i].name);
    for (int i=0;i<n;++i) s[i].order = i;
    sort(s, s+n, cmp);
    for (int i=0;i<n;++i) printf("%s\n",s[i].name);
    return 0;
}