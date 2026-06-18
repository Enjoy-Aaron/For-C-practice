#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calculateDays(int D, const vector<int>& galaxies) {
    int current = 0;  // 当前位置
    int days = 0;
    int n = galaxies.size();
    
    while (current < galaxies.back()) {
        auto it = upper_bound(galaxies.begin(), galaxies.end(), current + D);
        int farthest = it - galaxies.begin() - 1;
        current = galaxies[farthest];
        days++;
    }
    return days;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> galaxies(N);
    for (int i = 0; i < N; ++i) {
        cin >> galaxies[i];
    }
    
    int left = galaxies[0];
    for (int i = 1; i < N; ++i) {
        left = max(left, galaxies[i] - galaxies[i-1]);
    }
    int right = galaxies.back();
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        int requiredDays = calculateDays(mid, galaxies);
        
        if (requiredDays <= K) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    cout << left << endl;
    return 0;
}