#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// 插入结点
void insert(Node*& root, int key) {
    if (!root) {
        root = new Node(key);
        return;
    }
    if (key < root->val)
        insert(root->left, key);
    else if (key > root->val)
        insert(root->right, key);
    // 如果相等，忽略（二叉排序树不插入重复值）
}

// 查找关键字
bool search(Node* root, int key) {
    if (!root) return false;
    if (key == root->val) return true;
    if (key < root->val) return search(root->left, key);
    else return search(root->right, key);
}

// 前序遍历（递归）
void preorder(Node* root, vector<int>& res) {
    if (!root) return;
    res.push_back(root->val);
    preorder(root->left, res);
    preorder(root->right, res);
}

// 中序遍历（递归）
void inorder(Node* root, vector<int>& res) {
    if (!root) return;
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}

// 后序遍历（递归）
void postorder(Node* root, vector<int>& res) {
    if (!root) return;
    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->val);
}

// 中序遍历（非递归）
void inorderNonRecur(Node* root, vector<int>& res) {
    stack<Node*> st;
    Node* cur = root;
    while (cur || !st.empty()) {
        while (cur) {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();
        res.push_back(cur->val);
        cur = cur->right;
    }
}

// 层次遍历
void levelOrder(Node* root, vector<int>& res) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();
        res.push_back(cur->val);
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}

// 交换各结点的左右子树
void swapTree(Node* root) {
    if (!root) return;
    swap(root->left, root->right);
    swapTree(root->left);
    swapTree(root->right);
}

// 求二叉树的深度
int depth(Node* root) {
    if (!root) return 0;
    return 1 + max(depth(root->left), depth(root->right));
}

// 求叶子结点数
int leafCount(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return leafCount(root->left) + leafCount(root->right);
}

// 输出序列
void printVec(const vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i > 0) cout << ' ';
        cout << vec[i];
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        insert(root, x);
    }

    int key1, key2, insKey;
    cin >> key1 >> key2 >> insKey;

    // 原始树的三种遍历
    vector<int> pre, in, post;
    preorder(root, pre);
    inorder(root, in);
    postorder(root, post);
    printVec(pre);
    printVec(in);
    printVec(post);

    // 查找
    cout << (search(root, key1) ? 1 : 0) << endl;
    cout << (search(root, key2) ? 1 : 0) << endl;

    // 插入新结点
    insert(root, insKey);

    // 新树的三种遍历
    pre.clear(); in.clear(); post.clear();
    preorder(root, pre);
    inorder(root, in);
    postorder(root, post);
    printVec(pre);
    printVec(in);
    printVec(post);

    // 新树的中序非递归遍历
    vector<int> inNonRecur;
    inorderNonRecur(root, inNonRecur);
    printVec(inNonRecur);

    // 新树的层次遍历
    vector<int> level;
    levelOrder(root, level);
    printVec(level);

    // 第一次交换左右子树
    swapTree(root);
    pre.clear(); in.clear(); post.clear();
    preorder(root, pre);
    inorder(root, in);
    postorder(root, post);
    printVec(pre);
    printVec(in);
    printVec(post);

    // 第二次交换左右子树（恢复原状）
    swapTree(root);
    pre.clear(); in.clear(); post.clear();
    preorder(root, pre);
    inorder(root, in);
    postorder(root, post);
    printVec(pre);
    printVec(in);
    printVec(post);

    // 深度和叶子结点数（当前树为新树）
    cout << depth(root) << endl;
    cout << leafCount(root) << endl;

    return 0;
}
