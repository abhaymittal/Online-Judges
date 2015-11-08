#include<cstdio>

int calcNum(char in[]) {
  int n,z;
  n=(in[0]-48)*10+(in[1]-48);
  z=in[3]-48;
  for(int i=0;i<z;i++) {
    n=n*10;
  }
  return n;
}

int main() {
  int n,pwr;
  char in[5];
  scanf("%s",in);
  n=calcNum(in);
  while(n!=0) {
    pwr=1;
    while(pwr<=n) {
      pwr=pwr<<1;
    }
    pwr=pwr>>1;
    printf("%d\n",2*(n-pwr)+1);
    scanf("%s",in);
    n=calcNum(in);
  }
  return 0;
}
