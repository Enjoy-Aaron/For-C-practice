#include <iostream>
#include <string>
using namespace std;

// 递归解压缩函数
// s: 原始字符串（引用传递）
// i: 当前遍历的索引（引用传递，递归中会同步更新位置）
string dfs(string &s, int &i) {
    string res;  // 存储当前层解析后的结果
    int len = s.size();
    
    while (i < len) {
        // 1. 遇到普通大写字母，直接拼接
        if (s[i] >= 'A' && s[i] <= 'Z') {
            res += s[i];
            i++;
        }
        // 2. 遇到 [ ，开始解析压缩块
        else if (s[i] == '[') {
            i++;  // 跳过 '['
            // 提取重复次数 m
            int m = 0;
            while (s[i] >= '0' && s[i] <= '9') {
                m = m * 10 + (s[i] - '0');
                i++;
            }
            i++;  // 跳过分隔符 '|'
            
            // 递归解析内层字符串
            string sub = dfs(s, i);
            
            i++;  // 跳过结束符 ']'
            
            // 将子串重复 m 次，拼接到结果
            for (int k = 0; k < m; k++) {
                res += sub;
            }
        }
        // 3. 遇到 ] ，当前层递归结束，返回结果
        else if (s[i] == ']') {
            break;
        }
    }
    return res;
}

int main() {
    string s;
    cin >> s;    // 输入压缩字符串
    int i = 0;   // 初始索引
    string ans = dfs(s, i);  // 递归解压缩
    cout << ans << endl;     // 输出结果
    return 0;
}