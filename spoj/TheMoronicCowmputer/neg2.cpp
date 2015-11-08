#include<cstdio>


void printNegaBinary(int n) {
  int mod;
  char bin[34];
  int index=33;
  while(n!=0) {
    mod=n%-2;
    n=n/-2;
    if(mod<0) {
      mod+=2;
      n++;
    }
    bin[index--]=mod;
  }
  for(int i=index+1;i<34;i++) {
    printf("%d",bin[i]);
  }
  printf("\n");
}
int main() {
  int num;
  scanf("%d",&num);
  if(num!=0)
    printNegaBinary(num);
  else
    printf("0\n");
  return 0;
}
