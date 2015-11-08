#include<cstdio>
#define MAX 1000007

int main() {
  int nTest;
  unsigned long long res,N;

  scanf("%d",&nTest);
  for(int i=0;i<nTest;i++) {
    scanf("%llu",&N);
    res=0;
    res=(3*N+1);
    res=(res*N);
    res=(res/2)%MAX;
    printf("%llu\n",res);
  }
  return 0;
}
