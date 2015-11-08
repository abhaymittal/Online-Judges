#include<cstdio>
#include<algorithm>
#define MAXN 50010
using namespace std;
typedef struct {
  int maxL;
  int maxR;
  int max;
  int flag; //denotes if maxL is same as maxR, i.e. the whole array range
} stNode;

int buildSegTree(stNode *stree, int index, short *A, int l, int r) {
  if(l==r) {
    stree[index].maxL=A[l];
    stree[index].maxR=A[l];
    stree[index].max=A[l];
    stree[index].flag=1;
  }
  else {
    int mid=(l+r)/2;
    buildSegTree(stree, 2*index+1, A,l,mid);
    buildSegTree(stree,2*index+2, A, mid+1,r);
    if((stree[2*index+1].flag!=1)||(stree[2*index+2].maxL<=0)) {
      stree[index].maxL=stree[2*index+1].maxL;
    }
    else {
      stree[index].maxL=stree[2*index+1].maxL+stree[2*index+2].maxL;
      if(stree[2*index+2].flag==1)
	stree[index].flag=1;
    }
    if((stree[2*index+2].flag!=1)||(stree[2*index+1].maxR<=0)) {
      stree[index].maxR=stree[2*index+2].maxR;
    }
    else {
      stree[index].maxR=stree[2*index+2].maxR+stree[2*index+1].maxR;
      if(stree[2*index+1].flag==1)
	stree[index].flag=1;
    }
    int mx = stree[2*index+1].maxR+stree[2*index+2].maxL;
    stree[index].max=max(mx,max(stree[2*index+1].max,stree[2*index+2].max));
  }
  return 0;
}

stNode querySegTree(stNode *stree, int index, int l, int r,int ql, int qr) {
  stNode st;
  if((l==ql)&&(r==qr))
    return stree[index];
  int mid=(l+r)/2;
  if(qr<=mid)
    return querySegTree(stree, 2*index+1, l, mid, ql, qr);
  else if (ql>=mid+1)
    return querySegTree(stree,2*index+2, mid+1,r,ql,qr);
  else {
    stNode st1=querySegTree(stree,2*index+1,l,mid,ql,mid);
    stNode st2=querySegTree(stree,2*index+2,mid+1,r,mid+1,qr);
    if((st1.flag!=1)||(st2.maxL<0))
      st.maxL=st1.maxL;
    else {
      st.maxL=st1.maxL+st2.maxL;
      if(st2.flag==1)
	st.flag=1;
    }
    if((st2.flag!=1)||(st1.maxR<0))
      st.maxR=st2.maxR;
    else {
      st.maxR=st1.maxR+st2.maxR;
      if(st1.flag==1)
	st.flag=1;
    }

    int mx=st1.maxR+st2.maxL;
    st.max=max(mx,max(st1.max,st2.max));
  }
  return st;
}


int main() {
  int N,M,xi,yi;

  short A[MAXN];
  stNode stree[4*MAXN];
  scanf("%d",&N);

  for(int i=0;i<N;i++) {
    scanf("%hd",&A[i]);
  }
  buildSegTree(stree,0,A,0,N-1);

  scanf("%d",&M);
  stNode result;
  for(int i=0;i<M;i++) {
    scanf("%d%d",&xi,&yi);
    xi--;
    yi--;
    result=querySegTree(stree,0,0,N-1,xi,yi);
    printf("%d\n",result.max);
  }
  return 0;
}
