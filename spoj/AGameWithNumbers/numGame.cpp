#include<iostream>

using namespace std;

int main() {
  int num;
  cin>>num;
  if((num%10)==0)
    cout<<2;
  else
    cout<<1<<endl<<num%10;
  return 0;
}
