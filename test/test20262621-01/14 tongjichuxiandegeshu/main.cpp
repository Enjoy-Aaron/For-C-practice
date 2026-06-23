#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> cnt;
struct stu{
    int num;
    int time;
}stu[1010];

bool cmp(struct stu& a, struct stu& b) {
    if (a.time != b.time) return a.time > b.time;
    return a.num < b.num;
}

int main() {
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; ++i) {
        int num;
        scanf("%d",&num);
        if (cnt.find(num) == cnt.end()) cnt[num] = 1;
        else cnt[num]++;
    }
    int tot = 0;
    for (auto it : cnt) {
        stu[tot].num = it.first;
        stu[tot].time = it.second;
        tot++;
    }
    sort(stu, stu+tot, cmp);
    for (int i=0; i<3; ++i) {
        printf("%d %d\n",stu[i].num, stu[i].time);
    }
    return 0;
}