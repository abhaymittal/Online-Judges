#include<iostream>
#include<string>

using namespace std;

string add(string num1, string num2) {
  string sum="";
  int n1,n2;
  int carry=0;
  int len=(num1.length()>num2.length())?num2.length():num1.length();
  int index1=num1.length()-1,index2=num2.length()-1;
  for(int i=0;i<len;i++,index1--,index2--) {
    n1=num1.at(index1)-48;
    n2=num2.at(index2)-48;
    sum=string(1,((n1+n2+carry)%10)+48)+sum;
    carry=(n1+n2+carry)/10;
  }
  while(index1>-1) {
    n1=num1.at(index1)-48;
    sum=string(1,((n1+carry)%10)+48)+sum;
    carry=(n1+carry)/10;
    index1--;
  }

  while(index2>-1) {
    n2=num2.at(index2)-48;
    sum=string(1,((n2+carry)%10)+48)+sum;
    carry=(n2+carry)/10;
    index2--;
  }

  while(carry!=0) {

    sum=string(1,(carry%10)+48)+sum;
    carry/=10;
  }

  return sum;
}

bool checkPallindrome(string num) {
  for(int i=0;i<num.length()/2;i++) {
    if(num.at(i)!=num.at(num.length()-1-i))
      return false;
  }
  return true;
}


int main() {
  int nTest;
  string num;
  string one="1";
  cin>>nTest;
  for(int test=1;test<=nTest;test++) {
    cin>>num;
    num=add(num,one);
    while(!checkPallindrome(num)) {
      num=add(num,one);
    }

    cout<<num<<endl;

  }
  return 0;
}


