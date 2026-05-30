#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct cmp {
    bool operator() (const int &a, const int &b) const {
        int tmp_a = a%10;
        int tmp_b = b%10;
        return tmp_a > tmp_b;
    }
};

void traverse(priority_queue<int,vector<int>,cmp> Q)
{
    printf("traverse:\n");
    int tmp;
    while (!Q.empty()) {
        tmp = Q.top();Q.pop();
        cout << tmp << endl;
    }
    return;
}

int main()
{
    priority_queue<int, vector<int>, cmp> Q;
    int n,tmp;
    cin >> n;
    while (n--) {
        cin >> tmp;
        Q.push(tmp);
    }
    traverse(Q);
    return 0;
}
