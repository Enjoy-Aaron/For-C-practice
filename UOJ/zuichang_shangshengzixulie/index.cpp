#include <bits/stdc++.h>
#define MAX(a,b) (a>b? a:b)
using namespace std;

vector<int> GetDp1(vector<int> &arr)
{
    int len = arr.size();
    vector<int> dp(len, 1);
    for (int i=1;i<len;++i) {
        for (int j=0; j<i; ++j) {
            if (arr[j] < arr[i]) {
                dp[i] = MAX(dp[i], dp[j]+1);
            }
        }
    }
    return dp;
}

vector<int> GetDp2(vector<int> &arr)
{
    int len = arr.size();
    vector<int> dp(len, 0), ends(len, 0);
    dp[0] = 1;
    int l=0, r=0, m=0;
    int right=0;
    for (int i=1;i<len;++i) {
        l = 0; r = right;
        while (l <= r) {
            m = (l + r) >> 1;
            if (arr[i] > arr[m]) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
    right = MAX(right, l);
    ends[l] = arr[i];
    dp[i] = l + 1;
    }
    return dp;
}

vector<int> GenerateLIS(vector<int> &arr, vector<int> &dp)
{
    int len = 0, index = 0;
    for (int i=0; i<dp.size(); ++i) {
        if (dp[i] > len) {
            len = dp[i];
            index = i;
        }
    }
    vector<int> LIS(len, 0);
    LIS[--len] = arr[index];
    for (int i=index; i>=0; i--) {
        if (arr[i] < arr[index] && dp[i] == dp[index] - 1) {
            LIS[--len] = arr[i];
            index = i;
        }
    }
    return LIS;
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> arr(n,0), dp(n,0);
    for (int i=0;i<n;++i) scanf("%d",&arr[i]);
    dp = GetDp1(arr);
    for (int i=0;i<n;++i) printf("%d ",dp[i]);
    printf("\n");
    vector<int> LIS = GenerateLIS(arr,dp);
    for (int i=0;i<LIS.size(); ++i) printf("%d ",LIS[i]);
    return 0;
}