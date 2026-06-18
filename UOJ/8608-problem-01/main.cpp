#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

// 二叉排序树结点定义（无平衡因子）
typedef struct BSTNode {
    int data;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

// 函数声明
void InsertBST(BSTree &T, int key);          // 插入新结点
int SearchBST(BSTree T, int key);            // 查找关键字，成功返回1，失败返回0
void PreOrder(BSTree T, vector<int> &res);   // 递归前序
void InOrder(BSTree T, vector<int> &res);    // 递归中序
void PostOrder(BSTree T, vector<int> &res);  // 递归后序
void InOrderNonRec(BSTree T, vector<int> &res); // 中序非递归
void LevelOrder(BSTree T, vector<int> &res); // 层次遍历
void SwapTree(BSTree T);                     // 交换左右子树
int TreeDepth(BSTree T);                     // 求深度
int LeafCount(BSTree T);                     // 叶子结点数
void PrintVec(const vector<int> &v);         // 输出序列

// ---------- 主函数（严格按照题目输入输出格式） ----------
int main() {
    int n;
    cin >> n;
    BSTree T = nullptr;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        InsertBST(T, x);
    }
    int key1, key2, insKey;
    cin >> key1 >> key2 >> insKey;

    // 原始树遍历
    vector<int> pre, in, post;
    PreOrder(T, pre); InOrder(T, in); PostOrder(T, post);
    PrintVec(pre); PrintVec(in); PrintVec(post);

    // 查找结果
    cout << SearchBST(T, key1) << endl;
    cout << SearchBST(T, key2) << endl;

    // 插入新结点
    InsertBST(T, insKey);

    // 插入后的递归遍历
    pre.clear(); in.clear(); post.clear();
    PreOrder(T, pre); InOrder(T, in); PostOrder(T, post);
    PrintVec(pre); PrintVec(in); PrintVec(post);

    // 插入后的中序非递归
    vector<int> inNonRec;
    InOrderNonRec(T, inNonRec);
    PrintVec(inNonRec);

    // 插入后的层次遍历
    vector<int> level;
    LevelOrder(T, level);
    PrintVec(level);

    // 第一次交换左右子树
    SwapTree(T);
    pre.clear(); in.clear(); post.clear();
    PreOrder(T, pre); InOrder(T, in); PostOrder(T, post);
    PrintVec(pre); PrintVec(in); PrintVec(post);

    // 第二次交换（恢复原状）
    SwapTree(T);
    pre.clear(); in.clear(); post.clear();
    PreOrder(T, pre); InOrder(T, in); PostOrder(T, post);
    PrintVec(pre); PrintVec(in); PrintVec(post);

    // 深度和叶子数
    cout << TreeDepth(T) << endl;
    cout << LeafCount(T) << endl;

    return 0;
}

// ---------- 功能实现 ----------
// 二叉排序树插入（递归）
void InsertBST(BSTree &T, int key) {
    if (T == nullptr) {
        T = new BSTNode;
        T->data = key;
        T->lchild = T->rchild = nullptr;
        return;
    }
    if (key < T->data)
        InsertBST(T->lchild, key);
    else if (key > T->data)
        InsertBST(T->rchild, key);
    // 若相等，题目不要求处理，忽略
}

// 查找
int SearchBST(BSTree T, int key) {
    while (T) {
        if (key == T->data) return 1;
        else if (key < T->data) T = T->lchild;
        else T = T->rchild;
    }
    return 0;
}

// 递归遍历
void PreOrder(BSTree T, vector<int> &res) {
    if (T) {
        res.push_back(T->data);
        PreOrder(T->lchild, res);
        PreOrder(T->rchild, res);
    }
}
void InOrder(BSTree T, vector<int> &res) {
    if (T) {
        InOrder(T->lchild, res);
        res.push_back(T->data);
        InOrder(T->rchild, res);
    }
}
void PostOrder(BSTree T, vector<int> &res) {
    if (T) {
        PostOrder(T->lchild, res);
        PostOrder(T->rchild, res);
        res.push_back(T->data);
    }
}

// 中序非递归
void InOrderNonRec(BSTree T, vector<int> &res) {
    stack<BSTree> st;
    BSTree p = T;
    while (p || !st.empty()) {
        while (p) {
            st.push(p);
            p = p->lchild;
        }
        p = st.top(); st.pop();
        res.push_back(p->data);
        p = p->rchild;
    }
}

// 层次遍历（队列）
void LevelOrder(BSTree T, vector<int> &res) {
    if (!T) return;
    queue<BSTree> q;
    q.push(T);
    while (!q.empty()) {
        BSTree p = q.front(); q.pop();
        res.push_back(p->data);
        if (p->lchild) q.push(p->lchild);
        if (p->rchild) q.push(p->rchild);
    }
}

// 交换左右子树（递归）
void SwapTree(BSTree T) {
    if (T) {
        swap(T->lchild, T->rchild);
        SwapTree(T->lchild);
        SwapTree(T->rchild);
    }
}

// 深度
int TreeDepth(BSTree T) {
    if (!T) return 0;
    return max(TreeDepth(T->lchild), TreeDepth(T->rchild)) + 1;
}

// 叶子数
int LeafCount(BSTree T) {
    if (!T) return 0;
    if (!T->lchild && !T->rchild) return 1;
    return LeafCount(T->lchild) + LeafCount(T->rchild);
}

// 输出序列
void PrintVec(const vector<int> &v) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cout << ' ';
        cout << v[i];
    }
    cout << endl;
}