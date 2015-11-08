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


int main() {
  vector<int> pos,rank,height;
  vector<vector<int> >M;
  cin>>str;
  createSuffixArray(pos,rank);
  for(int i=0;i<str.length();i++) {
    cout<<pos[i]<<endl;
  }
  return 0;


}




