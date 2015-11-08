#include<iostream>
#include<deque>

using namespace std;

void multiply(deque<int>& dq,int n) {

  int carry=0,prod=0,place=1;
  int num,temp;
  int ndigits=0;

  for(deque<int>::reverse_iterator itr=dq.rbegin();itr!=dq.rend();itr++) {
    prod=0;
    place=1;
    ndigits=0;
    num=*itr;
    //cout<<"NUM= "<<num<<endl;
    while(num!=0) {
      temp=num%10;
      //cout<<"Carry = "<<carry<<endl;
      //cout<<"Temp= "<<temp<<endl;
      num=num/10;
      //cout<<"num/10 = "<<num<<endl;
      ndigits++;
      temp=temp*n;
      prod+=((temp+carry)%10)*place;
      carry=(temp+carry)/10;
      place*=10;
      //cout<<"Product "<<prod<<endl;
    }

    //cout<<"After basic product ndigits = "<<ndigits<<endl;
    while((ndigits!=8)&&(carry!=0)) {
      prod+=(carry%10)*place;
      carry=carry/10;
      place*=10;
      ndigits++;
    }

    *itr=prod;
    //cout<<"PROD "<<*itr<<endl;
    //cout<<"CARRY "<<carry<<endl;

  }

  if(carry!=0){
    dq.push_front(carry);
  }

  for(deque<int>::iterator itr=dq.begin();itr!=dq.end();itr++) {
    cout<<*itr;
  }
  cout<<endl;
  
}

int main() {
  deque<int> dq;
  int num;
  cin>>num;

  dq.push_back(num);
  cin>>num;

  dq.push_back(num);

  int num2;
  cin>>num2;

  multiply(dq,num2);
  return 0;
}
