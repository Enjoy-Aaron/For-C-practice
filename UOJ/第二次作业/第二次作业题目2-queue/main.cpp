#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> Q;
    int n,tmp;
    printf("in: \n");
    cin >> n;
    while (n--) {
        cin >> tmp;
        Q.push(tmp);
    }

    tmp = Q.front();
    Q.pop();
    printf("pop: %d\n",tmp);

    printf("isEmpty: ");
    if (Q.empty()) printf("Empty!\n");
    else printf("Not Empty!\n");
    printf("Size: %d\n",Q.size());

    //clear
    while (!Q.empty()) {
        Q.pop();
    }

    printf("After Clear:\n");
    printf("isEmpty: ");
    if (Q.empty()) printf("Empty!\n");
    else printf("Not Empty!\n");
    printf("Size: %d\n",Q.size());
    return 0;
}
