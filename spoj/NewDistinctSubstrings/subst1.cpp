#include<cstdio>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
string str;
bool compareStrChar(int a, int b) {
  return str[a]<str[b];
}


int createSuffixArray(vector<int>& pos, vector<int>& rank)  {
  pos.resize(str.length());
  rank.resize(str.length());
  for(int i=0;i<str.length();i++) {
    pos[i]=i;
  }

  sort(pos.begin(),pos.end(),compareStrChar);
  vector<bool> bh(str.length(),false);
  vector<bool> b2h(str.length(),false);
  vector<int> count(str.length(),0);
  vector<int> next(str.length(),0);

  for(int i=0;i<str.length();i++) {
    bh[i]=i==0||str[pos[i]]!=str[pos[i-1]];
  }

  for(int h=1;h<str.length();h<<=1) {
    int buckets=0;
    for(int i=0;i<str.length();i=next[i]) {
      int j;
      for(j=i+1;(j<str.length())&&!bh[j];j++);
      next[i]=j;
      buckets++;
    }
    if(buckets==str.length())
      break;
    for(int i=0;i<str.length();i=next[i]){
      count[i]=0;
      for(int j=i;j<next[i];j++) {
	rank[pos[j]]=i;
      }
    }

    count[rank[str.length()-h]]++;
    b2h[rank[str.length()-h]]=true;
    for(int i=0;i<str.length();i=next[i]) {
      for(int j=i;j<next[i];j++){
	int t=pos[j]-h;
	if(t>=0) {
	  count[rank[t]]++;
	  rank[t]=rank[t]+count[rank[t]]-1;
	  b2h[rank[t]]=true;
	}
      }

      for(int j=i;j<next[i];j++) {
	int t=pos[j]-h;
	if(t>=0&&b2h[rank[t]])
	  for(int k=rank[t]+1;k<str.length()&&!bh[k]&&b2h[k];k++)
	    b2h[k]=false;
      }
    }

    for(int i=0;i<str.length();i++) {
      pos[rank[i]]=i;
      bh[i] = bh[i]|b2h[i];
    }
  }
  
}


void getHeight(vector<int>& pos, vector<int>& rank, vector<int>& height) {
  height.resize(str.length());
  for(int i=0;i<str.length();i++)
    height[i]=0;

  int h=0;
  for(int i=0;i<str.length();i++) {
    if(rank[i]>0) {
      int k=pos[rank[i]-1];
      while(i+h<str.length()&&k+h<str.length()&&str[i+h]==str[k+h])
	h++;
      height[rank[i]]=h;
      if(h>0) h--;
    }
  }
}


int main() {
  vector<int> pos,rank,height;
  char st[50001];
  int nTest;
  scanf("%d",&nTest);

  for(int i=0;i<nTest;i++) {
    pos.clear();
    rank.clear();
    height.clear();
    scanf("%s",st);
    str.clear();
    str+=string(st);
    createSuffixArray(pos,rank);
    getHeight(pos,rank,height);
    int ans=str.substr(pos[0]).length();
    for(int i=1;i<str.length();i++) {
      ans=ans+str.substr(pos[i]).length()-height[i];
    }
    printf("%d\n",ans);
  }
  return 0;
}




