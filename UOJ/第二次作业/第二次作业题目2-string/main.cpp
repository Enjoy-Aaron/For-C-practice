#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string s1, s2;

int main()
{

    printf("compare:\n");
    printf("in: ");cin >> s1 >> s2;
    char op;
    if (s1<s2) op = '<';
    else if (s1 == s2) op = '=';
    else op = '>';
    printf("out:");cout << s1 << op << s2 << endl;

    printf("insert:\n");
    printf("in: ");cin >> s1 >> s2;
    string s3 = s1 + s2;
    printf("out:");cout << s3 << endl;
    s1.insert(s1.end(), s2.begin(), s2.end());
    printf("out:");cout << s1 << endl;
    int n,m;
    printf("in: ");cin >> n >> m;
    s3.insert(s3.begin()+n,m,'|'); //在第n个位置前插入m个'|' （下标从0开始）
    printf("in: ");cout << s3 << endl;

    printf("erase:\n");
    printf("in: ");cin >> n;
    s3.erase(s3.begin()+n); //删除第n个位置上的元素
    printf("out:");cout << s3 << endl;
    s3.erase(s3.begin()+n, s3.end());   //删除从第n个到末尾的元素
    printf("out:");cout << s3 << endl;
    return 0;
}
