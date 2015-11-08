#include<cstdio>
#include<vector>

using namespace std;

int main() {
  int nTest,n,temp;
  vector<bool>sieve;
  vector<int>primes;
  double tot;
  scanf("%d",&nTest);
  for(int test=1;test<=nTest;test++) {
    scanf("%d",&n);
    if((n==1)||(n==2)) {
      printf("1\n");
      continue;
    }
    primes.clear();
    tot=1;
    sieve.assign(n-2,false);
    for(int i=0;i<sieve.size();i++) {
      if(sieve[i])
	continue;
      for(int j=i;j<sieve.size();j=j+i+2) {
	sieve[j]=true;
      }
      if(n%(i+2)==0)
	primes.push_back(i+2);
    }
    tot=n;
    if(primes.empty())
      tot=n-1;
    for(vector<int>::iterator itr=primes.begin();itr!=primes.end();itr++) {
      tot=tot*(1.0-1.0/(*itr));
    }
    printf("%d\n",static_cast<int>(tot));
  }
  return 0;
}
