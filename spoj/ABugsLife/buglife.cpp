//Logic: Check if the graph is bipartite
#include<cstdio>
#include<set>
#include<utility>
#include<vector>
#include<queue>
#define RED 1
#define BLUE 2
#define id first
#define color second
using namespace std;
typedef queue<pair<int,int> > clist;
typedef vector<vector<int> > mat;

bool checkBipart(mat& adjList) {
  vector<int>::iterator  it;
  int V=adjList.size()-1;
  vector<int> color(V+1,0);
  queue<int> que;
  int parent,current=0;
  color[1]=RED;
  que.push(1);
  while(!que.empty()) {
    parent=current;
    current=que.front();
    for(it=adjList[current].begin();it!=adjList[current].end();it++) {
      if(color[*it]==0) {
	que.push(*it);
	color[*it]=(color[current]==RED)?BLUE:RED;
      }
      else if ((*it)!=parent) {
	if(color[*it]==color[current])
	  return false;
      }
    }
    que.pop();
    if(que.empty()) {
      for(int i=1;i<V+1;i++) {
	if(color[i]==0) {
	  que.push(i);
	  color[i]=RED;
	  break;
	}
      }
    }
  }
  return true;
}

int main() {
  int nTest, nBugs, nInt,u,v;
  mat adjList;
  bool flag;
  scanf("%d",&nTest);
  for(int t=1;t<=nTest;t++) {
    scanf("%d%d",&nBugs,&nInt);
    adjList.resize(nBugs+1);
    for(int i=0;i<nInt;i++) {
      scanf("%d%d",&u,&v);
      adjList[u].push_back(v);
      adjList[v].push_back(u);
    }
    flag=checkBipart(adjList);
    if(flag) {
      printf("Scenario #%d:\nNo suspicious bugs found!\n",t);
    }
    else
      printf("Scenario #%d:\nSuspicious bugs found!\n",t);
    adjList.clear();
  }
  return 0;
}
