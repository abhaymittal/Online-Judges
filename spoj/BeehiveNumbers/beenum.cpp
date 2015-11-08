//PROBLEM CODE: BEENUM
#include<iostream>

using namespace std;

int main() {
  int N,sum;
  cin>>N;
  while(N!=-1) {
    N--;
    if((N%6)!=0)
      cout<<"N"<<endl;
    else {
      sum=6;
      while(N>0) {
	N=N-sum;
	sum+=6;
      }
      if(N==0)
	cout<<"Y"<<endl;
      else
	cout<<"N"<<endl;
    }
    
    cin>>N;
  }
}
