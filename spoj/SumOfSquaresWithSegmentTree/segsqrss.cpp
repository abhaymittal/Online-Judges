#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAXN 400000

using namespace std;

struct stNode {
  int sum;
  long long sqrSum;
  int incr;
  int replace;
  int nLeaves;
  void merge(stNode& a, stNode& b) {
    nLeaves=a.nLeaves+b.nLeaves;
    sum=a.sum+b.sum;
    sqrSum=a.sqrSum+b.sqrSum;
    incr=0;
    replace=0;
  }
  void incSplit(stNode& a, stNode& b) {
    a.incr+=incr;
    b.incr+=incr;
    a.sqrSum+=a.nLeaves*incr*incr+2*incr*a.sum;
    a.sum+=a.nLeaves*incr;
    b.sqrSum+=b.nLeaves*incr*incr+2*incr*b.sum;
    b.sum+=b.nLeaves*incr;
    incr=0;
  }
  void reSplit(stNode& a, stNode& b) {
    a.incr=0;
    b.incr=0;
    a.replace=replace;
    b.replace=replace;
    a.sum=a.nLeaves*replace;
    a.sqrSum=a.nLeaves*replace*replace;
    b.sum=b.nLeaves*replace;
    b.sqrSum=b.nLeaves*replace*replace;
    replace=0;
  }

} stree[MAXN];


stNode querySegTree(stNode* stree, int index, int l, int r, int ql, int qr) {
  if((l==ql)&&(r==qr))
    return stree[index];
  if(stree[index].replace!=0) {
    stree[index].reSplit(stree[2*index],stree[2*index+1]);
  }
  if(stree[index].incr!=0) {
    stree[index].incSplit(stree[2*index],stree[2*index+1]);
  }
  int mid=(l+r)>>1;
  if(qr<=mid)
    return querySegTree(stree,2*index,l,mid,ql,qr);
  else if (ql>=mid+1)
    return querySegTree(stree,2*index+1,mid+1,r,ql,qr);
  else {
    stNode v1,v2,val;
    v1=querySegTree(stree,2*index,l,mid,ql,mid);
    v2=querySegTree(stree,2*index+1,mid+1,r,mid+1,qr);
    val.merge(v1,v2);
    return val;
  }
}
//upId = 1 add val
//upId = 0 change node = val

void updateSegNode (stNode& sNode, int val, int upId) {
  if(upId==1) {
    sNode.sqrSum+=(sNode.nLeaves*val*val+2*sNode.sum*val);
    sNode.sum+=(val*sNode.nLeaves);
    sNode.incr+=val;
  }
  else if(upId==0) {
    sNode.sum=sNode.nLeaves*val;
    sNode.sqrSum=sNode.nLeaves*val*val;
    sNode.replace=val;
    sNode.incr=0;
  }
}


void updateSegRange(stNode* stree, int index, int l, int r, int ql, int qr, int val,int upId) {
  if((l==ql)&&(r==qr)) {
    if(l==r)
      stree[index].nLeaves=1;
    return updateSegNode(stree[index], val,upId);
  }
  int mid=(l+r)>>1;
  if(stree[index].replace!=0)
    stree[index].reSplit(stree[2*index],stree[2*index+1]);
  stree[index].incSplit(stree[2*index],stree[2*index+1]);
  if(qr<=mid)
    updateSegRange(stree,2*index,l,mid,ql,qr,val,upId);
  else if (ql>=mid+1)
    updateSegRange(stree,2*index+1,mid+1,r,ql,qr,val,upId);
  else {
    updateSegRange(stree,2*index,l,mid,ql,mid,val,upId);
    updateSegRange(stree,2*index+1,mid+1,r,mid+1,qr,val,upId);
  }
  stree[index].merge(stree[2*index],stree[2*index+1]);
}


int main() {
  int nTest,N,Q,st,nd,x,temp,opId;
  scanf("%d",&nTest);
  for(int t=1;t<=nTest;t++) {
    memset(stree,0,MAXN*sizeof(stNode));
    scanf("%d%d",&N,&Q);
    for(int i=1;i<=N;i++) {
      scanf("%d",&temp);
      updateSegRange(stree,1,1,N,i,i,temp,0);
    }
    printf("Case %d:\n",t);
    for(int i=1;i<=Q;i++) {
      scanf("%d%d%d",&opId,&st,&nd);
      if(opId==2)
	printf("%lld\n",querySegTree(stree,1,1,N,st,nd).sqrSum);
      else {
	scanf("%d",&x);
	updateSegRange(stree,1,1,N,st,nd,x,opId);
      }
    }
  }
  return 0;
}
