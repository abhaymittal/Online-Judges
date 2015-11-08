//PROBLEM CODE: MAXLN
#include<iostream>
#include<iomanip>
using namespace std;
int main() {
  float r;
  int nTest;
  cin>>nTest;
  for(int i=1;i<=nTest;i++) {
    cin>>r;
    cout<<fixed<<setprecision(2)<<"Case "<<i<<": "<<4*r*r+0.25<<endl;
  }
}
