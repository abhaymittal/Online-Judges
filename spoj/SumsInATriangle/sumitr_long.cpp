#include<cstdio>
#include<algorithm>
#define MAX 100

using namespace std;

int main() {
  int a[MAX][MAX],nTest,n,temp,maxe;

  scanf("%d",&nTest);

  for(int i=0;i<nTest;i++) {
    
    scanf("%d",&n);

    for(int j=0;j<n;j++) {
      if(j==0) {
	scanf("%d",&a[0][0]);
	continue;
      }
      for(int k=0;k<j+1;k++) {
	scanf("%d",&temp);
	if(k==0) {
	  a[j][k]=a[j-1][k]+temp;
	}
	else if (k==j) {
	  a[j][k]=a[j-1][k-1]+temp;
	}
	else {
	  a[j][k]=max(a[j-1][k],a[j-1][k-1])+temp;
	}
      }
    }

    maxe=0;
    for(int i=0;i<n;i++) {
      if(maxe<a[n-1][i])
	maxe=a[n-1][i];
    }
    printf("%d\n",maxe);
  }
  return 0;
}
