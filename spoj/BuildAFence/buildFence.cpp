//PROBLEM CODE: FENCE1

#include<iostream>
#include<iomanip>
using namespace std;

int main() {
  int length;
  double radius, area;
  double pi=3.14159265359;
  cin>>length;
  while(length!=0) {
    radius=length/pi;
    area=pi*radius*radius/2;
    cout<<fixed<<setprecision(2)<<area<<endl;
    cin>>length;
  }
}
