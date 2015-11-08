#include<cstdio>
int main() {
  int nTest,N,K,T,F;
  int x;
  scanf("%d",&nTest);
  for(int t=1;t<=nTest;t++) {
    scanf("%d%d%d%d",&N,&K,&T,&F);
    printf("%d\n",N+(K*(F-N))/(K-1));
  }
  return 0;
}
