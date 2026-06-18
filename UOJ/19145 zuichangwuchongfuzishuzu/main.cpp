#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    unordered_map<int, int> last_pos;
    int left = 0;
    int max_len = 0;
    
    for (int right = 0; right < n; ++right) {
        int num = arr[right];
        auto it = last_pos.find(num);
        if (it != last_pos.end() && it->second >= left) {
            left = it->second + 1;
        }
        last_pos[num] = right;
        max_len = max(max_len, right - left + 1);
    }
    
    cout << max_len << endl;
    return 0;
}