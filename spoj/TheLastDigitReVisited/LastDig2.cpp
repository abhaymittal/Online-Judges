#include<iostream>
#include<string>
#include<vector>
using namespace std;
int mod(string divdStr,int divs) {
  int rem=0,n,divd;
  string quot="";
  for(int index=0;index<divdStr.length();index++) {
    n=divdStr.at(index)-48;
    divd=rem*10+n;
    rem=divd%divs;
  }
  return rem;
}
int main() {
int nTest,a,ml;
string aStr, b;
vector< vector<int> > mul(10);
cin>>nTest;
for(int i=0;i<nTest;i++) {
cin>>aStr;
cin>>b;
a=aStr.at(aStr.length()-1)-48;
if(b.at(0)=='0') {
cout<<1<<endl;
continue;
}
if(mul[a].size()==0) {
ml=a;
do {
mul[a].push_back(ml);
ml=(ml*a)%10;
}
while(ml!=a);
}
int pow=mod(b,mul[a].size());
pow--;
if(pow==-1)
pow=mul[a].size()-1;
cout<<mul[a][pow]<<endl;
}
  return 0;
}
