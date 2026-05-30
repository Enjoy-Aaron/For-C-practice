#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;


typedef struct stu {
    int num;
    int time;
    char name[50];
    int order;
};

struct CompareStu {
        bool operator()(const  stu &a, const stu &b) const {
        if (a.num != b.num) return a.num <  b.num;
        if (a.time != b.time) return a.time > b.time;
        return a.order > b.order;
    }
};

priority_queue<stu, vector<stu>, CompareStu> pq;
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;++i) {
        int a,b;
        char s[50]={};
        scanf("%d%d%s",&a,&b,s);
        stu temp;
        temp.num=a;temp.time=b;strcpy(temp.name,s);temp.order=i;
        pq.push(temp);
    }
    while (!pq.empty()) {
        stu temp = pq.top();pq.pop();
        printf("%s\n",temp.name);
    }
    return 0;
}
