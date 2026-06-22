#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int MAXN = 500010;

typedef struct stu{
    int num;
    int time;
    char name[50];
    int order;
    bool operator<(const struct stu& other) const{
        if (this->num != other.num) return this->num < other.num;
        if (this->time != other.time) return this->time > other.time;
        return this->order > other.order;
    }
}stu;

priority_queue<stu> pq;

int main() {
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; ++i) {
        int num, time;
        char name[50];
        scanf("%d%d%s",&num, &time, name);
        stu tmp;
        tmp.num = num;
        tmp.time = time;
        strcpy(tmp.name, name);
        tmp.order = i;
        pq.push(tmp);
    }
    while (!pq.empty()) {
        stu tmp = pq.top(); pq.pop();
        printf("%s\n",tmp.name);
    }
}
