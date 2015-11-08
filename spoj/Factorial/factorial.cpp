#include<iostream>
using namespace std;
int main() {
  long long fact;
  int num,temp;
  int testCase,i;
  cin>>testCase;

  for(i=0;i<testCase;i++) {
    fact=0;
    cin>>num;

    for(int i=5;i<=num;i*=5) {
      fact=fact+num/i;
    }
    
    cout<<fact<<endl;
  }

  return 0;

}
