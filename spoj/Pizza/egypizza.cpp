#include<iostream>
#include<string>

using namespace std;

int main() {
  int remainder[3]={0},required[3]={0};
  int N,pizzaCount=1,num,den,index;
  string slice;
  cin>>N;

  for(int i=0;i<N;i++) {
    cin>>slice;
    num=slice.at(0)-48;
    den=slice.at(2)-48;

    if(num==1) {
      if(den==4)
	index=0;
      else
	index=1;
    }
    else
      index=2;
    required[index]++;
  }

  pizzaCount+=required[2];
  remainder[0]+=required[2];
  required[2]=0;
  pizzaCount+=(required[1]/2);
  
  if((required[1]%2)==1){
    pizzaCount++;
    remainder[0]+=2;
  }
  required[1]=0;
  if(required[0]>remainder[0]) {
    required[0]=required[0]-remainder[0];
    remainder[0]=0;
    pizzaCount+=(required[0]/4);
    if((required[0]%4)!=0) {
      pizzaCount++;
      required[0]=0;
    }
  }
  cout<<pizzaCount<<endl;
  return 0;
}

