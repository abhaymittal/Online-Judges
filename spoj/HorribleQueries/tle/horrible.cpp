#include<cstdio>
#include<cstring>
#define MAXN 4*100000

int querySegTree(int l, int r, int ql, int qr, int index, long long segTree[MAXN]) {
  if((l==ql)&&(r==qr))
    return segTree[index];
  int mid=(l+r)/2;
  if(qr<=mid)
    return querySegTree(l,mid,ql,qr,2*index,segTree);
  else if (ql>=mid+1)
    return querySegTree(mid+1,r,ql,qr,2*index+1,segTree);
  else {
    int v1=querySegTree(l,mid,ql,mid,2*index,segTree);
    int v2=querySegTree(mid+1,r,mid+1,qr,2*index+1,segTree);
    return v1+v2;
  }
}

int updateSegTree(int l,int r, int ql,int qr, long long val, int index, long long segTree[MAXN]) {
  if((l==r)&&(ql==qr)&&(l==ql)) {
    segTree[index]+=val;
  }
  else {
    int mid=(l+r)/2;
    if(qr<=mid) {
      updateSegTree(l,mid,ql,qr,val,2*index,segTree);
    }
    else if(ql>=mid+1) {
      updateSegTree(mid+1,r,ql,qr,val,2*index+1,segTree);
    }
    else {
      updateSegTree(l,mid,ql,mid,val,2*index,segTree);
      updateSegTree(mid+1,r,mid+1,qr,val,2*index+1,segTree);
    }
    segTree[index]=segTree[2*index]+segTree[2*index+1];
  }
  return segTree[index];
}

int main() {
  long long segTree[MAXN];
  int nTest,N,C,opId,p,q;
  long long v;
  scanf("%d",&nTest);
  for(int t=1;t<=nTest;t++) {
    scanf("%d%d",&N,&C);
    memset(segTree,0,N*sizeof(int));
    for(int c=1;c<=C;c++) {
      scanf("%d %d %d",&opId,&p,&q);
      if(opId==1) { //opId == 1
	printf("%d\n",querySegTree(1,N,p,q,1,segTree));
      }
      else if(opId==0) {
	scanf("%lld",&v);
	updateSegTree(1,N,p,q,v,1,segTree);
      }      
    }
  }
  return 0;
}
