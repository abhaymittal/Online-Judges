#include<cstdio>
#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<bitset>
#include<queue>
#include<stack>
#include<set>

#define MAXB 50000
#define MAXC 50000
#define NIL 0
#define INF (1<<29)
using namespace std;

vector<set<int> > adjList(MAXC+1);
int pairCow[MAXC+1];
int pairBull[MAXB+1];
int dist[MAXC+1];


bool bfs(int nCows,int nBulls) {
  queue<int> bfsque;
  // Make the distance of every matched edge as infinity so that they can be given the actual
  // distance during bfs layering. Make the distances of unmatched edges as 0.
  for(int i=1;i<=nCows;i++) {
    if(pairCow[i]==NIL) { 
      dist[i]=0;
      bfsque.push(i);
    }
    else
      dist[i]=INF;
  }
  dist[NIL]=INF; //Distance of NIL is also infinity

  // Create the BFS tree. We are only pushing the left side vertices on the stack by following a
  // matched edge. Thus we follow an unmatched edge when we go left to right and a matched edge
  // from right to left. We update the distances of the left vertices which are already matched
  // and hence have infinity initial distances. NOTE: We increase the distance of a vertex on the
  // left by 1 if we can come from the previous left vertex to this one by using one matched
  // right vertex.
  while(!bfsque.empty()) {
    int c=bfsque.front();
    bfsque.pop();
    if(dist[c]<dist[NIL]) {
      for(set<int>::iterator it = adjList[c].begin();it!=adjList[c].end();it++) {
	int b=*it;
	if(dist[pairBull[b]]==INF) {
	  dist[pairBull[b]]=dist[c]+1;
	  bfsque.push(pairBull[b]);
	}
      }
    }
  }
  //Unmatched right vertex was paired with NIL. So the distance of NIL must be less than infinity
  // if there is a path to any unmatched vertex.
  return dist[NIL]!=INF;
}

bool dfs(int c, int nCows,int nBulls) {
  // the following if condition is important as c may be NIL in the base case of this recursive
  // function. We use this to do DFS till we reach nill and then just calculate the symmetric
  // difference.

  if(c!=NIL) {
    for(set<int>::iterator it = adjList[c].begin();it!=adjList[c].end();it++) {
      int b=*it;
      // We check if the paired vertex of the adjacent vertex is at a distance of 1 from the
      // current vertex. If the paired vertex is null, we will return true in the next recursive
      // call and update this path to be matched. Otherwise, we just go recurse from the paired
      // vertex till we reach the NIL vertex
      if(dist[pairBull[b]]==dist[c]+1){
	if(dfs(pairBull[b],nCows,nBulls)) { //after updating the pairs of the descendent nodes
	  pairBull[b]=c;
	  pairCow[c]=b;
	  return true;
	}
      }
    }
    dist[c]=INF; //this case will occur if we are not able to find a matching
    return false;
  }
  return true; //this is important when c becomes NIL in the base case
}

int main() {
  int N,M,P,A,B,result=0;
  scanf("%d %d %d",&N,&M,&P);
  for(int i=0;i<P;i++) {
    scanf("%d %d",&A,&B);
    adjList[A].insert(B);
  }
  int matching=0;
  while(bfs(N,M)) {
    for(int i=1;i<=N;i++) {
      if(pairCow[i]==NIL)
	matching+=dfs(i,N,M);
    }
  }
  printf("%d\n",matching);
  return 0;
}
