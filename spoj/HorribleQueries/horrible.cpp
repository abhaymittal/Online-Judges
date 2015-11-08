#include<cstdio>

#define MAXN 400000

struct segNode {
  long long sum;
  long long incr;
  bool flag;
};

void clearSegTree(segNode segTree[MAXN],int n) {
  for(int i=0;i<n;i++) {
    segTree[i].sum=0;
    segTree[i].incr=0;
    segTree[i].flag=false;
  }
}

void updateSegNode(segNode segTree[MAXN], int index,int l, int r) {
  //printf("Update => l = %d, r = %d, incr = %lld, index = %d\n",l,r,segTree[index].incr,index);
  if(!segTree[index].flag)
    return;
  if(l==r) {
    segTree[index].sum+=segTree[index].incr;
    segTree[index].flag=false;
    segTree[index].incr=0;
    return;
  }
  segTree[index].sum+=segTree[index].incr*(r-l+1);
  segTree[index].flag=false;
  segTree[2*index].flag=true;
  segTree[2*index].incr+=segTree[index].incr;
  segTree[2*index+1].flag=true;
  segTree[2*index+1].incr+=segTree[index].incr;
  segTree[index].incr=0;
}

long long querySegTree(int l, int r, int ql, int qr, int index, segNode segTree[MAXN]) {
  if(segTree[index].flag) {
    updateSegNode(segTree,index,l,r);
  }
  if((l==ql)&&(r==qr))
    return segTree[index].sum;
  int mid=(l+r)/2;
  if(qr<=mid)
    return querySegTree(l,mid,ql,qr,2*index,segTree);
  else if (ql>=mid+1)
    return querySegTree(mid+1,r,ql,qr,2*index+1,segTree);
  else {
    long long v1=querySegTree(l,mid,ql,mid,2*index,segTree);
    long long v2=querySegTree(mid+1,r,mid+1,qr,2*index+1,segTree);
    return v1+v2;
  }
}

void updateSegRange(int l, int r, int ql, int qr, long long val, int index, segNode segTree[MAXN]) {
  // printf("l = %d, r = %d, ql = %d, qr = %d, val = %lld, index = %d\n",l,r,ql,qr,val,index);
  if(segTree[index].flag) {
    updateSegNode(segTree,index,l,r);
  }
  if((l==ql)&&(r==qr)) {
    segTree[index].flag=true;
    segTree[index].incr+=val;
    updateSegNode(segTree,index,l,r);
    return;
  }
  int mid=(l+r)/2;
  if(qr<=mid) {
    updateSegRange(l,mid,ql,qr,val,2*index,segTree);
    updateSegNode(segTree,2*index+1,mid+1,r);
    segTree[index].sum=segTree[2*index].sum+segTree[2*index+1].sum;
  }
  else if (ql>=mid+1) {
    updateSegRange(mid+1,r,ql,qr,val,2*index+1,segTree);
    updateSegNode(segTree,2*index,l,mid);
    segTree[index].sum=segTree[2*index].sum+segTree[2*index+1].sum;
  }
  else {
    updateSegRange(l,mid,ql,mid,val,2*index,segTree);
    updateSegRange(mid+1,r,mid+1,qr,val,2*index+1,segTree);
    segTree[index].sum=segTree[2*index].sum+segTree[2*index+1].sum;
  }
}
  segNode segTree[MAXN];
int main() {
  int nTest,N,C,opId,p,q;
  long long v;
  scanf("%d",&nTest);
  for(int t=1;t<=nTest;t++) {
    scanf("%d%d",&N,&C);
    clearSegTree(segTree,4*N);
    for(int c=1;c<=C;c++) {
      scanf("%d %d %d",&opId,&p,&q);
      if(opId==1) { //opId == 1
	printf("%lld\n",querySegTree(1,N,p,q,1,segTree));
      }
      else if(opId==0) {
	scanf("%lld",&v);
	updateSegRange(1,N,p,q,v,1,segTree);
      }
    }
  }
  return 0;
}
