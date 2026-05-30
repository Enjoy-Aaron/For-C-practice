#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    int n,tmp;
    printf("in: \n");
    cin >> n;
    while (n--) {
        cin >> tmp;
        s.push(tmp);
    }

    tmp = s.top();
    s.pop();
    printf("pop: %d\n",tmp);

    printf("isEmpty: ");
    if (s.empty()) printf("Empty!\n");
    else printf("Not Empty!\n");
    printf("Size: %d\n",s.size());

    //clear
    while (!s.empty()) {
        s.pop();
    }

    printf("After Clear:\n");
    printf("isEmpty: ");
    if (s.empty()) printf("Empty!\n");
    else printf("Not Empty!\n");
    printf("Size: %d\n",s.size());
    return 0;
}
