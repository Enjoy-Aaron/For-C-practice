#include <iostream>
#include <cstdio>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
#define MAXSTACKSIZE 100    //栈储存空间初始化分配量
#define MAXQUEUESIZE 100    //队列存储空间初始化分配量
#define MAX(a, b) (a>b ? a:b)   //设置取大比较函数
#define MIN(a, b) (a<b ? a:b)   //设置取小标胶函数
using namespace std;

//变量声明
typedef int Status;         //函数状态类型
typedef int KeyType;        //关键字数据类型
//平衡二叉排序树
typedef struct DataType {   //数据域
    KeyType key;            //关键字
    //InfoType otherInfo;   //其他数据项
    DataType& operator=(const DataType& other_data) {   //重载赋值运算
        if (this != &other_data) {  //若赋值元素与当前元素地址相同则不予赋值
            this->key = other_data.key;
            //otherInfo
        }
        return *this;       //返回this
    }
}DataType;
typedef struct AVLNode {    //结点域
    DataType data;          //数据域
    struct AVLNode *lchild; //左孩子结点
    struct AVLNode *rchild; //右孩子结点
    int bf;                 //平衡因子
}AVLNode, *AVLTree;
//栈
typedef AVLTree SElemType;  //栈元素类型
typedef struct SqStack {
    SElemType *base;        //栈底，也是栈的储存空间
    SElemType *top;         //栈顶
    int stacksize;          //最大栈大小
}SqStack;
//循环队列
typedef AVLTree QEelemType;
typedef struct SqQueue {
    QEelemType *elem;       //队列元素存储空间
    int front;              //队列头下标
    int rear;               //队列尾下标
    int queuesize;          //队列大小
}SqQueue;

//函数声明
Status InitAVLTree(AVLTree &T);         //初始化平衡二叉排序树
Status CreateAVLTree(AVLTree &T);       //创建平衡二叉排序树
Status InsertAVL(AVLTree &T, DataType elem, bool &taller);     //在平衡二叉树中插入新节点
Status DeleteAVL(AVLTree &T, DataType &elem, bool &shorter);   //在平衡二叉树中删除结点
Status LeftBalance_AVL(AVLTree &T);     //左平衡子树操作
Status RightBalance_AVL(AVLTree &T);    //右平衡子树操作
Status L_Rotate(AVLTree &p);            //对根节点p的左旋操作
Status R_Rotate(AVLTree &p);            //对根节点p的右旋操作
Status PreOrderTraverse(AVLTree T);     //对二叉树的前序遍历
Status InOrderTraverse(AVLTree T);      //对二叉树的中序遍历
Status PostOrderTraverse(AVLTree T);    //对二叉树的后序遍历
Status PreOrderTraverse_Nonr(AVLTree T);    //对二叉树的前序遍历（非递归）
Status InOrderTraverse_Nonr(AVLTree T);     //对二叉树的中序遍历（非递归）
Status PostOrderTraverse_Nonr(AVLTree T);   //对二叉树的后序遍历（非递归）
Status LevelOrderTraverse(AVLTree T);       //对二叉树的层次遍历
Status FindTree(AVLTree T, DataType elem);  //在二叉树中查找给定关键字 (函数返回值为成功1,失败0) 
Status SwapTree(AVLTree &T);            //交换各结点的左右子树
Status SwapTNode(AVLTree &T);           //交换该节点左右两子树
int GetTreeDepth(AVLTree T);            //获取二叉树深度
int GetLeafCount(AVLTree T);            //获取二叉树叶子个数
Status InitStack(SqStack &S);           //初始化栈
Status StackPush(SqStack &S,SElemType e);   //在栈S中插入元素e为新的栈顶元素
Status StackPop(SqStack &S,SElemType &e);   //若栈不空，则删除S的栈顶元素返回其值e
Status StackEmpty(SqStack S);           //判断栈是否为空
Status InitQueue(SqQueue &Q);           //初始化队列
Status EnQueue(SqQueue &Q, QEelemType e);   //将新元素压入队列中
Status DeQueue(SqQueue &Q, QEelemType &e);  //队列头元素出队
Status QueueEmpty(SqQueue Q);           //判断队列是否为空

//主函数
int main() {
    AVLTree T;
    InitAVLTree(T);     //初始化平衡二叉树

    printf("0. Exit\n");
    printf("1. Create the AVLTree\n");
    printf("2. Insert a element into AVLTree\n");
    printf("3. PreOderTraverse the AVLTree\n");
    printf("4. InOrderTraverse the AVLTree\n");
    printf("5. PostOrderTraverse the AVLTree\n");
    printf("6. PreOderTraverse the AVLTree (Non Recursive)\n");
    printf("7. InOrderTraverse the AVLTree (Non Recursive)\n");
    printf("8. PostOrderTraverse the AVLTree (Non Recursive)\n");
    printf("9. LevelOrderTraverse the AVLTree\n");
    printf("10. Find the element from tree\n");
    printf("11. Swap the AVLTree\n");
    printf("12. Get the Tree depth\n");
    printf("13. Get the leafcount of tree\n");
    printf("14. Delete a element from AVLTree\n");
    printf("Please Enter the choice: ");

    //测试二叉排序树的各种算法
    int choice;     //输入选项
    while (scanf("%d",&choice) == 1 && choice != 0) {   //选项为0时退出
        switch (choice) {
            case 1: {
                if (CreateAVLTree(T) == OK) {   //创建平衡二叉排序树并进行判断
                    printf("Create AVLTree successfully.\n");
                }
                else {
                    printf("Create AVLTree in failure.\n");
                }
                break;
            }
            case 2: {   //插入元素到平衡二叉排序树中
                DataType data;
                printf("Enter key to insert: ");
                scanf("%d", &data.key);
                bool taller;    //传入参数，记录子树高度是否增加
                if (InsertAVL(T, data, taller) == OK) {
                    printf("Insert %d successfully.\n", data.key);
                }
                else {  //该元素已经存在时返回ERROR
                    printf("Key %d already exists.\n", data.key);
                }
                break;
            }
            case 3: {
                if (PreOrderTraverse(T) == OK) {    //前序遍历二叉排序树成功
                    printf("\n");
                    printf("PreOrderTraverse successfully.\n");
                }
                else {      //二叉树为空
                    printf("The AVLTree is empty.\n");
                }
                break;
            }
            case 4: {
                if (InOrderTraverse(T) == OK) {     //中序遍历二叉排序树成功
                    printf("\n");
                    printf("InOrderTraverse successfully.\n");
                }
                else {      //二叉树为空
                    printf("The AVLTree is empty.\n");
                }
                break;
            }
            case 5: {
                if (PostOrderTraverse(T) == OK) {    //后序遍历二叉排序树成功
                    printf("\n");
                    printf("PostOrderTraverse successfully.\n");
                }
                else {      //二叉树为空
                    printf("The AVLTree is empty.\n");
                }
                break;
            }
            case 6: {
                if (PreOrderTraverse_Nonr(T) == OK) {   //非递归前序遍历二叉排序树成功
                    printf("PreOrderTraverse_Nonr successfully.\n");
                }
                else {      //二叉树为空
                    printf("The AVLTree is empty.\n");
                }
                break;
            }
            case 7: {
                if (InOrderTraverse_Nonr(T) == OK) {    //非递归前序遍历二叉排序树成功
                    printf("InOrderTraverse_Nonr successfully.\n");
                }
                else {      //二叉树为空
                    printf("The AVLTree is empty.\n");
                }
                break;
            }
            case 8: {
                if (PostOrderTraverse_Nonr(T) == OK) {  //非递归前序遍历二叉排序树成功
                    printf("PostOrderTraverse_Nonr successfully.\n");
                }
                else {      //二叉树为空
                    printf("The AVLTree is empty.\n");
                }
                break;
            }
            case 9: {
                if (LevelOrderTraverse(T) == OK) {      //层次遍历二叉排序树成功
                    printf("LevelOrderTraverse successfully.\n");
                }
                else {      //二叉树为空
                    printf("The AVLTree is empty.\n");
                }
                break;
            }
            case 10: {
                DataType elem;
                printf("Enter the element to find: ");
                scanf("%d", &elem.key);
                if (FindTree(T, elem) == TRUE) {        //在二叉树中找到该节点
                    printf("The key %d is found.\n");
                }
                else {
                    printf("Not found.\n");
                }
                break;
            }
            case 11: {
                if (SwapTree(T) == OK) {            //交换每个节点得左右子树
                    printf("Swap the AVLTree successfully.\n");
                }
                else {
                    printf("The AVLTree is empty.\n");
                }
                break;
            }
            case 12: {
                printf("The depth of Tree is %d.\n", GetTreeDepth(T));      //获取二叉树深度
                break;
            }
            case 13: {
                printf("The leaftcount of Tree is %d.\n", GetLeafCount(T)); //获取二叉树的叶子个数
                break;
            }
            case 14: {
                DataType elem;
                printf("Enter the key to delete: ");
                scanf("%d", &elem.key);
                bool shorter;       //作为该子树是否高度减少的传入参数
                if (DeleteAVL(T, elem, shorter) == OK) {
                    printf("Delete %d successfully.\n", elem.key);
                }
                else {  //该元素已经存在时返回ERROR
                    printf("Key %d not exist.\n", elem.key);
                }
                break;
            }
            default: {      //非法选项输入
                printf("Invalid choice.\n");
                break;
            }
        }
    }
}

//各函数功能实现
Status InitAVLTree(AVLTree &T) {    //初始化平衡二叉排序树
    T = NULL;   //初始化根节点为空
    return OK;
}

Status L_Rotate(AVLTree &p) {       //对根节点p的左旋操作
    AVLTree rc = p->rchild; //rc指向根节点的右子树
    p->rchild = rc->lchild; //rc左子树挂接到p的右子树
    rc->lchild = p;         //rc左孩子指向p
    p = rc;                 //p指向新的根节点
    return OK;
}

Status R_Rotate(AVLTree &p) {       //对根节点p的右旋操作
    AVLTree lc = p->lchild; //lc指向根节点的左子树
    p->lchild = lc->rchild; //lc右子树挂接到p的左子树
    lc->rchild = p;         //lc右孩子指向p
    p = lc;                 //p指向新的根节点
    return OK;
}

Status InsertAVL(AVLTree &T, DataType elem, bool &taller) {     //在平衡二叉树中插入新节点
    if (T == NULL) {    //T为新节点
        T = new AVLNode;    //创建新节点
        T->bf = 0;          //平衡因子初始化为0
        T->data = elem;     //赋予新值
        T->lchild = NULL;
        T->rchild = NULL;
        taller = true;      //加入新节点后以该节点为根节点的子树高度增加
        return OK;
    }
    if (elem.key == T->data.key) {  //插入元素的关键字在树中已存在
        taller = false;     //高度不变,不添加元素
        return ERROR;       //反馈为添加失败
    }
    if (elem.key < T->data.key) {   //插入元素的关键字比当前结点小
        //在左子树中插入元素
        if (InsertAVL(T->lchild, elem, taller) == ERROR) return ERROR;   //若插入不成功则返回ERROR反馈给上一层函数
        if (taller == true) {   //左子树高度增加了
            if (T->bf == 0) {   //原本左右子树高度相等
                T->bf++;        //由于左子树高度增加平衡因子加1
                taller = true;  //该结点所对应的子树高度增加
                return OK;
            }
            if (T->bf == 1) {   //原本左子树比右子树高1，插入后该节点平衡因子为2，需要左平衡子树
                LeftBalance_AVL(T);     //左平衡子树
                //平衡后T->bf保持原来不变，因此不需要操作
                taller = false; //平衡后子树高度不增加
                return OK;
            }
            if (T->bf == -1) {  //原本右子树比左子树高1，插入后左子树与右子树高度相等
                T->bf++;        //左子树高度增加
                taller = false; //左右子树高度相等，子树高度未增加
                return OK;
            }
            printf("OverFlowError\n");  //到这一步说明平衡因子不在-1~1，防报错
            return OVERFLOW;
        }
    }
    else {  //插入元素的关键字比当前结点大
        //在右子树中插入元素
        if (InsertAVL(T->rchild, elem, taller) == ERROR) return ERROR;   //若插入不成功则返回ERROR反馈给上一层函数
        if (taller == true) {   //右子树高度增加了
            if (T->bf == 0) {   //原本左右子树高度相等
                T->bf--;        //由于右子树高度增加平衡因子减1
                taller = true;  //该结点所对应的子树高度增加
                return OK;
            }
            if (T->bf == -1) {   //原本右子树比左子树高1，插入后该节点平衡因子为-2，需要右平衡子树
                RightBalance_AVL(T);    //右平衡子树
                //平衡后T->bf保持原来不变，因此不需要操作
                taller = false; //平衡后子树高度不增加
                return OK;
            }
            if (T->bf == 1) {  //原本左子树比右子树高1，插入后左子树与右子树高度相等
                T->bf--;        //右子树高度增加
                taller = false; //左右子树高度相等，子树高度未增加
                return OK;
            }
            printf("OverFlowError\n");  //到这一步说明平衡因子不在-1~1，防报错
            return OVERFLOW;
        }
    }
    return OK;
}

Status DeleteAVL(AVLTree &T, DataType &elem, bool &shorter) {   //在平衡二叉树中删除结点
    if (T == NULL) {
        shorter = false;    //未找到关键字高度不变
        return ERROR;       //未找到关键字
    }
    if (elem.key == T->data.key) {      //找到待删结点
        AVLTree p = T;
        if (T->lchild == NULL) {        //若左子树为空
            T = T->rchild;              //该节点为右子树
            delete p;                   //删除该节点原值
            shorter = true;             //子树变短
        }
        else if (T->rchild == NULL) {   //若右子树为空
            T = T->lchild;              //该节点为左子树
            delete p;                   //删除该节点原值
            shorter = true;             //子树变短
        }
        else {                          //左右子树均存在
            AVLTree s = T->lchild;      //s为左孩子
            while (s->rchild != NULL) { //s的右子树不为空
                s = s->rchild;          //寻找左子树的最右结点
            }
            T->data = s->data;          //用左子树最大值覆盖原节点
            DeleteAVL(T->lchild, s->data, shorter); //删除冗余s结点，且能保证s的有孩子为空
            if (shorter == true) {      //删除后子树变短了
                if (T->bf == 1) {       //原本左子树高，删除后左右子树登高
                    T->bf--;
                    shorter = true;     //子树总高度减少
                }
                else if (T->bf == 0) {  //原本平衡，删除后右子树高
                    T->bf--;
                    shorter = false;
                }
                else if (T->bf == -1) { //原本右子树高，删除后不平衡，需要右平衡子树
                    RightBalance_AVL(T);//右平衡子树
                    shorter = false;    //平衡后该子树高度为减少
                }
                else {      //平衡因子不在-1~1范围内，放报错
                    printf("OverFlowError\n");
                    return OVERFLOW;
                }
            }
        }
        return OK;
    }
    if (elem.key < T->data.key) {   //待删结点较小
        if (DeleteAVL(T->lchild, elem, shorter) == ERROR) return ERROR; //继续向左寻找待删结点，关键字未找到返回ERROR
        if (shorter == true) {      //删除后子树变短了
            if (T->bf == 1) {       //原本左子树高，删除后左右子树登高
                T->bf--;
                shorter = true;     //子树总高度减少
            }
            else if (T->bf == 0) {  //原本平衡，删除后右子树高
                T->bf--;
                shorter = false;
            }
            else if (T->bf == -1) { //原本右子树高，删除后不平衡，需要右平衡子树
                AVLTree rc = T->rchild;
                if (rc->bf == 0) {  //若右孩子平衡因子为0
                    AVLTree rc = T->rchild;
                    T->bf = -1;     //平衡因子修正
                    rc->bf = 1;
                    L_Rotate(T);
                    shorter = false;
                }
                else {
                    RightBalance_AVL(T);//右平衡子树
                    shorter = false;    //平衡后该子树高度为减少
                }
            }
            else {      //平衡因子不在-1~1范围内，放报错
                printf("OverFlowError\n");
                return OVERFLOW;
            }
        }
    }
    else {      //待删结点较大
        if (DeleteAVL(T->rchild, elem, shorter) == ERROR) return ERROR; ////继续向右寻找待删结点，关键字未找到返回ERROR
        if (shorter) {
            switch (T->bf) {
                case -1:            //右子树高1，删除后左右子树等高
                    T->bf++;
                    shorter = true;
                    break;
                case 0:             //原本左右子树登高，删除后左子树高1
                    T->bf++;
                    shorter = false;
                    break;
                case 1:             //原本左子树高1，删除后左子树高2，需左平衡子树
                    AVLTree lc = T->lchild;
                    if (lc->bf == 0) {  //若左孩子平衡因子为0
                        T->bf = 1;
                        lc->bf = -1;    //平衡因子修正
                        R_Rotate(T);
                        shorter = false;
                    }
                    else {
                        LeftBalance_AVL(T); //左平衡子树
                        shorter = false;
                    }
                    break;
            }
        }
    }
    return OK;
}

Status LeftBalance_AVL(AVLTree &T) {    //左平衡子树操作
    AVLTree lc = T->lchild; //lc指向T的左子树根节点
    if (lc->bf == 1) {      //该子树为LL型，需要右旋
        T->bf = 0;  //右旋后结点T的左右子树高度相等
        lc->bf = 0; //右旋后结点lc的左右子树高度相等
        R_Rotate(T);
        return OK;
    }
    if (lc->bf == -1) {     //该子树为LR型，需要先对子树左旋，再进行右旋
        AVLTree rd = lc->rchild;    //rd指向lc右子树
        switch(rd->bf) {    //对rd子树进行左旋后的平衡因子更新
            case 1:        //若rd左子树更深
                T->bf = -1;
                lc->bf = 0;
                break;
            case 0:         //若rd左右子树一样深
                T->bf = 0;
                lc->bf = 0;
                break;
            case -1:        //若rd右子树更深
                T->bf = 0;
                lc->bf = 1;
                break;
            default:
                printf("OverFlowError\n");
                return OVERFLOW;
        }
        rd->bf = 0;         //两次旋转过后，rd为该子树的根节点，且左右子树深度平衡且相等
        L_Rotate(T->lchild);//先对左子树进行左旋
        R_Rotate(T);        //再对根节点所对应的子树进行右旋
        return OK;
    }
    printf("OverFlowError\n");  //运行到这一步说明lc的平衡因子为0，出错且报错
    return OVERFLOW;
}

Status RightBalance_AVL(AVLTree &T) {    //右平衡子树操作
    AVLTree rc = T->rchild; //rc指向T的右子树根节点
    if (rc->bf == -1) {     //该子树为RR型，需要左旋
        T->bf = 0;  //左旋后结点T的左右子树高度相等
        rc->bf = 0; //左旋后结点rc的左右子树高度相等
        L_Rotate(T);
        return OK;
    }
    if (rc->bf == 1) {     //该子树为RL型，需要先对子树右旋，再进行左旋
        AVLTree ld = rc->lchild;    //ld指向rc左子树
        switch(ld->bf) {    //对ld子树进行右旋后的平衡因子更新
            case -1:        //若ld右子树更深
                T->bf = 1;
                rc->bf = 0;
                break;
            case 0:         //若ld左右子树一样深
                T->bf = 0;
                rc->bf = 0;
                break;
            case 1:        //若ld左子树更深
                T->bf = 0;
                rc->bf = -1;
                break;
            default:
                printf("OverFlowError\n");
                return OVERFLOW;
        }
        ld->bf = 0;         //两次旋转过后，ld为该子树的根节点，且左右子树深度平衡且相等
        R_Rotate(T->rchild);//先对右子树进行右旋
        L_Rotate(T);        //再对根节点所对应的子树进行左旋
        return OK;
    }
    printf("OverFlowError\n");  //运行到这一步说明lc的平衡因子为0，出错且报错
    return OVERFLOW;
}

Status CreateAVLTree(AVLTree &T) {  //创建平衡二叉排序树
    InitAVLTree(T); //初始化该二叉树为空
    int n;
    printf("Enter the numbers of elements: ");
    scanf("%d",&n);         //输入元素个数
    printf("Enter the elements:\n");
    bool success = true;    //记录是否创建成功
    for (int i=0; i<n; ++i) {
        DataType data;
        scanf("%d", &data.key); //输入元素
        bool taller;            //用于记录插入后子树是否变高
        if (InsertAVL(T, data, taller) == ERROR) {  //该元素关键字已存在
            success = false;    //记录为创建失败
            printf("Key %d already exists.\n", data.key);
        }
    }
    if (success == true) return OK; //创建成功
    return ERROR;       //否则创建失败
}

Status PreOrderTraverse(AVLTree T) {    //对二叉树的前序遍历
    if (T == NULL) return ERROR;           //子树为空返回上一级递归
    printf("%d ",T->data.key);          //输出该节点的关键字
    PreOrderTraverse(T->lchild);        //遍历左子树
    PreOrderTraverse(T->rchild);        //遍历右子树
    return OK;
}

Status InOrderTraverse(AVLTree T) {     //对二叉树的中序遍历
    if (T == NULL) return ERROR;           //子树为空返回上一级递归
    InOrderTraverse(T->lchild);         //遍历左子树
    printf("%d ",T->data.key);          //输出该节点的关键字
    InOrderTraverse(T->rchild);         //遍历右子树
    return OK;
}

Status PostOrderTraverse(AVLTree T) {    //对二叉树的后序遍历
    if (T == NULL) return ERROR;           //子树为空返回上一级递归
    PostOrderTraverse(T->lchild);        //遍历左子树
    PostOrderTraverse(T->rchild);        //遍历右子树
    printf("%d ",T->data.key);          //输出该节点的关键字
    return OK;
}

Status InitStack(SqStack &S) {          //初始化栈
    S.base = new SElemType[MAXSTACKSIZE];
    if (S.base == NULL) return ERROR;
    S.top = S.base;                     //初始化栈为空
    S.stacksize = MAXSTACKSIZE;         //初始化栈储存空间大小
    return OK;
}

Status StackPush(SqStack &S, SElemType e) {     //在栈S中插入元素e为新的栈顶元素
    if (S.top - S.base == S.stacksize) return ERROR;    //若栈满则插入失败
    *S.top++ = e;
    return OK;
}

Status StackPop(SqStack &S, SElemType &e) {     //若栈不空，则删除S的栈顶元素返回其值e
    if (S.top == S.base) return ERROR;          //栈空则无法删除
    e = *(--S.top);
    return OK;
}

Status StackEmpty(SqStack S) {      //判断栈是否为空
    if (S.top == S.base) return TRUE;       //栈空返回TRUE
    return FALSE;                           //栈非空返回FALSE
}

Status PreOrderTraverse_Nonr(AVLTree T) {       //对二叉树的前序遍历（非递归）
    if (T == NULL) return ERROR;        //二叉树为空则不遍历
    SqStack S;
    InitStack(S);           //初始化栈
    StackPush(S, T);        //头节点入栈
    while (StackEmpty(S) == FALSE) {
        AVLTree p;
        StackPop(S, p);     //弹出栈顶
        printf("%d ",p->data.key);      //输出该节点的关键字
        if (p->rchild != NULL) StackPush(S, p->rchild);        //右孩子先入栈，后处理
        if (p->lchild != NULL) StackPush(S, p->lchild);        //左孩子后入栈，先处理 
    }
    printf("\n");
    return OK;
}

Status InOrderTraverse_Nonr(AVLTree T) {        //对二叉树的中序遍历（非递归）
    if (T == NULL) return ERROR;        //二叉树为空则不遍历
    SqStack S;
    InitStack(S);           //初始化栈
    AVLTree p = T;
    while (p != NULL || StackEmpty(S) == FALSE) {   //若子树还未遍历完
        while (p != NULL) {     //将左子树所有结点压入栈中
            StackPush(S, p);
            p = p->lchild;
        }
        StackPop(S, p);         //取栈顶元素
        printf("%d ", p->data.key); //输出该节点关键字
        p = p->rchild;          //遍历右子树
    }
    printf("\n");
    return OK;
}

Status PostOrderTraverse_Nonr(AVLTree T) {      //对二叉树的中序遍历（非递归）
    if (T == NULL) return ERROR;        //二叉树为空则不遍历
    SqStack S1, S2;
    InitStack(S1);          //初始化栈S1
    InitStack(S2);          //初始化栈S2
    StackPush(S1, T);       //头节点入栈,
    while (StackEmpty(S1) == FALSE) {
        AVLTree p;
        StackPop(S1, p);    //弹出S1栈顶
        StackPush(S2, p);   //压入S2，且按照根->右孩子节点->左孩子节点的顺序压入
        if (p->lchild != NULL) StackPush(S1, p->lchild);    //先将左孩子压入S1，则左孩子后弹出，S2后压入左孩子
        if (p->rchild != NULL) StackPush(S1, p->rchild);    //后将右孩子压入S1，则右孩子先弹出，S2先压入右孩子
    }
    while (StackEmpty(S2) == FALSE){    //从S2栈顶至栈顶即为后序遍历顺序
        AVLTree p;
        StackPop(S2, p);                //取S2栈顶元素
        printf("%d ", p->data.key);     //输出关键字
    }
    printf("\n");
    return OK;
}

Status LevelOrderTraverse(AVLTree T) {      //对二叉树的层次遍历
    if (T == NULL) return ERROR;        //二叉树为空
    SqQueue Q;
    InitQueue(Q);       //初始化循环队列
    EnQueue(Q, T);      //将根节点压入队列
    while (QueueEmpty(Q) == FALSE) {    //队列非空，说明还未遍历完
        AVLTree p;
        DeQueue(Q, p);  //取队头元素
        printf("%d ", p->data.key);     //输出关键字
        if (p->lchild != NULL) EnQueue(Q, p->lchild);   //左子树不为空则压入队列
        if (p->rchild != NULL) EnQueue(Q, p->rchild);   //右子树不为空则压入队列
    }
    printf("\n");
    return OK;
}

Status InitQueue(SqQueue &Q) {      //初始化队列
    Q.elem = new QEelemType[MAXQUEUESIZE];
    if (Q.elem == NULL) return ERROR;
    Q.rear = Q.front = 0;
    Q.queuesize = MAXQUEUESIZE;
    return OK;
}

Status EnQueue(SqQueue &Q, QEelemType e) {  //将新元素压入队列中
    if ((Q.rear + 1) % Q.queuesize == Q.front) return ERROR;    //队列已满
    Q.elem[Q.rear] = e;
    Q.rear = (Q.rear + 1) % Q.queuesize;    //队尾后移一位
    return OK;
}

Status DeQueue(SqQueue &Q, QEelemType &e) { //队列头元素出队
    if (Q.rear == Q.front) return ERROR;    //队列为空
    e = Q.elem[Q.front];                    //保存出队元素
    Q.front = (Q.front + 1) % Q.queuesize;  //出队后对头后移一位
    return OK;
}

Status QueueEmpty(SqQueue Q) {      //判断队列是否为空
    if (Q.rear == Q.front) return TRUE;     //为空则返回TRUE
    return FALSE;                           //否则返回FALSE
}

Status FindTree(AVLTree T, DataType elem) {
    if (T == NULL) return FALSE;                    //子树为空表示未找到
    if (T->data.key == elem.key) return TRUE;       //当前结点的关键字与待查元素一致，表示找到该元素
    if (elem.key < T->data.key) return FindTree(T->lchild, elem);   //待查元素关键字较小则查找左子树
    return FindTree(T->rchild, elem);                               //待查元素关键字较大则查找右子树
}

Status SwapTree(AVLTree &T) {       //交换各结点的左右子树 
    if (T == NULL) return ERROR;    //子树为空，返回ERROR
    SwapTNode(T);           //交换该节点的左右两子树
    T->bf = -(T->bf);       //交换左右子树后平衡因子取相反数
    SwapTree(T->lchild);    //递归交换左子树
    SwapTree(T->rchild);    //递归交换右子树
    return OK;
}

Status SwapTNode(AVLTree &T) {      //交换该节点左右两子树
    AVLTree temp = T->lchild;
    T->lchild = T->rchild;
    T->rchild = temp;
    return OK;
}

int GetTreeDepth(AVLTree T) {       //获取二叉树的深度
    if (T == NULL) return 0;        //若该子树为空则深度为0
    return MAX(GetTreeDepth(T->lchild), GetTreeDepth(T->rchild)) + 1;   //该子树的深度为左右孩子深度最大值+1
}

int GetLeafCount(AVLTree T) {       //获取二叉树叶子个数
    if (T == NULL) return 0;        //结点为空则叶子个数为0
    if (T->lchild == NULL && T->rchild == NULL) return 1;       //若该节点为叶子则返回叶子个数1
    return GetLeafCount(T->lchild) + GetLeafCount(T->rchild);   //递归返回叶子个数，子树叶子个数为左右子树相加
}