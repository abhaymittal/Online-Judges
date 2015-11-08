//PROBLEM CODE: MAXLN

#include<iostream>
#include<iomanip>

using namespace std;

int main() {
  int nTest,r;

  cin>>nTest;

  for(int test=1;test<=nTest;test++) {
    cin>>r;

    cout<<fixed<<setprecision(2)<<"Case "<<test<<": "<<0.25+4*r*r<<endl;
  }
  return 0;
}
