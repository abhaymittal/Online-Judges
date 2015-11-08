#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAX 1000

using namespace std;

int bsearch(char a[], char key, int l, int r) {
  int mid=(l+r)/2;
  while(l<=r) {
    mid=(l+r)/2;
    if(key<a[mid]) {
      r=mid-1;
    }
    else if(key>a[mid]) {
      l=mid+1;
    }
    else {
      while((a[mid]==key)&&(mid>=l))
	mid--;
      return mid+1;

    }
  }
  return -1;
}

int main() {
  char a[MAX+1],b[MAX+1],x[MAX+1];
  int aLen,bLen,xLen,temp,l;
  while(scanf("%s",a)!=EOF) {
    scanf("%s",b);
    xLen=0;
    x[xLen]='\0';
    aLen=strlen(a);
    bLen=strlen(b);
    sort(a,a+aLen);
    sort(b,b+bLen);
    if(aLen>bLen) {
      temp=-1;l=0;
      for(int i=0;i<bLen;i++) {
	temp=bsearch(a,b[i],l,aLen-1);
	if(temp!=-1) {
	  x[xLen++]=b[i];
	  l=temp+1;
	}
      }
    }
    else {
      temp=-1;l=0;
      for(int i=0;i<aLen;i++) {
	temp=bsearch(b,a[i],l,bLen-1);
	if(temp!=-1) {
	  x[xLen++]=a[i];
	  l=temp+1;
	}
      }
    }
    x[xLen]='\0';
    printf("%s\n",x);
  }
  return 0;
}
