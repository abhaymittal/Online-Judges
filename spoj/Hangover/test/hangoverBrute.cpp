#include<iostream>

using namespace std;

int main() {
  int sm=382;
  int partsm;
  int n;
  while(sm<520) {
    partsm=0;
    n=0;
    cout<<"g | ";
    for(int i=2;partsm<sm;i++) {
      partsm+=(1.0L/i)*100;
      n++;
    }
    cout<<sm<<" | "<<n<<endl;
    sm+=1;
  }
  return 0;
}
