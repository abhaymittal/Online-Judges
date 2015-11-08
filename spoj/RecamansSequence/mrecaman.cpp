#include<cstdio>
#include<iostream>
#include<unordered_map>
#define MAXN 500001

using namespace std;
int recsec[MAXN];

void buildRecSec() {
  unordered_map<int,bool> presentMap;
  int temp;
  recsec[0]=0;
  presentMap[0]=true;
  for(int i=1;i<MAXN;i++) {
    temp=recsec[i-1]-i;
    if(presentMap[temp]||temp<0) {
      recsec[i]=recsec[i-1]+i;
      presentMap[recsec[i-1]+i]=true;
    }
    else {
      recsec[i]=temp;
      presentMap[temp]=true;
    }
  }
}

int main() {
  int k;
  buildRecSec();
  scanf("%d",&k);
  while(k!=-1) {
    printf("%d\n",recsec[k]);
    scanf("%d",&k);
  }
  return 0;
}
