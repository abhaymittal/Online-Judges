#include<cstdio>
#define MAX 1002


using namespace std;

int main() {
  int nTest, sMax,temp,standing,required,num;
  char str[MAX];

  scanf("%d",&nTest);

  for(int t=1;t<=nTest;t++) {
    standing=0;
    required=0;
    scanf("%d",&sMax);
    scanf("%s",str);
    for(int i=0;i<=sMax;i++) {
      num=str[i]-48;
      if(num>0) {
	if(standing>=i) {
	  standing+=num;
	}
	else {
	  required+=(i-standing);
	  standing+=(i-standing);
	  standing+=num;
	}
      }
    }
    printf("Case #%d: %d\n",t,required);
  }
  return 0;
}
