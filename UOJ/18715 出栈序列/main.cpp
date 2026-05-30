#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#define MAX(a,b) (a>b? a:b)
using namespace std;
const int MAXN = 110;

int main()
{
    int n, tmp, max_num=0;
    stack<int> nums;
    queue<int> in_nums;
    scanf("%d",&n);
    for (int i=0; i<n; ++i) {
        scanf("%d",&tmp);
        in_nums.push(tmp);
        max_num = MAX(max_num, tmp);
    }
    while (!in_nums.empty()) {
        int in_num = in_nums.front();
        max_num = 0;
        for (int i=0; i<in_nums.size(); ++i) {
            int temp = in_nums.front(); in_nums.pop();
            max_num = MAX(max_num, temp);
            in_nums.push(temp);
        }
        //printf("in_num:%d  max_num:%d\n",in_num,max_num);
        if (nums.empty()) {
            nums.push(in_num);
            in_nums.pop();
            continue;
        }
        int num = nums.top();
        if (num >= max_num) {
            printf("%d ",num);
            nums.pop();
            continue;
        }
        nums.push(in_num); in_nums.pop();
    }
    while (!nums.empty()) {
        printf("%d ",nums.top());
        nums.pop();
    }
    return 0;
}
