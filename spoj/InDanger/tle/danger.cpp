#include<cstdio>
#define MAX 99000000

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
  int nTest ,prevIndex, index, n, newIndex,z;
  static int a[MAX];
  char in[5];
  scanf("%s",in);
  n=calcNum(in);
  while(n!=0) {
    for(int i=0;i<n;i++)
      a[i]=i+1;
    index=2;
    newIndex=1;
    prevIndex=0;
    while(n!=1) {
      while(index<n) {
	a[newIndex++]=a[index];
	prevIndex=index;
	index=index+2;
      }
      if(prevIndex<n-1)
	index=0;
      else
	index=1;
      n=newIndex;
      newIndex=0;
    }
    printf("%d\n",a[0]);
    scanf("%s",in);
    n=calcNum(in);
  }
  return 0;
}
