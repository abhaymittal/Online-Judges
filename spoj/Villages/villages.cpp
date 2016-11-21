#include<cstdio>
#include<bitset>
#include<vector>
#define MAXVLG 1000
using namespace std;

int main()  {
  vector< bitset<MAXVLG> > adjMat(MAXVLG);
  bitset<MAXVLG> andmask;
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++) {
    int v1,v2;
    scanf("%d %d",&v1,&v2);
    adjMat[v1-1].set(v2-1);
  }
  long long nWays=0;
  for(int i=0;i<N;i++) {
    int count =0;
    for(int j=i+1;j<N;j++) {
      andmask=adjMat[i]&adjMat[j];
      count =andmask.count();
      nWays+=((count*(count-1))/2);
    }
  }
  printf("%lld\n",nWays);
  // for(int i=0;i<N;i++) {
  //   for(int j=0;j<N;j++) {
  //     int a=adjMat[i][j];
  //     printf("%d ",a);
  //   }
  //   printf("\n");
  // }
}
