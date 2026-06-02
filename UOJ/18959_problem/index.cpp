#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;        // 输入顺序存储的二叉树字符串
    int n = s.size();
    queue<int> q;    // 队列存储节点的下标
    q.push(0);       // 根节点下标为0
    int level = 1;   // 记录当前层数，第一层正序

    while (!q.empty()) {
        int level_size = q.size();  // 当前层的节点数量
        vector<char> cur_layer;      // 存储当前层的有效节点

        // 遍历当前层所有节点
        for (int i = 0; i < level_size; ++i) {
            int idx = q.front();
            q.pop();

            // 跳过空节点（#）和越界下标
            if (idx >= n || s[idx] == '#') continue;

            cur_layer.push_back(s[idx]);
            // 入队左右孩子下标
            q.push(2 * idx + 1);
            q.push(2 * idx + 2);
        }

        // 之字形：偶数层反转
        if (level % 2 == 0) {
            reverse(cur_layer.begin(), cur_layer.end());
        }

        // 输出当前层
        for (int i = 0; i < cur_layer.size(); ++i) {
            if (i > 0) cout << " ";
            cout << cur_layer[i];
        }
        cout << endl;
        level++;
    }
    return 0;
}