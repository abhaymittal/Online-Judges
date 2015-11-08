/**
 * PROBLEM CODE: FASHION
 */

#include<iostream>
#include<algorithm>

using namespace std;

int main() {
  int nTest,N;
  int *male,*female; //hotness arrays for males and females
  int sum;

  cin>>nTest;

  for(int test=1;test<=nTest;test++) {
    cin>>N;
    
    sum=0;
    male=new int[N];
    female=new int[N];

    for(int i=0;i<N;i++) {
      cin>>male[i];
    }
    for(int i=0;i<N;i++) {
      cin>>female[i];
    }

    sort(male,male+N);
    sort(female,female+N);

    for(int i=0;i<N;i++){
      sum+=male[i]*female[i];
    }

    cout<<sum<<endl;
    delete[] male;
    delete[] female;
  }
  return 0;
}
