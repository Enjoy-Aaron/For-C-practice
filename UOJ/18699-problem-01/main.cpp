#include <iostream>
using namespace std;
int n;
int dat[1001];
int temp[1001];
void merge_sort(int* A, int x, int y, int* T) {
  if(y-x > 1){
    int m = (x + y) / 2;
    merge_sort(A, x, m, T);
    merge_sort(A, m, y, T);
    int p = x, q = m, i = x;
    while(p < m || q < y) {
      if(q >= y || (p < m && A[p] <= A[q]))
        T[i++] = A[p++];
      else
        T[i++] = A[q++];
    }
    for(i = x; i < y; i++) A[i] = T[i];
  }
}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>dat[i];
    merge_sort(dat, 0, n, temp);
    for(int i=0; i<n; i++)
        cout<<dat[i]<<endl;

}