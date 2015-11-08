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

vector<long long> fib(int N) {
  vector<vector<long long> > t(K,vector<long long>(K));
  vector<long long> res(2);
  vector<long long> fi(K);

  fi[0]=0;
  fi[1]=1;
  t[0][0]=0;
  t[0][1]=1;
  t[1][0]=1;
  t[1][1]=1;
  if(N==0) {
    return fi;
  }
  t=pow(t,N);
    for(int j=0;j<K;j++) {
      for(int k=0;k<K;k++) {
	res[j]=(res[j]+t[j][k]*fi[k])%MOD;
      }
    }
    //    cout<<"Result = "<<res[0]<<" "<<res[1]<<endl;
  return res;
}
int main() {
  int nTest,N,M,a,b,c;
  long long sum;
  vector<long long > pwr;
  scanf("%d",&nTest);
  for(int t=1;t<=nTest;t++) {
    scanf("%d%d",&N,&M);
    sum=0;
    pwr=fib(N);
    if(N==M) {
      sum=pwr[0];
    }
    else {
      sum=(pwr[0]+pwr[1])%MOD;
      a=pwr[0];
      b=pwr[1];
      for(int i=N+2;i<=M;i++) {
	c=(a+b)%MOD;
	a=b;
	b=c;
	sum=(sum+c)%MOD;
      }
    }
    printf("%lld\n",sum);
  }
  return 0;
}
