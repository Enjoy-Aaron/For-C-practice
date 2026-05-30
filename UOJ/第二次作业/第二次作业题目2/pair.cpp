#include <iostream>
#include <cstdio>
using namespace std;

pair<int,int> pa,pb;

int main()
{
    int a_x,a_y,b_x,b_y;
    while(cin >> a_x>>a_y>>b_x>>b_y) {
        pa = make_pair(a_x,a_y);
        pb = make_pair(b_x,b_y);
        char op;
        if (pa<pb) op = '<';
        else if (pa == pb) op = '=';
        else op = '>';
        printf("(%d,%d) %c (%d,%d)\n",pa.first,pa.second,op,pb.first,pb.second);
    }
    return 0;
}
