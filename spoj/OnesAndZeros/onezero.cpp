#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<ctime>
#include<bitset>
#include<cstdlib>

#define MAXN 20001

using namespace std;
bitset<MAXN> seen;
vector<int> parent(MAXN,0);
vector<char> value(MAXN,-1);
string getResult(int n) {
  queue<int> que;
  seen.reset();
  int num=1;
  parent[0]=-1;
  parent[1]=-1;
  value[1]='1';
  seen.set(1);
  if(1%n==0) {
    return "1";
  }
  que.push(1%n);
  int mod;
  while(!que.empty()) {
    mod=que.front();
    // printf("Mod = %d\n",mod);
    que.pop();
    if (mod==0) {
      break;
    }
    int left=(mod*10)%n;
    // printf("Left = %d\n",left);
    if(!seen.test(left)){
      parent[left]=mod;
      value[left]='0';
      seen.set(left);
      que.push(left);
    }
    int right=(left+1)%n;
    // printf("Right = %d\n",right);
    if(!seen.test(right)) {
      parent[right]=mod;
      value[right]='1';
      seen.set(right);
      que.push(right);
    }
  }
  string result="";
  result=value[mod];
  while(parent[mod]!=-1) {
    mod=parent[mod];
    result=value[mod]+result;
  }
  return result;
}

void solve() {
  int K,n;
  scanf("%d",&K);
  int i=0;
  while(i++<K) {
    scanf("%d",&n);
    printf("%s\n",getResult(n).c_str());
  }
}

int main() {
  //  clock_t beg=clock();
  solve();
  //  clock_t end=clock();
  // printf("%lf sec.\n",double(end-beg)/CLOCKS_PER_SEC);
  return 0;
}
