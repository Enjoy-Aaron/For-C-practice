#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 105;
// 存储每个节点的左、右孩子，0表示没有孩子
int left_child[MAX];
int right_child[MAX];

// 判断一个节点是否是叶子节点
bool is_leaf(int x) {
    return left_child[x] == 0 && right_child[x] == 0;
}

int main() {
    // 初始化所有孩子为0
    memset(left_child, 0, sizeof(left_child));
    memset(right_child, 0, sizeof(right_child));

    int m, n;
    cin >> m >> n;

    // 构建二叉树
    for (int i = 0; i < n; ++i) {
        int fa, son;
        string dir;
        cin >> fa >> dir >> son;
        if (dir == "left") {
            left_child[fa] = son;
        } else {
            right_child[fa] = son;
        }
    }

    int ans = 0;
    // 遍历所有节点，统计符合条件的数量
    for (int i = 1; i <= m; ++i) {
        // 核心条件：有左、有右，且两个都是叶子
        if (left_child[i] != 0 && right_child[i] != 0
            && is_leaf(left_child[i]) && is_leaf(right_child[i])) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}