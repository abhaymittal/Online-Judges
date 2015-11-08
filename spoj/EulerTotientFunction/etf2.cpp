#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

int main() {
  int nTest,n,temp;
  bool sieve[1000000];
  int primes[1000000],nprimes;
  double tot;
  scanf("%d",&nTest);
  for(int test=1;test<=nTest;test++) {
    scanf("%d",&n);
    if((n==1)||(n==2)) {
      printf("1\n");
      continue;
    }
    nprimes=0;
    memset(sieve,false,(n-1)*sizeof(bool));
    for(int i=0;i<n-1;i++) {
      if(sieve[i])
	continue;
      for(int j=i;j<n-1;j=j+i+2) {
	sieve[j]=true;
      }
      if(n%(i+2)==0)
	primes[nprimes++]=i+2;
    }
    tot=n;
    if(nprimes==0)
      tot=n-1;
    for(int j=0;j<nprimes;j++) {
      tot=tot*(1.0-1.0/(primes[j]));
    }
    printf("%d\n",static_cast<int>(tot));
  }
  return 0;
}
