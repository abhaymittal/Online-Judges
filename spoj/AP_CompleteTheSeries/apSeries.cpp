#include<iostream>
using namespace std;
int main() {
  long long third,thirdLast,sum,diff,initial,num;
  int nTest;
  cin>>nTest;
  for(int test=1;test<=nTest;test++) {
    cin>>third>>thirdLast>>sum;

    num=(2*sum)/(third+thirdLast);
    if(num!=5)
      diff=(thirdLast-third)/(num-5);
    else
      diff=0;
    initial=third-(2*diff);
    int sum=initial;
    cout<<num<<endl;
    cout<<sum;
    for(int i=1;i<num;i++) {
      sum=sum+diff;
      cout<<" "<<sum;
    }
    cout<<endl;
  }
  return 0;
}
