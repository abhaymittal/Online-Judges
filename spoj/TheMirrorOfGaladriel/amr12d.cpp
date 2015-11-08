#include<cstdio>
#include<cstring>
#define MAXLEN 10
int main() {
  char str[MAXLEN+1];
  int nTest,len;
  bool flag=true;
  scanf("%d",&nTest);
  for(int t=1;t<=nTest;t++) {
    flag=true;
    scanf("%s",str);
    len=strlen(str);
    for(int i=0;i<len/2;i++) {
      if(str[i]!=str[len-1-i]) {
	flag=false;
	break;
      }
    }
    if(!flag) {
      printf("NO\n");
    }
    else
      printf("YES\n");
  }
  return 0;
}
