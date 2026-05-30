#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <string>
#define MIN(a,b) (a<b? a:b)
using namespace std;
const int MAXN = 1e6+10;
int n,m;
string temp,squ[MAXN];
map<string,int> cntw;
set<string> tar,target,current_tar;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;++i) {
        cin >> temp;
        tar.insert(temp);
    }
    scanf("%d",&m);
    for (int i=0;i<m;++i) {
        cin >> squ[i];
        if (tar.count(squ[i]) != 0) {
            target.insert(squ[i]);
        }
    }
    int i=0;
    int ans = MAXN;
    for (int j=0;j<m;++j) {
        while (target.count(squ[j])==0 && j<m) j++;
        while (target.count(squ[i])==0 && i<m) i++;
        if (i==m || j==m) break;
        cntw[squ[j]]++;
        current_tar.insert(squ[j]);
        if (current_tar.size() == target.size()) {
            while (target.count(squ[i])!=0 && cntw[squ[i]] > 0) {
                cntw[squ[i]]--;
                ans=MIN(ans,j-i+1);
                i++;
                if (cntw[squ[i-1]] == 0) {
                    current_tar.erase(squ[i-1]);
                    break;
                }
            }
        }
    }
    printf("%d\n%d\n",target.size(),ans);
    return 0;
}
