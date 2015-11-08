#include<cstdio>

int main() {
  unsigned long long k;
  unsigned long long num;
  int cands[4]={192,442,692,942};
  int nTest;
  scanf("%d",&nTest);

  for(int test=1;test<=nTest;test++) {
    scanf("%lld",&k);
    k--; // my index starts from 0
    printf("%lld\n",(k/4)*1000+cands[k%4]);
  }
  

  return 0;
}
