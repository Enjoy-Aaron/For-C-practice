#include <iostream>
#include <set>
using namespace std;

void traverse(set<int> nums)
{
    printf("Traverse: ");
    for (auto it : nums) {
        printf("%d ",it);
    }
    printf("\n");
    return;
}

void traverse_greater(set<int,greater<int> > nums)
{
    for (auto it : nums) {
        printf("%d ",it);
    }
    printf("\n");
    return;
}


int main()
{
    int tmp,n;
    set<int> nums;
    set<int,greater<int> >nums_greater;
    printf("in: \n");
    cin >> n;
    while (n--) {
        cin >> tmp;
        nums.insert(tmp);
        nums_greater.insert(tmp);
    }
    traverse(nums);
    printf("reverse: ");traverse_greater(nums_greater);

    printf("erase:\n");
    printf("in: ");cin >> tmp;
    nums.erase(tmp);
    traverse(nums);

    printf("find:\n");
    printf("in: ");cin>>tmp;
    auto it = nums.find(tmp);
    if (it == nums.end()) printf("NotFound!\n");
    else printf("Found!\n");
    printf("in: ");cin >> tmp;
    if (!nums.count(tmp)) printf("NotFound!\n");
    else printf("Found!\n");

    printf("isEmpty: ");
    if (nums.empty()) printf("Empty!\n");
    else printf("Not Empty!\n");

    printf("setSize: %d\n",nums.size());
    nums.clear();
    return 0;
}
