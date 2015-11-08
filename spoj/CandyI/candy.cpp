/**
 * Distribute candies evenly
 * PROBLEM CODE: CANDY
 */

#include<iostream>

using namespace std;
int main() {
  int N,sum,share;
  int moves;
  int *candy;

  cin>>N;
  while(N!=-1) {
    sum=0;
    moves=0;
    candy=new int[N];
    for(int i=0;i<N;i++) {
      cin>>candy[i];
      sum+=candy[i];
    }

    if((sum%N)!=0)
      cout<<-1<<endl;
    else {
      share=sum/N;

      for(int i=0;i<N;i++) {
	if(candy[i]<share)
	  moves+=(share-candy[i]);
      }

      cout<<moves<<endl;
    }

    delete[] candy;
    cin>>N;
  }
  return 0;
}
