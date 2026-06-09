#include <cstdio>
#include <algorithm> // 必须包含，用于 lower_bound
using namespace std;

const int MAXN = 100010; // 适配 1e5 数据规模
int a[MAXN];

int main() {
    int n, q, x;
    // 输入序列长度
    scanf("%d", &n);
    // 输入非降序列（存储为 1 下标，直接匹配题目要求）
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    // 输入查询次数
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &x);
        // lower_bound：找第一个 >=x 的元素迭代器
        // 参数：起始地址，结束地址，目标值
        auto it = lower_bound(a + 1, a + n + 1, x);
        // 迭代器 - 数组首地址 = 下标
        int pos = it - a;
        // 输出结果：超过数组长度则输出 n+1，否则输出下标
        if (pos > n) printf("%d\n", n + 1);
        else printf("%d\n", pos);
    }
    return 0;
}