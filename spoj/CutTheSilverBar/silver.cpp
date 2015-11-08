#include<cstdio>

int main() {
  int n,pwr,count;
  scanf("%d",&n);
  while(n!=0) {
    pwr=1;
    count=0;
    while(pwr<=n) {
      pwr=(pwr<<1);
      count++;
    }
    count--;
    printf("%d\n",count);
    scanf("%d",&n);
  }
  return 0;
}
