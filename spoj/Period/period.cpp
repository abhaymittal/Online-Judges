#include<cstdio>
#include<cstring>
#define MAXN 1000000

void generateLPS(char *str, int lps[], int length) {
  lps[0]=0;
  int len=0;
  for(int i=1;i<length;) {
    if(str[i]==str[len]) {
      len++;
      lps[i]=len;
      i++;
    }
    else {
      if(len!=0) {
	len=lps[len-1];
      }
      else {
	lps[i]=0;
	i++;
      }
    }
  }
}


int main() {
  int nTest,N;
  char str[MAXN+1];
  int lps[MAXN];
  int period=0;
  scanf("%d",&nTest);
  for(int t=1;t<=nTest;t++) {
    scanf("%d",&N);
    scanf("%s",str);
    generateLPS(str,lps,N);
    printf("Test case #%d\n",t);
    /*for(int i=0;i<N;i++) {
      printf("%d -> %d\n",i,lps[i]);
    }*/
    for(int i=1;i<N;i++) {
      period=i+1-lps[i];
      if(((i+1)%period==0)&&((i+1)/period>1))
	printf("%d %d\n",i+1,(i+1)/period);
    }
    printf("\n");
  }
  return 0;
}
