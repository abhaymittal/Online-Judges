#include<cstdio>

int main() {
  int nTest,N,M;
  scanf("%d",&nTest);
  for(int t=1;t<=nTest;t++) {
    scanf("%d%d",&N,&M);
    if(N<=M)
      if(N%2==0)
	printf("L\n");
      else
	printf("R\n");
    else
      if(M%2==0)
	printf("U\n");
      else
	printf("D\n");
  }
  return 0;
}
