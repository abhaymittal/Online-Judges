#include<string>
#include<cstring>
#include<cstdio>
#define MAXN 1001
using namespace std;
int dp[MAXN][MAXN];
char ar[MAXN][MAXN];
void solveLCS(string a, string b, int K) {
  memset(dp,0,sizeof(dp[0][0])*MAXN*MAXN);
  memset(ar,-1,sizeof(ar[0][0])*MAXN*MAXN);
  string temp1,temp2;
  int len1=a.length(),len2=b.length();
  for(int i=1;i<=len1-K+1;i++) {
    for(int j=1;j<=len2-K+1;j++) {
      if(ar[i-1][j-1]=='0') {
	if(a[i+K-2]==b[j+K-2]) {
	  dp[i][j]=dp[i-1][j-1]+1;
	  ar[i][j]='0';
	}
	else if (dp[i][j-1]>dp[i-1][j]) {
	dp[i][j]=dp[i][j-1];
	ar[i][j]='-';
      }
      else {
	dp[i][j]=dp[i-1][j];
	ar[i][j]='+';
      }
      }
      if(a.compare(i-1,K,b,j-1,K)==0) {
	if(ar[i-1][j-1]=='0')
	  dp[i][j]=dp[i-1][j-1]+1;
	else
	  dp[i][j]=dp[i-1][j-1]+K;
	ar[i][j]='0';
      }
      else if (dp[i][j-1]>dp[i-1][j]) {
	dp[i][j]=dp[i][j-1];
	ar[i][j]='-';
      }
      else {
	dp[i][j]=dp[i-1][j];
	ar[i][j]='+';
      }
    } 
  }
  printf("%d\n",dp[len1-K+1][len2-K+1]);
  for(int i=0;i<=a.length();i++) {
    for(int j=0;j<=b.length();j++) {
      printf("%d ",dp[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int K;
  string a,b;
  char str[MAXN];

  scanf("%d",&K);
  while(K!=0) {
    scanf("%s",str);
    a=str;
    scanf("%s",str);
    b=str;
    if((a.length()<K)||(b.length()<K))
      printf("0\n");
    else
      solveLCS(a,b,K);
    scanf("%d",&K);
  }
  return 0;
}
