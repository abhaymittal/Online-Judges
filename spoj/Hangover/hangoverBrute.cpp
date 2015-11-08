#include<iostream>

using namespace std;

int main() {
  double sum;
  double partialSum=0;
  int n;
  cin>>sum;
  while(sum!=0.00L) {
    partialSum=0;
    n=0;
    for(int i=2;partialSum<sum;i++) {
      partialSum+=(1.0L/i);
      n++;
    }
    cout<<n<<" card(s)"<<endl;
    cin>>sum;
  }
  return 0;
}
