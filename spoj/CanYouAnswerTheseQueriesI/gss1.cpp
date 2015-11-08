#include<cstdio>
#define MAXN 50000
int main() {
  int N,M,xi,yi;
  int max, maxHere;
  short A[MAXN];
  scanf("%d",&N);
  for(int i=0;i<N;i++) {
    scanf("%hd",&A[i]);
  }

  scanf("%d",&M);

  for(int i=0;i<M;i++) {
    scanf("%d%d",&xi,&yi);
    xi--;yi--;

    if(xi<0)
      xi=0;
    if(yi>(N-1))
      yi=N-1;
    max=A[xi];maxHere=0;
    for(int index=xi;index<=yi;index++) {
      maxHere+=A[index];
      if(maxHere>max)
	max=maxHere;
      if(maxHere<0)
	maxHere=0;
    }

    printf("%d\n",max);
  }
  return 0;
}
