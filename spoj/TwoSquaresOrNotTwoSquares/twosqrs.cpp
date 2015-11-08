#include<cstdio>
#include<cmath>

bool checkSumSquare(long long n) {
  long long fs=0;
  long long ss=(long long)sqrt(n);
  long long temp;
  while(fs<=ss) {
    temp=fs*fs+ss*ss;
    if(temp<n)
      fs++;
    else if (temp==n)
      return true;
    else
      ss--;
  }
  return false;
}

int main() {
  int nTest;
  long long n;
  scanf("%d",&nTest);
  for(int i=0;i<nTest;i++) {
    scanf("%lld",&n);
    if(checkSumSquare(n))
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
