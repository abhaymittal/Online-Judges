#include<iostream>

using namespace std;

int main() {
  int nTest,start;
  cin>>nTest;

  for(int t=1;t<=nTest;t++) {
    cin>>start;
    cin>>start; //ignore number of pieces

    if(start==0)
      cout<<"Airborne wins."<<endl;
    else
      cout<<"Pagfloyd wins."<<endl;
  }
  return 0;
}
