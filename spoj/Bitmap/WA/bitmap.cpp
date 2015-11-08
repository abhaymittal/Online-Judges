#include<cstdio>
#include<climits>
#include<algorithm>

using namespace std;

int abs(int x) {
  if(x<0)
    return -1*x;
  return x;
}

int calcDist(int sx, int sy, int n, int m, int dist[182][182],bool flag[182][182]) {
  if((sx<0)||(sx>=n))
    return INT_MAX;
  else if ((sy<0)||(sy>=m))
    return INT_MAX;
  if(dist[sx][sy]!=-1)
    return dist[sx][sy];
  if(flag[sx][sy])
    return INT_MAX;
  flag[sx][sy]=true;
  dist[sx][sy]=1+min(calcDist(sx-1,sy,n,m,dist,flag),min(calcDist(sx+1,sy,n,m,dist,flag),min(calcDist(sx,sy-1,n,m,dist,flag),calcDist(sx,sy+1,n,m,dist,flag))));
  return dist[sx][sy];
}

int main() {
  int n,m,nTest;
  bool bitmap[182][182],flag[182][182];
  int dist[182][182];
  char ch;

  scanf("%d",&nTest);

  for(int i=0;i<nTest;i++) {
    scanf("%d%d",&n,&m);
    getchar();

    for(int j=0;j<n;j++) {
      for(int k=0;k<m;k++) {
	scanf("%c",&ch);
	ch=ch-48;
	if(!ch) {
	  bitmap[j][k]=false;
	  dist[j][k]=-1;
	}
	else {
 	  bitmap[j][k]=true;
	  dist[j][k]=0;
	}
	flag[j][k]=false;
      }
      getchar();
    }
    for(int j=0;j<n;j++) {
      for(int k=0;k<m;k++) {
	if(dist[j][k]==-1)
	  calcDist(j,k,n,m,dist,flag);
      }
    }

    for(int j=0;j<n;j++) {
      for(int k=0;k<m;k++) {
	printf("%d",dist[j][k]);
	if(k!=(m-1))
	  printf(" ");
      }
      printf("\n");
    }
  }
  return 0;
}
