#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int mod(string dividendStr,int divisor) {
  int rem=0;
  int n;
  int dividend;
  string quot="";
  for(int index=0;index<dividendStr.length();index++) {
    n=dividendStr.at(index)-48;
    dividend=rem*10+n;
    rem=dividend%divisor;
  }
  return rem;
}

int gcdInt(int a, int b) {
  if(b==0)
    return a;
  else
    return gcdInt(b,a%b);
}

string gcdS(string a, int b) {
  if(b==0)
    return a;
  int strMod=mod(a,b);
  int res=gcdInt(b,strMod);
  stringstream ss;
  ss<<res;
  return ss.str();
}


int main() {
  int a;
  string b;
  int nTest;
  cin>>nTest;
  for(int i=1;i<=nTest;i++) {
    cin>>a;
    cin>>b;
    cout<<gcdS(b,a)<<endl;
  }
  return 0;
}
