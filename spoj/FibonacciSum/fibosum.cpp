#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

const int MOD=1000000007;
const int K=2;

vector<vector<long long> > matMul(vector<vector<long long> > A, vector<vector<long long> > B) {
  vector<vector<long long> > C(A.size(),vector<long long>(B[0].size()));
  for(int i=0;i<A.size();i++) {
    for(int j=0;j<B[0].size();j++) {
      for(int k=0;k<B.size();k++) {
	C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MOD;
      }
    }
  }
  return C;
}

vector<vector<long long> > pow(vector<vector<long long> > mat, int p) {
  if(p==1)
    return mat;
  if(p%2)
    return matMul(mat,pow(mat,p-1));
  vector<vector<long long> > M=pow(mat,p/2);
  return matMul(M,M);
}

vector<long long> sumFib(int N) {
  vector<vector<long long> > t(K+1,vector<long long>(K+1));
  vector<long long> res(K+1);
  vector<long long> fi(K+1);

  fi[0]=0;
  fi[1]=1;
  fi[2]=1;
  t[0][0]=0;
  t[0][1]=1;
  t[0][2]=0;
  t[1][0]=1;
  t[1][1]=1;
  t[1][2]=1;
  t[2][0]=0;
  t[2][1]=0;
  t[2][2]=1;
  if(N==0) {
    return fi;
  }
  t=pow(t,N);
    for(int j=0;j<K+1;j++) {
      for(int k=0;k<K+1;k++) {
	res[j]=(res[j]+t[j][k]*fi[k])%MOD;
      }
    }

  return res;
}

int main() {
  int nTest,N,M;
  long long sum;
  vector<long long> fSum;
  scanf("%d",&nTest);
  for(int t=1;t<=nTest;t++) {
    scanf("%d%d",&N,&M);
    if(N==0) {
      fSum=sumFib(M);
      printf("%lld\n",fSum[0]);
    }
    else {
      fSum=sumFib(M);
      sum=fSum[0];
      fSum=sumFib(N-1);
      sum=sum-fSum[0];
      if(sum<0)
	sum=(sum+MOD)%MOD;
      printf("%lld\n",sum);
    }
  }
  return 0;
}
