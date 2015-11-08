#include<cstdio>
using namespace std;
int main() {
  long long int third,thirdLast,sum,diff,initial,num;
  int nTest;
  scanf("%d",&nTest);
  for(int test=1;test<=nTest;test++) {
    scanf("%lld",&third);
    scanf("%lld",&thirdLast);
    scanf("%lld",&sum);
    
    num=(2*sum)/(third+thirdLast);
    if(num!=5)
      diff=(thirdLast-third)/(num-5);
    else
      diff=0;
    initial=third-(2*diff);
    sum=initial;
    printf("%lld\n",num);
    printf("%lld",sum);
    for(int i=1;i<num;i++) {
      sum=sum+diff;
      printf(" %lld",sum);
    }
    printf("\n");
  }
  return 0;
}
