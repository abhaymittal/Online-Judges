#include<cstdio>
#include<algorithm>
#include<cstring>
#include<climits>
#define MAXN 100001

using namespace std;

int main() {
  int N,in[MAXN][3],dist[MAXN][3];
  int t=1;
  scanf("%d",&N);
  while(N!=0) {
    memset(dist,SCHAR_MAX,sizeof(dist[0][0])*MAXN*3);
    memset(in,0,sizeof(in[0][0])*MAXN*3);
    for(int j=0;j<3;j++) {
      scanf("%d",&in[0][j]);
    }
    dist[0][0]=200000000;
    dist[0][1]=in[0][1];
    dist[0][2]=in[0][1]+in[0][2];
    for(int i=1;i<N;i++) {
      for(int j=0;j<3;j++) {
	scanf("%d",&in[i][j]);
      }
      for(int j=0;j<3;j++) {
	for(int k=j-1;k<=j+1;k++) {
	  if((k<0)||(k>=3))
	    continue;
	  dist[i][k]=min(dist[i][k],dist[i-1][j]+in[i][k]);
	}
      }
      for(int k=1;k<3;k++) {
	dist[i][k]=min(dist[i][k],dist[i][k-1]+in[i][k]);
      }
    }
    /*    printf("\n");
    for(int i=0;i<N;i++) {
      for(int j=0;j<3;j++) {
	printf("%d ",dist[i][j]);
      }
      printf("\n");
      }*/
    printf("%d. %d\n",t,dist[N-1][1]);
    t++;
    scanf("%d",&N);
  }
  return 0;
}
