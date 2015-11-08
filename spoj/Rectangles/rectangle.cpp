// PROBLEM CODE: AE00

#include<iostream>

using namespace std;

int main(int argc,char **argv) {
  int N;
  cin>>N;

  int count=0;
  if(N!=0)
    count=1; // There will alaways be a rectangle of area 1x1 unless N =0

  for(int area=2;area<=N;area++) {
    if((area%2)==0) {
      //cout<<"---- AREA = "<<area<<" ----"<<endl;
      //cout<<"1x"<<area<<endl;
      count++; //For 1xarea rectangle
      for(int l=2;l<area/2;l+=2) {
	int b=area/l;
	if(l*b!=area)
	  continue;
	if((b%2==0)&&(b<l))
	  continue;
	//cout<<l<<"x"<<b<<endl;
	count++;
      }
      
      if((area*area/4)==area) {//i.e. area/2 == 2
	count++; //For checking for 2x2 for 4 :P
	//cout<<"2x2"<<endl;
      }
    }
    else {
      //cout<<"---- AREA = "<<area<<" ----"<<endl;
      count++; //for 1xarea rectangle
      //cout<<"1x"<<area<<endl;
      for(int l=3;l<area/3;l+=2) {
	int b=area/l;
	if(l*b!=area)
	  continue;
	if(b<l)
	  continue;
	//cout<<l<<"x"<<b<<endl;	
	count++;
      }

      if((area*area/9)==area) { //i.e. area/3==3
	count++; //For checking for 3x3 for 9
	//cout<<"3x3"<<endl;
      }
	
    }

    
    
  }

  cout<<count<<endl;
  return 0;
}

