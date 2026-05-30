#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int,vector<int>,greater<int> > Qg;
    priority_queue<int,vector<int>,less<int> > Ql;
    int n,tmp;
    printf("in: \n");
    cin >> n;
    while (n--) {
        cin >> tmp;
        Qg.push(tmp);
        Ql.push(tmp);
    }

    //traverse&pop
    printf("traverse:\n");
    while (!Qg.empty()) {
        tmp = Qg.top();Qg.pop();
        cout << tmp << ' ';
    }
    cout << endl;
    printf("reverse:\n");
    while (!Ql.empty()) {
        tmp = Ql.top();Ql.pop();
        cout << tmp << ' ';
    }
    cout << endl;
    return 0;
}
