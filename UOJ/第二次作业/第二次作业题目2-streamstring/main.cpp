#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    stringstream ss;
    int n1,n2,n3;
    string str1,str2;
    printf("in:\n");
    cin >> n1 >> str1 >> n2 >> str2 >> n3;
    ss << n1 << ' ' << str1 << ' ' << n2 << ' ' << str2 << ' ' << n3;
    printf("out:\n");
    printf("ss: ");cout << ss.str() << endl;
    int nn1,nn2,nn3;
    string str_t1,str_t2;
    ss >> nn1 >> str_t1 >> nn2 >> str_t2 >> nn3;
    printf("nums: ");printf("%d %d\n",nn1,nn2);
    printf("stings: ");cout << str_t1 << ' ' << str_t2 << endl;
    return 0;
}
