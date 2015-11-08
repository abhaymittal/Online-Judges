#include<algorithm>
#include<cstring>
#include<cstdio>
#define MAXN 1000001

using namespace std;

int main() {
  int nTest,N,P,count,temp;
  bool sieve[MAXN];
  scanf("%d",&nTest);
  for(int t=1;t<=nTest;t++) {
    scanf("%d",&N);
    memset(sieve,0,sizeof(sieve[0])*MAXN);
    P=N;
    count=0;
    while(P>1) {
      count++;
      if(P%2==0) {
	temp=P;
	sieve[2]=1;
	temp=temp/2;
	//	printf("sieve[2]=1\n");
	while(temp%2==0&&temp>1) {
	  sieve[temp]=1;
	  temp/=2;
	}
	sieve[temp]=1;	
	//	printf("sieve[%d]=1\n",temp);
      }
      else
	temp=P;
      for(int i=3;i*i<=temp;i+=2)
	if(temp%i==0) {
	  sieve[i]=1;
	  //	  printf("sieve[%d]=1\n",i);
	  sieve[temp/i]=1;
	  //	  printf("sieve[%d]=1\n",temp/i);
	}

      for(P=P-1;sieve[P]&&P>1;P--);
    }
    printf("%d\n",count);
  }
  return 0;
}
