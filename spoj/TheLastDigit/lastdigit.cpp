// PROBLEM CODE: LASTDIG

//The technique applied is Fast modular exponentiation. Learnt from khanacademy. express the power in terms of binary and compute it based on powers of two
#include<iostream>

using namespace std;

int main() {
  int nTest,a,b;
  int prod=0,result;
  bool bitmap[32]={false};
  cin>>nTest;
  for(int test=0;test<nTest;test++) {
    cin>>a>>b;
    a=a%10;
    for(int i=0;i<32;i++) {
      bitmap[i]=(b&(1<<i))?true:false;
    }
    prod=a;
    result=1;
    if(bitmap[0])
      result=a;

    for(int i=1;i<32;i++) {
      prod=(prod*prod)%10;
      if(bitmap[i])
	result=(result*prod)%10;
    }

    cout<<result<<endl;

  }
  return 0;
}
