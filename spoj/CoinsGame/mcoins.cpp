#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 1000000

using namespace std;

int ans[MAXN+1];
// 0 denotes a winning position and 1 denotes a losing position

int result(int N) {
  if(N==0)
    return 1;
  if(N<0)
    return -1;
  return ans[N];
}


void preCompute(int K,int L) {
  ans[1]=0;
  int winr;
  for(int i=2;i<=MAXN;i++) {
    if(result(i-1)==0)
      ans[i]=1;
    else
      ans[i]=0;
    if(ans[i]==1&&result(i-K)==1) {
      ans[i]=0;
    }
    if(ans[i]==1&&result(i-L)==1) {
      ans[i]=0;
    }
  }
}
int main() {
  int K,L,m,N;
  scanf("%d%d%d",&K,&L,&m);
  preCompute(K,L);
  for(int t=1;t<=m;t++) {
    scanf("%d",&N);
    if(ans[N]==0)
      printf("A");
    else
      printf("B");
  }
  return 0;
}
