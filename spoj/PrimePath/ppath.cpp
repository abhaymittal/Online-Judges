#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#define MAXPRIME 102
#define MAXPRIMESEG 4500
#define MAPSIZE 1070

using namespace std;

typedef queue<pair<int,int> > qp;

int sieveErato(vector<int>& primeList,int num) {
  primeList.clear();
  if(num>=2)
    primeList.push_back(2);
  bool prime[MAXPRIME];
  int ival;
  for(int i=0;i<num/2;i++) {
    prime[i]=false;
  }
  int mp=((num)*2+1);
  for(int i=0;i<num/2;i++) {
    if(prime[i])
      continue;
    ival=(i+1)*2+1;
    primeList.push_back(ival);
    for(int j=ival*ival;j<=mp;j=j+2*ival)
      prime[j/2-1]=true;
  }
  return 0;
}

int segSieve(vector<int>& primeList, int n1, int n2) {
  vector<int> seed;
  int temp,num,max;
  bool prime[MAXPRIMESEG];
  if(n1%2==0)
    n1++;
  if(n2%2==0)
    n2--;
  num=n2-n1+1;
  num=num/2+1;
  temp=sqrt(n2);
  if((temp+1)*(temp+1)<=n2)
    temp++;
  if(temp%2==0)
    sieveErato(seed,temp-1);
  else
    sieveErato(seed,temp);
  for(int j=0;j<num;j++)
    prime[j]=false;
  int i=0;
  if(seed[i]==2)
    i++;
  for(;i<seed.size();i++) {
    temp=n1/seed[i];
    temp=temp*seed[i];
    if(temp<n1) {
      if(temp%2==1)
	temp+=2*seed[i];
      else
	temp+=seed[i];
    }
    for(int j=temp;j<=n2;j+=2*seed[i]) {
      prime[(j-n1)/2]=true;
    }
  }
  for(int i=0;i<num;i++) {
    if(!prime[i])
      primeList.push_back(i*2+n1);
  }
  return 0;
}

int digDifference(int a,int b)  {//finds the digit difference in the four digits from units place
  a=a%10000;
  b=b%10000; //get last 4 digits
  int d1,d2;
  int diff=0;
  for(int i=0;i<4;i++) {
    d1=a%10;
    d2=b%10;
    if(d1-d2!=0)
      diff++;
    a/=10;
    b/=10;
  }
  return diff;
}

int bfs(int start, int end, int n, bool map[MAPSIZE][MAPSIZE]) {
  qp que;
  bool flag = false;
  int index,level;
  bool color[MAPSIZE]={0};
  que.push(make_pair(start,0));
  while(!que.empty()) {
    index=que.front().first;
    level=que.front().second;
    color[index]=1;
    que.pop();
    for(int j=0;j<n;j++) {
      if(map[index][j]&&!color[j]) {
	if(j==end) {
	  flag=true;
	  level++;
	  break;
	}
	que.push(make_pair(j,level+1));
      }
    }
    if(flag)
      break;
  }
  if(flag)
    return level;
  return -1;
}

int main() {
  vector<int> primeList;
  segSieve(primeList,1001,9999);
  bool map[MAPSIZE][MAPSIZE];
  int nTest,a,b,aIn,bIn,n,diff,dist;
  n=primeList.size();
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      diff=digDifference(primeList[i],primeList[j]);
      if(diff==1)
	map[i][j]=1;
    }
  }
  scanf("%d",&nTest);
  for(int t=1;t<=nTest;t++) {
    scanf("%d%d",&a,&b);
    dist=0;
    if(a!=b) {
      aIn=find(primeList.begin(),primeList.end(),a)-primeList.begin();
      bIn=find(primeList.begin(),primeList.end(),b)-primeList.begin();
      dist=bfs(aIn,bIn,n,map);
    }
    printf("%d\n",dist);
  }
  return 0;
}
