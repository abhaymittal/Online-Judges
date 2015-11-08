#include<iostream>
#include<set>

using namespace std;

int breakNumber(int num) ;

int main() {
  int N, breakNum=0,nSteps;
  set<int> breakSet;

  cin>>N;
  for( nSteps=0;breakNum!=1;nSteps++) {
    breakNum=breakNumber(N);
    if(breakSet.find(breakNum)!=breakSet.end()) {
      cout<<"-1"<<endl;
      return 0;
    }
    else {
      breakSet.insert(breakNum);
      N=breakNum;
    }
  }

  cout<<nSteps<<endl;
  return 0;
  
}

int breakNumber(int num) {
  int temp,brokenNum=0;
  int digit;
  temp=num;
  while(temp!=0) {
    digit=temp%10;
    temp=temp/10;
    brokenNum+=(digit*digit);
  }
  return brokenNum;
}
