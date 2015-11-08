#include<cstdio>

using namespace std;

double findHarm(int n){
  double res=0;
  for(int i=1;i<=n;i++) {
    res+=((double)1)/i;
  }
  return res;
}

int main() {
  int nTest,n;
  double res;
  scanf("%d",&nTest);
  for(int t=1;t<=nTest;t++) {
    scanf("%d",&n);
    res=n*findHarm(n);
    printf("%.2f\n",res);
  }
  return 0;
}
