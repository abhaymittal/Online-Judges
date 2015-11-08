#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

long long coins[4];

int prevIndex(int i,int c) {
  i-=c;
  if(i<0)
    i+=4;
  return i;
}

void incrementIndex(int& i) {
  i++;
  if(i>3)
    i=0;
}

void decrementIndex(int& i) {
  i--;
  if(i<0)
    i=3;
}


int main() {
  int nTest,n,cIndex=0;
  long long num;
  scanf("%d",&nTest);
  for(int t=1;t<=nTest;t++) {
    scanf("%d",&n);
    memset(coins,0,4*sizeof(long long));
    for(int i=0;i<n;i++) {
      scanf("%lld",&num);
      coins[cIndex]=max(coins[prevIndex(cIndex,1)],max(num+coins[prevIndex(cIndex,2)],num+coins[prevIndex(cIndex,3)]));
      incrementIndex(cIndex);
    }
    decrementIndex(cIndex);
    printf("Case %d: %lld\n",t,coins[cIndex]);
  }
  return 0;
}
