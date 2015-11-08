//PROBLEM CODE: EASYPROB

#include<iostream>
using namespace std;

void print_exp(int num);

int pow[15]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};

int main() {
  int input[]={137,1315,73,136,255,1384,16385};

  for(int i=0;i<7;i++) {
    cout<<input[i]<<"=";
    print_exp(input[i]);
    if(i!=6)
      cout<<endl;
  }
  return 0;
}


void print_exp(int num) {
  
  //  cout<<endl<<"NUM = "<<num<<endl;
  if(num==0)
    cout<<"0";
  else {
    int powr;
    for(powr=0;(powr<=14)&&(pow[powr]<=num);powr++);
    powr--;
    
    if(powr==1)
      cout<<"2";
    else {	
      cout<<"2(";
      print_exp(powr);
      cout<<")";
    }
    if(pow[powr]!=num) {
      cout<<"+";
      print_exp(num-pow[powr]);
    }
  }
  
}
