#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int main() {
  vector<int> A,B,C,D;
  vector<int> sumAB;
  multiset<int> sumCD;
  int n,a,b,c,d;
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%d%d%d%d",&a,&b,&c,&d);
    A.push_back(a);
    B.push_back(b);
    C.push_back(c);
    D.push_back(d);
  }

  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      sumAB.push_back(A[i]+B[j]);
      sumCD.insert(C[i]+D[j]);
    }
  }
  unsigned long long int count=0;
  for(int i=0;i<sumAB.size();i++) {
    count+=sumCD.count(-1*sumAB[i]);
  }
  printf("%llu\n",count);
  return 0;
  
}
