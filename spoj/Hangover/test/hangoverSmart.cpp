#include<iostream>
#include<cmath>

using namespace std;

int main() {
  double sum=0;
  double gamma=0.577215664901532860L;
  
  while(sum<5.20L) {
    sum+=1;
    cout<<sum-1<<" | "<<static_cast<int>(exp(sum-gamma)-0.5L)<<endl;
    sum-=0.9;
  }
  return 0;
}
