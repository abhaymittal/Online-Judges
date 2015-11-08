#include<cstdio>

using namespace std;

int main() {
  int nTest,n,p,temp;
  int primes[1000001];
  double tot;
  for(long long i=2;i<1000001;i++) {
    if(!primes[i]) {
      primes[i]=i;
      for(long long j=i*i;j<=1000000;j+=i) {
	primes[j]=i;
      }
    }
  }
  
  scanf("%d",&nTest);
  for(int test=0;test<nTest;test++) {
    scanf("%d",&n);
    if(n==1) {
      printf("1\n");
      continue;
    }
    if(primes[n]==n) {
      tot=n-1;
    }
    else {
      tot=n;
      while(n>1) {
	p=primes[n];
	for(;n%p==0;n/=p);
	tot=tot*(1-1.0/p);
      }
    }
    printf("%d\n",static_cast<int>(tot));
  }
  return 0;
}
