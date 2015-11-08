#include<cstdio>
#include<bitset>
#define MAXN 1000000
using namespace std;

int main() {
  int nTest,n,p;
  int phi[MAXN+1], primes[MAXN/10],primesIndex=0;
  bitset <MAXN+1> mark;
  phi[1]=1;
  for(int i=2;i<=MAXN;i++) {
    if(!mark[i]) {
      mark[i]=1;
      phi[i]=i-1;
      primes[primesIndex++]=i;
    }

    for(int j=0;(j<primesIndex)&&(primes[j]*i<=MAXN);j++){
      mark[primes[j]*i]=1;
      if(i%primes[j]==0) {
	phi[i*primes[j]]=phi[i]*primes[j];
      }
      else
	phi[i*primes[j]]=phi[i]*(primes[j]-1);
    }
  }

  scanf("%d",&nTest);

  for(int test=1;test<=nTest;test++) {
    scanf("%d",&n);
    printf("%d\n",phi[n]);
  }
  return 0;
}
