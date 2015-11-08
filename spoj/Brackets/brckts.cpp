#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAXN 120000

using namespace std;

struct stNode{
  int leftBr; // increase in negative
  int rightBr; // increase in positive
  void merge(stNode& a, stNode& b) {
    leftBr=b.leftBr;
    rightBr=a.rightBr;
    if(a.leftBr<b.rightBr)
      rightBr+=(b.rightBr-a.leftBr);
    else
      leftBr+=(a.leftBr-b.rightBr);
  }
};


stNode querySegTree(stNode* stree, int index, int l, int r, int ql, int qr) {
  if((l==ql)&&(r==qr))
    return stree[index];
  int mid=(l+r)>>1;
  if(qr<=mid)
    return querySegTree(stree, 2*index, l, mid, ql, qr);
  else if (ql>=mid+1)
    return querySegTree(stree, 2*index+1,mid+1,r, ql,qr );
  else {
    stNode v1,v2,val;
    v1=querySegTree(stree,2*index,l,mid,ql,mid);
    v2=querySegTree(stree,2*index+1,mid+1,r,mid+1,qr);
    val.merge(v1,v2);
    return val;
  }
}

//1 denotes left paranthesis and -1 denotes right
void updateSegPoint(stNode* stree, int index, int l, int r, int qIndex, int val) {
  if((l==r)&&(l==qIndex)) {
    if(val!=0) {
      if(val==1)
	stree[index].leftBr=1;
      else
	stree[index].rightBr=1;
    }
    else {
      if(stree[index].leftBr==1) {
	stree[index].leftBr=0;
	stree[index].rightBr=1;
      }
      else {
	stree[index].leftBr=1;
	stree[index].rightBr=0;
      }
    }
    return;
  }

  int mid=(l+r)>>1;
  if(qIndex<=mid) {
    updateSegPoint(stree,2*index,l,mid,qIndex,val);
    stree[index].merge(stree[2*index],stree[2*index+1]);
  }
  else {
    updateSegPoint(stree,2*index+1,mid+1,r,qIndex,val);
    stree[index].merge(stree[2*index],stree[2*index+1]);
  }
  
}
  stNode stree[MAXN];

int main() {
  int n,m,k,temp;
  char ch;
  for(int t=1;t<=10;t++) {
    memset(stree,0,MAXN*sizeof(stNode));
    scanf("%d",&n);
    scanf("%c",&ch);
    for(int i=1;i<=n;i++) {
      scanf("%c",&ch);
      if(ch=='(')
	updateSegPoint(stree,1,1,n,i,1);
      else
	updateSegPoint(stree,1,1,n,i,-1);
      /*      for(int j=0;j<4*n;j++)
	printf("%d-%d | ",stree[j].leftBr,stree[j].rightBr);
	printf("\n");*/
    }
    scanf("%d",&m);
    printf("Test %d:\n",t);
    for(int i=0;i<m;i++) {
      scanf("%d",&k);
      if(k==0) {
	if((stree[1].leftBr==0)&&(stree[1].rightBr==0))
	  printf("YES\n");
	else
	  printf("NO\n");
      }
      else
	updateSegPoint(stree,1,1,n,k,0);
    }
  }
  return 0;
}

