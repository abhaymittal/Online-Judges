#include<cstdio>

int gcd(int a,int b) {
  if(!b)
    return a;
  else
    return gcd(b,a%b);
}


int main() {
  int nTest,a,b,hcf,res,i;
  scanf("%d",&nTest);
  for(int t=1;t<=nTest;t++) {
    scanf("%d%d",&a,&b);
    hcf=gcd(a,b);
    res=0;
    for(i=1;i*i<hcf;i++) {
      if(hcf%i==0) {
	res+=2;
      }
    }
    if(i*i==hcf)
      res++;
    printf("%d\n",res);
  }
  return 0;
}
