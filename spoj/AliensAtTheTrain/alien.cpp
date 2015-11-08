#include<cstdio>
#define MAX 100000

int main() {
  int at, bt, maxStation,station, b,maxB, a[MAX];
  int startIndex=0, endIndex=-1,nTest;
  scanf("%d",&nTest);
  for(int t=1;t<=nTest;t++) {
    scanf("%d%d",&at,&bt);
    startIndex=0;
    endIndex=-1;
    station=0;
    maxStation=0;
    maxB=0;
    b=0;

    for(int i=0;i<at;i++) {
      scanf("%d",&a[i]);
      if(a[i]==bt) {
	startIndex=i+1;
	endIndex=i;
	b=0;
	station=0;
	if(maxStation<1) {
	  maxStation=1;
	  maxB=a[i];
	}
      }
      else if (b+a[i]<=bt) {
	b=b+a[i];
	station++;
	endIndex++;
      }
      else if (a[i]>bt) {
	b=0;
	station=0;
	endIndex=i;
	startIndex=i+1;
      }
      else {
	b=b+a[i];
	endIndex++;
	station++;
	for(;(startIndex<=endIndex)&&(b>bt);startIndex++) {
	  b=b-a[startIndex];
	  station--;
	}
      }

      if((station>maxStation)||((station==maxStation)&&(b<maxB))) {
	maxStation=station;
	maxB=b;
	//printf("max B = %d, ai = %d, sI = %d, eI = %d\n",maxB,a[i],startIndex,endIndex);
      }
    }
    printf("%d %d\n",maxB,maxStation);
  }
  
  return 0;
}
