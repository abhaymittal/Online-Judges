#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 120000

using namespace std;

int querySegTree(int l,int r, int ql, int qr, int index, int segTree[MAXN]) {
  if((l==ql)&&(r==qr)) {
    return segTree[index];
  }

  int mid=(l+r)>>1;
  if(qr<=mid) {
    return querySegTree(l,mid,ql,qr,2*index,segTree);
  }
  else if (ql>=mid+1) {
    return querySegTree(mid+1,r,ql,qr,2*index+1,segTree);    
  }
  else {
    int v1=querySegTree(l,mid,ql,mid,2*index,segTree);
    int v2=querySegTree(mid+1,r,mid+1,qr,2*index+1,segTree);
    return v1+v2;
  }
}


void replaceSegPoint(int l, int r, int point, int val, int index,int segTree[MAXN]) {
  if((l==r)&&(l==point)) {
    if(val!=0)
      segTree[index]=val;
    else
      segTree[index]=(segTree[index]==1)?-1:1;
    return;
  }
  int mid=(l+r)>>1;
  if(point<=mid) {
    replaceSegPoint(l,mid,point,val,2*index,segTree);
  }
  else
    replaceSegPoint(mid+1,r,point,val,2*index+1,segTree);
  segTree[index]=segTree[2*index]+segTree[2*index+1];
}


int main() {
  int n,m,k,segTree[MAXN],temp;
  char ch;
  for(int t=1;t<=10;t++) {
    memset(segTree,0,MAXN*sizeof(int));
    scanf("%d",&n);
    scanf("%c",&ch);
    for(int i=1;i<=n;i++) {
      scanf("%c",&ch);
      if(ch=='(')
	replaceSegPoint(1,n,i,1,1,segTree);
      else
	replaceSegPoint(1,n,i,-1,1,segTree);
    }

    scanf("%d",&m);
    for(int i=1;i<=m;i++) {
      scanf("%d",&k);
      if(k==0) {
	if(segTree[1]==0)
	  printf("YES\n");
	else
	  printf("NO\n");
      }
      else
	replaceSegPoint(1,n,k,0,1,segTree);
    }
  }
  return 0;
}
