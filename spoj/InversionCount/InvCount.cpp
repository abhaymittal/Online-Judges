//PROBLEM CODE: INVCOUNT

#include<iostream>
#define MAXN 200000

using namespace std;

int main() {
  int nTest,num;
  long long invCount;
  int *A;
  int *aux, *temp;
  int a[MAXN],b[MAXN];
  int auxIndex;

  cin>>nTest;

  for(int test=1;test<=nTest;test++) {
    invCount=0;
    cin>>num;
    A=a;
    aux=b;



    for(int i=0;i<num;i++) {
      cin>>A[i];
    }

    
    for(int group=1;group<=num;group*=2) {
      auxIndex=0;
      for(int i=0;i+group<num;i+=2*group) {
	int lIndex=i;
	int rIndex=i+group;


	for(;(lIndex<i+group)&&(rIndex<num)&&(rIndex<(i+2*group));) {
	  if(A[lIndex]<=A[rIndex]) {
	    aux[auxIndex]=A[lIndex];
	    lIndex++;
	  }
	  else {
	    aux[auxIndex]=A[rIndex];
	    invCount+=(i+group-lIndex);
	    rIndex++;
	  }
	  auxIndex++;
	}
	while(lIndex<(i+group)) {
	  aux[auxIndex]=A[lIndex];
	  lIndex++;
	  auxIndex++;
	}
	while((rIndex<num)&&(rIndex<(i+2*group))) {
	  aux[auxIndex]=A[rIndex];
	  rIndex++;
	  auxIndex++;
	}

      }
      for(int j=auxIndex;j<num;j++) {
	aux[j]=A[j];
      }
      temp=A;
      A=aux;
      aux=temp;
    }
    
    cout<<invCount<<endl;
  }
  return 0;
}
