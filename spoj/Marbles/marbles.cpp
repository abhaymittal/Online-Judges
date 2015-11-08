#include<iostream>
using namespace std;
long long C(int n,int r) {
  double result=1;
  if(n==r)
    return 1;
  if(r>n/2)
    r=n-r;
  for(int i=0;i<r;i++) {
    result=(result*(n-i))/(i+1);
  }
  return static_cast<long long>(result);
}

int main() {
int nTest,n,k;
cin>>nTest;
for(int i=0;i<nTest;i++) {
cin>>n>>k;
cout<<C(n-1,k-1)<<endl;
}
return 0;
}
