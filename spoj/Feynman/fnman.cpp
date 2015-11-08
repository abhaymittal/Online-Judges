/**
 * Find the number of different squares in a grid of NxN squares
 * PROBLEM CODE: SAMER08F
 */


#include<iostream>
using namespace std;

int main() {
  int N;

  cin>>N;
  while(N!=0) {
    cout<<N*(N+1)*(2*N+1)/6<<endl;
    cin>>N;
  }
  return 0;
}
