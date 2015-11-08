//PROBLEM CODE:INVCOUNT

#include<iostream>
#include<algorithm>

using namespace std;

struct elem{
  int num;
  int index;
};

  bool compare(elem i, elem j) {
    return (i.num<j.num);
  }
  
int main() {
  int nTest,num,invCount;
  elem *A;
  cin>>nTest;

  for(int test=1;test<=nTest;test++) {
    invCount=0;
    cin>>num;
    A=new elem[num];

    for(int i=0;i<num;i++) {
      cin>>A[i].num;
      A[i].index=i;
    }
    sort(A,A+num,compare);

    for(int i=0;i<num-1;i++) {
      for(int j=i+1;j<num;j++) {
	if(A[j].num==A[i].num)
	  i=j;
	else {
	  if(A[i].index>A[j].index)
	    invCount++;
	}
      }
    }

    
    cout<<invCount<<endl;
    delete[] A;
  }
  return 0;
}
