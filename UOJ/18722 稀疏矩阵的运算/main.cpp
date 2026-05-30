#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef struct Point{
    int row;
    int col;
    int data;

    bool operator <(const Point &order) const {
        if (row != order.row) return row>order.row;
        return col > order.col;
    }
} Point;

int main()
{
    priority_queue<Point> pq;
    int n,m,k;
    cin >>n>>m>>k;
    for (int i=0;i<k;++i) {
        Point temp;
        cin >> temp.col >> temp.row >> temp.data;
        pq.push(temp);
    }
    while (!pq.empty()) {
        Point temp = pq.top(); pq.pop();
        printf("%d %d %d\n",temp.row, temp.col, temp.data);
    }
    return 0;
}
