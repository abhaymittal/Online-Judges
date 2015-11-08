// PROBLEM CODE: TRICOUNT

#include<iostream>

using namespace std;

int main() {
  int nTest;
  unsigned long long level;
  cin>>nTest;
  for(int test=1;test<=nTest;test++) {
    cin>>level;

    cout<<level*(level+2)*(2*level+1)/8<<endl;

 }
  return 0;
}
