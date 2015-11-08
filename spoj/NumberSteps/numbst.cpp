/**
 * Can't write description, contains image
 * PROBLEM CODE: NSTEPS
 */

#include<iostream>

using namespace std;

int main() {
  int nTest,x,y;
  int val,offset;

  cin>>nTest;

  for(int test=1;test<=nTest;test++) {
    cin>>x;
    cin>>y;

    if((x==y)||(y==(x-2))) {
      offset=(x==y)?0:2;
      val=(y/2)*4+(y%2)+offset;
      cout<<val<<endl;
    }
    else
      cout<<"No Number"<<endl;
  }
  return 0;
}
