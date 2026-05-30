#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    int n,tmp;
    stack<int> ns;
    queue<int> s, na;
    scanf("%d",&n);
    for (int i=0; i<n; ++i) {
        scanf("%d",&tmp);
        s.push(tmp);
    }
    for (int i=0; i<n; ++i) {
        scanf("%d",&tmp);
        na.push(tmp);
    }
    while(!s.empty()) {
        if (na.front() != s.front()) {
            if (!ns.empty() && ns.top() == na.front()) {
                na.pop(); ns.pop();
            }
            else {
                ns.push(s.front()); s.pop();
            }
        }
        else {
            na.pop(); s.pop();
        }
    }
    bool flag = 1;
    while (!ns.empty() && !na.empty()) {
        if (ns.top() == na.front()) {
            ns.pop(); na.pop();
        }
        else {
            flag = 0;break;
        }
    }
    if (flag) printf("yes");
    else printf("no");
    return 0;
}
