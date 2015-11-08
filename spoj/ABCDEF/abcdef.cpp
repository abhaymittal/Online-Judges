#include<cstdio>
#include<algorithm>
#define MAX 100
#define MAXC 1000000

using namespace std;

int main() {
  int S[MAX],N,lhs[MAXC],rhs[MAXC];
  int lIndex,rIndex,lLen,rLen;
  long long count=0;
  scanf("%d",&N);
  for(int i=0;i<N;i++) {
    scanf("%d",&S[i]);
  }

  lIndex=0;
  rIndex=0;
  for(int a=0;a<N;a++) {
    for(int b=0;b<N;b++) {
      for(int c=0;c<N;c++) {
	lhs[lIndex++]=S[a]*S[b]+S[c];
	if(S[a]!=0) {
	  rhs[rIndex++]=S[a]*(S[b]+S[c]);
	}
      }
    }
  }
  lLen=lIndex;
  rLen=rIndex;
  sort(lhs,lhs+lLen);
  sort(rhs,rhs+rLen);
  for(lIndex=0,rIndex=0;(lIndex<lLen)&&(rIndex<rLen);) {
    if(lhs[lIndex]>rhs[rIndex]) {
      rIndex++;
    }
    else if (lhs[lIndex]<rhs[rIndex]) {
      lIndex++;
    }
    else {
      for(int j=rIndex;lhs[lIndex]==rhs[j];j++) {
	count++;
      }
      lIndex++;
    }
  }
  printf("%lld\n",count);
  return 0;
}
