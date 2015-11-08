#include<cstdio>
#include<algorithm>
#include<climits>
using namespace std;

int main() {
  int N,M,K,temp, cost[102][102], minCost;
  for(int i=1;i<102;i++) {
    for(int j=0;j<102;j++) {
      cost[i][j]=INT_MAX;
    }
  }
  scanf("%d%d",&N,&M);
  for(int i=1;i<=N;i++) {
    for(int j=1;j<=M;j++) {
      scanf("%d",&temp);
      cost[i][j]=min(cost[i-1][j-1],min(cost[i-1][j],cost[i-1][j+1]))+temp;
    }
  }

  minCost=INT_MAX;
  for(int i=1;i<=M;i++) {
    minCost=min(minCost,cost[N][i]);
  }
  printf("%d\n",minCost);
  return 0;
}
