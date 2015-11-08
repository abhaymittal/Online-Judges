#include<iostream>
#include<string>

using namespace std;

string sub(string num1, string num2) {
  //Performs num1-num2
  string diff="";
  int n1,n2;
  int borrow=0;

  int len=num2.length();
  int index1=num1.length()-1,index2=num2.length()-1;
  for(int i=0;i<len;i++,index1--,index2--) {
    n1=num1.at(index1)-48;
    n2=num2.at(index2)-48;
    
    n1=n1-borrow;
    borrow=0;
    if(n1<n2) {
      n1=10+n1;
      borrow=1;
    }

    diff=string(1,n1-n2+48)+diff;
  }
  while(index1>-1) {
    n1=num1.at(index1)-48;

    n1=n1-borrow;
    borrow=0;
    if(n1<0) {
      n1=n1+10;
      borrow=1;
    }
      diff=string(1,n1+48)+diff;
    index1--;
  }

  //Remove zeroes from the beginning

  while(diff.at(0)=='0') {
    diff.erase(0,1);
  }
  return diff;
  
  
}


int main() {
  string num1,num2;
  cin>>num1;
  cin>>num2;
  cout<<sub(num1,num2)<<endl;
}
