#include<cstdio>

int main() {
  int n,m,D,nTest,pow;
  scanf("%d",&nTest);
  for(int t=0;t<nTest;t++) {
    scanf("%d%d%d",&n,&m,&D);
    for(int h=0;h<n;h++) {
      scanf("%d",&pow);
      if(pow<=D)
	continue;
      if(pow%D!=0) {
	m-=(pow/D);
      }
      else
	m-=(pow/D-1);
    }
    if(m<=0)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
