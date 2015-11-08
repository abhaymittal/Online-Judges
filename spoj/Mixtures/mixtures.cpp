#include<cstdio>
#include<utility>
#include<climits>
#define MAXN 100
using namespace std;

int main() {
  int n,temp;
  pair<int,int> mix[MAXN][MAXN];
  while(scanf("%d",&n)!=EOF) {
    for(int i=0;i<n;i++) {
      scanf("%d",&mix[i][i].first);
      mix[i][i].second=0;
    }

    for(int l=2;l<=n;l++) {
      for(int i=0;i<n-l+1;i++) {
	int j=i+l-1;
	mix[i][j].first=INT_MAX;
	mix[i][j].second=INT_MAX;
	for(int k=i;k<j;k++) {
	  temp=mix[i][k].second+mix[k+1][j].second+mix[i][k].first*mix[k+1][j].first;
	  if(temp<mix[i][j].second) {
	    mix[i][j].second=temp;
	    mix[i][j].first=(mix[i][k].first+mix[k+1][j].first)%100;
	  }
	  else if (temp==mix[i][j].second) {
	    if(mix[i][j].first>(mix[i][k].first+mix[k+1][j].first)%100)
	      mix[i][j].first=(mix[i][k].first+mix[k+1][j].first)%100;
	  }
	}
	//end of k loop
      }
    }

    printf("%d\n",mix[0][n-1].second);
  }
  return 0;
}
