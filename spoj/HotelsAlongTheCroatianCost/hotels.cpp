#include<cstdio>
#define MAX 300000
int main() {
  unsigned int N,M,sum=0,maxSum=0,a[MAX];
  int startIndex=0,endIndex=-1;
  bool flag =false;
  scanf("%d%d",&N,&M);
  for(int i=0;i<N;i++) {
    scanf("%d",&a[i]);
    if(!flag) {
      if (a[i]==M)  {
	sum=0;
	maxSum=M;
	flag=true;
	startIndex=i+1;
	endIndex=i;
      }
      else if(sum+a[i]<=M) {
	sum+=a[i];
	endIndex++;
      }
      else if (a[i]>M) {
	sum=0;
	startIndex=i+1;
	endIndex=i;
      }
      else {
	sum=sum+a[i];
	endIndex++;
	for(int j=startIndex;(j<=endIndex)&&(sum>M);j++) {
	  sum=sum-a[j];
	  startIndex++;
	}
      }
      
      if(sum>maxSum)
	maxSum=sum;
    }
  }
  printf("%d\n",maxSum);
  return 0;
}
