#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#define MAX 10000

using namespace std;

int bsearch(int a[], int key, int l, int r) {
  int mid=(l+r)/2;
  while(l<=r) {
    mid=(l+r)/2;
    if(key<a[mid]) {
      r=mid-1;
    }
    else if(key>a[mid]) {
      l=mid+1;
    }
    else
      return mid;
  }
  return -1;
}

int main() {
  int n1,n2,a[MAX],b[MAX],temp,i1,i2,ci1,ci2;
  int sum1,sum2,maxSum=0;;
  vector< pair<int,int> > comn;
  scanf("%d",&n1);
  while(n1!=0) {
    maxSum=0;
    comn.clear();
    for(int i=0;i<n1;i++) {
      scanf("%d",&a[i]);
    }
    scanf("%d",&n2);
    for(int i=0;i<n2;i++) {
      scanf("%d",&b[i]);
    }
    if(n1>n2) {
      for(int i=0;i<n2;i++) {
	temp=bsearch(a,b[i],0,n1);
	if(temp!=-1)
	  comn.push_back(make_pair(temp,i));
      }
    }
    else {
      for(int i=0;i<n1;i++) {
	temp=bsearch(b,a[i],0,n2);
	if(temp!=-1)
	  comn.push_back(make_pair(i,temp));
      }
    }

    i1=0;i2=0;
    vector< pair<int,int> >::iterator itr=comn.begin();
    while(itr!=comn.end()) {
      ci1=(*itr).first;
      ci2=(*itr).second;
      sum1=0;sum2=0;
      for(;i1<=ci1;i1++) {
	sum1+=a[i1];
      }
      for(;i2<=ci2;i2++) {
	sum2+=b[i2];
      }
      maxSum=maxSum+max(sum1,sum2);
      itr++;
    }
    sum1=0;sum2=0;
    for(;i1<n1;i1++) {
      sum1+=a[i1];
    }
    for(;i2<n2;i2++) {
      sum2+=b[i2];
    }
    maxSum=maxSum+max(sum1,sum2);
    printf("%d\n", maxSum);

    scanf("%d",&n1);
  }
  
  return 0;
}
