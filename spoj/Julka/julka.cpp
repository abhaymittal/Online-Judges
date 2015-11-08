//PROBLEM CODE: JULKA

#include<iostream>
#include<string>

using namespace std;

string add(string num1, string num2);
string sub(string num1,string num2);
string halve(string num);

int main() {
  string sum, diff;
  
  for(int test=1;test<=10;test++) {
    cin>>sum; // read total apples
    cin>>diff;// extra apples of klaudia

    /* Let apples of klaudia =x , and natalia = y.
       x+y=sum;
       x-y=diff;
       x=(sum+diff)/2; and y=(sum-diff)/2;
    */

    cout<<halve(add(sum,diff))<<endl;//Klaudia's apples
    cout<<halve(sub(sum,diff))<<endl;//Natalia's apples
  }

  return 0;
}


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

  while((diff.length()!=1)&&(diff.at(0)=='0')) {
    diff.erase(0,1);
  }
  return diff; 
}




string halve(string num) {
  int rem=0;
  int n;
  int dividend;
  string quot="";
  for(int index=0;index<num.length();index++) {
    n=num.at(index)-48;
    dividend=rem*10+n;
    rem=dividend%2;
    quot=quot+string(1,(dividend/2)+48);
  }

  while((quot.length()!=1)&&(quot.at(0)=='0'))
    quot.erase(0,1);
  return quot;
}

			 
