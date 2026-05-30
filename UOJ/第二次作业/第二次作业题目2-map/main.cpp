#include <iostream>
#include <map>
using namespace std;

void traverse(map<string,int> m)
{
    printf("Traverse:\n");
    for (auto it : m) {
        cout << it.first << ':' << it.second << endl;
    }
    cout << endl;
    return;
}
void traverse_greater(map<string,int> m)
{
    printf("Reverse:\n");
    for (auto it : m) {
        cout << it.first << ':' << it.second << endl;
    }
    cout << endl;
    return;
}

int main()
{
    map<string, int> wrds;
    int n,num;
    string name;
    printf("in:\n");
    cin >> n;
    while (n--) {
        cin >> name >> num;
        wrds[name] = num;
    }
    traverse(wrds);
    traverse_greater(wrds);

    printf("erase:\n");
    printf("in: ");cin >> name;
    wrds.erase(name);
    traverse(wrds);

    printf("find:\n");
    printf("in: ");cin>>name;
    auto it = wrds.find(name);
    if (it == wrds.end()) printf("NotFound!\n");
    else printf("Found!\n");
    printf("in: ");cin >> name;
    if (!wrds.count(name)) printf("NotFound!\n");
    else printf("Found!\n");

    printf("isEmpty: ");
    if (wrds.empty()) printf("Empty!\n");
    else printf("Not Empty!\n");

    printf("setSize: %d\n",wrds.size());
    wrds.clear();

    printf("After Clear:\n");
    printf("isEmpty: ");
    if (wrds.empty()) printf("Empty!\n");
    else printf("Not Empty!\n");
    printf("setSize: %d\n",wrds.size());
    return 0;
}
