#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;

typedef struct stu {
    int num;
    int time;
    char name[50];
    int order;
    bool operator<(const struct stu& other) const{
        if (this->num != other.num) return this->num < other.num;
        if (this->time != other.time) return this->time > other.time;
        return this->order > other.order;
    }
} STU;

priority_queue<STU> pq;

int main() {
    STU s;
    int n;
    cin >> n;
    for (int i=0;i<n;++i) {
        scanf("%d%d%s",&s.num, &s.time, s.name);
        s.order = i;
        pq.push(s);
    }
    while (!pq.empty()) {
        STU tmp = pq.top();pq.pop();
        printf("%s\n",tmp.name);
    }
    return 0;
}