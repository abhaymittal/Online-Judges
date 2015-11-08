#include<cstdio>
#include<algorithm>
#define MAXN 50010
using namespace std;
typedef struct {
  int maxL;
  int maxR;
  int max;
  int sum;
} stNode;



int buildSegTree(stNode *stree, int index, short *A, int l, int r) {
  if(l==r) {
    stree[index].maxL=A[l];
    stree[index].maxR=A[l];
    stree[index].max=A[l];
    stree[index].sum=A[l];
  }
  else {
    int mid=(l+r)/2;
    buildSegTree(stree, 2*index, A,l,mid);
    buildSegTree(stree,2*index+1, A, mid+1,r);
    int left=2*index, right=left+1;
    stree[index].maxL=max(stree[left].maxL,stree[left].sum+stree[right].maxL);
    stree[index].maxR=max(stree[right].maxR,stree[right].sum+stree[left].maxR);
    stree[index].sum=stree[left].sum+stree[right].sum;
    stree[index].max=max(stree[index].maxL,max(stree[index].maxR,max(stree[left].max,max(stree[right].max,stree[left].maxR+stree[right].maxL))));
  }
  return 0;
}

stNode querySegTree(stNode *stree, int index, int l, int r,int ql, int qr) {
  stNode st;
  if((l==ql)&&(r==qr))
    return stree[index];
  int mid=(l+r)/2;
  if(qr<=mid)
    return querySegTree(stree, 2*index, l, mid, ql, qr);
  else if (ql>=mid+1)
    return querySegTree(stree,2*index+1, mid+1,r,ql,qr);
  else {
    stNode st1=querySegTree(stree,2*index,l,mid,ql,mid);
    stNode st2=querySegTree(stree,2*index+1,mid+1,r,mid+1,qr);
    st.maxL=max(st1.maxL,st1.sum+st2.maxL);
    st.maxR=max(st2.maxR,st2.sum+st1.maxR);
    st.sum=st1.sum+st2.sum;
    st.max=max(st.maxL,max(st.maxR,max(st1.max,max(st2.max,st1.maxR+st2.maxL))));
  }
  return st;
}

int main() {
  int N, M, xi, yi;
  short A[MAXN];
  stNode stree[4*MAXN];
  scanf("%d",&N);

  for(int i=0;i<N;i++) {
    scanf("%hd",&A[i]);
  }
  buildSegTree(stree,1,A,0,N-1);

  scanf("%d",&M);
  stNode result;
  for(int i=0;i<M;i++) {
    scanf("%d%d",&xi,&yi);
    xi--;
    yi--;
    result=querySegTree(stree,1,0,N-1,xi,yi);
    printf("%d\n",result.max);
  }
  return 0;

}
