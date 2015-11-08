#include<iostream>
#include<cmath>
using namespace std;

int reverseNum(int x);

int main(){
  int N;
  int a,b,i;
  cin>>N;
  for(i=0;i<N;i++) {
    cin>>a;
    cin>>b;
    cout<<reverseNum(reverseNum(a)+reverseNum(b))<<endl;
  }
  return 0;
}

int reverseNum(int x) {
  int i=10,ndigits=1;
  while((x/i)!=0) {
    ndigits++;
    i*=10;
  }

  int temp=x;
  int revNum=0, place=pow(10,ndigits-1);
  while(temp!=0) {
    revNum=revNum+((temp%10)*place);
    place=place/10;
    temp=temp/10;
  }
  return revNum;
}
