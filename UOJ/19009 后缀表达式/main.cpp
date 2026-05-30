#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
char oper[4] = {'+','-','*','/'};
bool IN(char ch)
{
    bool flag = 0;
    for (int i=0;i<4;++i) {
        if (ch == oper[i]) {flag = 1; break;}
    }
    return flag;
}

int operate(int a, int b, char op)
{
    switch (op) {
    case '+': return a+b;
    case '-': return a-b;
    case '*': return a*b;
    case '/': return a/b;
    }
}

int main()
{
    stack<int> nums;
    char ch;
    ch = getchar();
    while (ch != '@') {
        while (ch == ' ') ch = getchar();
        if (!IN(ch)) {
            nums.push(ch-'0');
        }
        else {
            int temp_num_b = nums.top(); nums.pop();
            int temp_num_a = nums.top(); nums.pop();
            int num_c = operate(temp_num_a,temp_num_b,ch);
            nums.push(num_c);
        }
        ch = getchar();
    }
    printf("%d\n",nums.top());
    return 0;
}
