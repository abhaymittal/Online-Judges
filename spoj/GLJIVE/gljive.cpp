#include<cstdio>
#include<algorithm>
using namespace std;
int abs(int x) {
  return (x>=0)?x:-x;
}

int main() {
  int sum,prevSum,temp;
  sum=0;
  prevSum=0;
  bool flag = false;
  for(int i=0;i<10;i++) {
    scanf("%d",&temp);
    if(!flag) {
    prevSum=sum;
    sum=sum+temp;
    if(sum>=100)
      flag=true;
    }
  }
  int s1=abs(sum-100);
  int s2=abs(100-prevSum);
  if(s1>s2) {
    printf("%d\n",prevSum);
  }
  else
    printf("%d\n",sum);
  return 0;
}
