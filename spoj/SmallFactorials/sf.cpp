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
    if(num==0)
      continue;
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
  //cout<<endl;
  
}

int calcNdigits(int num) {
  int ndigits=0;
  if(num==0)
    return 1;
  while(num!=0){
    ndigits++;
    num=num/10;
  }
  return ndigits;
  
}


int main() {
  int nTest,num;
  deque<int> que;
  
  cin>>nTest;
  for(int test=0;test<nTest;test++) {
    que.clear();
    cin>>num;
    que.push_back(num);

    for(int i=num-1;i>=2;i--) {
      multiply(que,i);
    }

    for(deque<int>::iterator itr=que.begin();itr!=que.end();itr++) {
      if(*itr!=0) {
	int digits=calcNdigits(*itr);
	if((digits!=8)&&(itr!=que.begin())) {
	  for(int i=0;i<(8-digits);i++)
	    cout<<0;
	}
	cout<<*itr;
      }
      else
	for(int i=0;i<8;i++)
	  cout<<0;
    }
    cout<<endl;
  }
  return 0;
}

