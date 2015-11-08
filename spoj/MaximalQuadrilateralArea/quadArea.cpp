#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main() {
  int nTest;
  double s,a,b,c,d;
  cin>>nTest;
  for(int i=0;i<nTest;i++) {
    cin>>a>>b>>c>>d;
    s=(a+b+c+d)/2;
    cout<<fixed<<setprecision(2)<<sqrt((s-a)*(s-b)*(s-c)*(s-d))<<endl;
  }
  return 0;
}
