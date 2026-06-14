#include <stdio.h>
#include <string.h>

#define MAXN 1000010

long long tree[MAXN];
int n;
long long m;

// 计算高度为 h 时，能砍下的木材总量
long long calc(long long h)
{
    long long sum = 0;
    for (int i = 0; i < n; ++i)
    {
        if (tree[i] > h)
            sum += tree[i] - h;
    }
    return sum;
}

int main()
{
    scanf("%d%lld", &n, &m);
    long long l = 0, r = 0, ans = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &tree[i]);
        if (tree[i] > r) r = tree[i];
    }

    // 二分答案
    while (l <= r)
    {
        long long mid = l + (r - l) / 2;
        long long total = calc(mid);
        if (total >= m)
        {
            ans = mid;    // 记录合法高度
            l = mid + 1;  // 尝试更高
        }
        else
        {
            r = mid - 1;  // 高度过高，降低
        }
    }
    printf("%lld\n", ans);
    return 0;
}