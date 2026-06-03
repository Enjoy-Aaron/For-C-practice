#include <iostream>
#include <vector>
#include <algorithm>  // 用于 max 函数
using namespace std;

// 全局变量：记录二叉树的最长路径（边的数量）
int max_length = 0;

// 递归函数：返回当前节点的最大深度（边数），同时更新最长路径
int dfs(int node_idx, vector<char>& tree) {
    // 边界：超出数组范围 或 节点为空（#），深度为-1
    if (node_idx >= tree.size() || tree[node_idx] == '#') {
        return -1;
    }

    // 递归计算左右子树的深度
    int left_depth = dfs(2 * node_idx, tree);
    int right_depth = dfs(2 * node_idx + 1, tree);

    // 更新最长路径：经过当前节点的路径长度 = 左深度 + 右深度 + 2
    max_length = max(max_length, left_depth + right_depth + 2);

    // 返回当前节点的最大深度（到最远叶子的边数）
    return max(left_depth, right_depth) + 1;
}

int main() {
    int n;
    string tree_str;
    // 读取输入
    cin >> n;
    cin >> tree_str;

    // 构建完全二叉树数组（下标从1开始，0位置占位）
    vector<char> tree;
    tree.push_back('\0');  // 下标0无用
    for (char c : tree_str) {
        tree.push_back(c);
    }

    // 初始化最长路径，从根节点（下标1）开始递归
    max_length = 0;
    dfs(1, tree);

    // 输出结果
    cout << max_length << endl;

    return 0;
}