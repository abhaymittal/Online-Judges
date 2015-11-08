// PROBLEM CODE: CANDY3

#include<iostream>

using namespace std;

int main() {
  int nTest,N;
  long long result,temp;

  cin>>nTest;
  for(int test=1;test<=nTest;test++) {
    cin>>N;
    result=0;

    for(int i=0;i<N;i++) {
      cin>>temp;
      result=(result+(temp%N))%N;
    }

    if(!result)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }

  return 0;
}
