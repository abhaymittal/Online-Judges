// PROBLEM CODE: TRICOUNT

#include<iostream>

using namespace std;

int main() {
  int nTest,level;
  unsigned long long tricount=0;
  cin>>nTest;
  for(int test=1;test<=nTest;test++) {
    tricount=0;
    cin>>level;

    for(long long lvl=1,terms=level;lvl<=level;lvl++,terms--) {
      tricount+=(terms+(terms/2))*lvl;
    }

    cout<<tricount<<endl;
 }
  return 0;
}
