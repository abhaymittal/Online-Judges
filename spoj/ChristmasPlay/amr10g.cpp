#include<cstdio>
#include<climits>
#include<algorithm>
#define MAXN 20004

int main() {
  int N,K,hgt[MAXN];
  int nTest,minDif=INT_MAX;
  scanf("%d",&nTest);

  for(int i=0;i<nTest;i++) {
    minDif=INT_MAX;
    scanf("%d%d",&N,&K);
    for(int k=0;k<N;k++) {
      scanf("%d",&hgt[k]);
    }
    std::sort(hgt,hgt+N);

    for(int j=0;j<=N-K;j++) {
      minDif=(minDif<=(hgt[j+K-1]-hgt[j]))?minDif:hgt[j+K-1]-hgt[j];
    }
    printf("%d\n",minDif);
  }
  return 0;
}
