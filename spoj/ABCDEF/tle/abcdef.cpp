#include<cstdio>
#include<set>
#define MAX 100
#define MAXC 1000000

using namespace std;

int main() {
  int S[MAX],N,lhs[MAXC];
  int lIndex;
  multiset<int> rhs;
  long long count=0;
  scanf("%d",&N);
  for(int i=0;i<N;i++) {
    scanf("%d",&S[i]);
  }

  //Calculate LHS a*b+c
  lIndex=0;
  for(int a=0;a<N;a++) {
    for(int b=0;b<N;b++) {
      for(int c=0;c<N;c++) {
	lhs[lIndex++]=S[a]*S[b]+S[c];
	if(S[a]!=0) {
	  rhs.insert(S[a]*(S[b]+S[c]));
	}
      }
    }
  }

  for(int i=0;i<lIndex;i++) {
    count=count+rhs.count(lhs[i]);
  }
  printf("%lld\n",count);
  return 0;
}
