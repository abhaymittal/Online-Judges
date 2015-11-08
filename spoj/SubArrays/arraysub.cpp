#include<cstdio>
#include<set>
#include<vector>
#define MAX 100000
using namespace std;

int main() {
  int n,k,temp;
  multiset<int> window;
  vector<int> a;
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%d",&temp);
    a.push_back(temp);
  }
  scanf("%d",&k);

  for(int i=0;i<k;i++) {
    window.insert(a[i]);
  }
  printf("%d",*window.rbegin());

  for(int i=1;i<=n-k;i++) {
    window.erase(window.find(a[i-1]));
    window.insert(a[i+k-1]);
    printf(" %d",*window.rbegin());
  }
  printf("\n");
  return 0;
}
