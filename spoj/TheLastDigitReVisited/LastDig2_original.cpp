#include<iostream>
#include<string>
#include<vector>
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
int main() {
  int nTest,a;
  int multiple;
  string aStr, b;
  vector< vector<int> > multiplicity(10);
  cin>>nTest;
  for(int i=0;i<nTest;i++) {
    cin>>aStr;
    cin>>b;
    a=aStr.at(aStr.length()-1)-48;
    if(b.at(0)==0) {
      cout<<1<<endl;
      continue;
    }
    if(multiplicity[a].size()==0) {
      multiple=a;
      do {
	multiplicity[a].push_back(multiple);
	multiple=(multiple*a)%10;
      }
      while(multiple!=a);
    }
    int pow=mod(b,multiplicity[a].size());
    pow--;
    if(pow==-1)
      pow=multiplicity[a].size()-1;
    cout<<multiplicity[a][pow]<<endl;
  }
  return 0;
}
