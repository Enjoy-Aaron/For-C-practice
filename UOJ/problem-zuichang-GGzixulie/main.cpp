#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#define MAX(a, b) (a>b ? a:b)
#define MIN(a, b) (a<b ? a:b)
using namespace std;
typedef long long ll;
const int MAXN = 1e5+10;
char s1[MAXN], s2[MAXN];
int dp[MAXN][MAXN];
set<string> res;

void ToFindLCS(int i, int j, string path) {
    if (i == 0 || j == 0) {
        reverse(path.begin(), path.end());
        res.insert(path);
        return;
    }

    if (s1[i-1] == s2[j-1]) {
        ToFindLCS(i-1, j-1, path + s1[i-1]);
    }
    else {
        if (dp[i][j] == dp[i-1][j]) {
            ToFindLCS(i-1, j, path);
        }
        if (dp[i][j] == dp[i][j-1]) {
            ToFindLCS(i, j-1, path);
        }
    }
    return;
}

int main() {
    scanf("%s%s", s1, s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for (int i=0; i<len1; ++i) {
        for (int j=0; j<len2; ++j) {
            if (s1[i] == s2[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = MAX(dp[i][j+1], dp[i+1][j]);
        }
    }
    // /+++test+++
    // for (int i=1;i<=len1; ++i) {
    //     for (int j=1; j<=len2; ++j) {
    //         printf("%d ",dp[i][j]);
    //     }
    //     printf("\n");
    // }
    // //----------
    int max_len = dp[len1][len2];
    printf("%d\n",max_len);
    ToFindLCS(len1, len2, "");
    for (set<string>::iterator it = res.begin(); it != res.end(); it++) {
        for (int i=0; i<max_len; ++i) {
            printf("%c ",(*it)[i]);
        }
        printf("\n");
    }
    return 0;
}