#include<iostream>
#include<climits>
#include<utility>
#include<vector>

using namespace std;

pair<int,int> DFS(int node, vector< vector<int> >& adjList, vector<int> status, int numNodes);

int main() {
  int numNodes;
  int v1,v2;

  cin>>numNodes;
  vector<int> status(numNodes,0);
  vector<vector<int> > adjList(numNodes);

  for(int i=0;i<numNodes-1;i++) {
    cin>>v1;
    cin>>v2;
    adjList[v1-1].push_back(v2-1);
    adjList[v2-1].push_back(v1-1);
  }
  /*
  cout<<"The adjacency matrix is : "<<endl;
  for(int i=0;i<numNodes;i++) {
    for(int j=0;j<numNodes;j++) {
      cout<<adjMatrix[i][j]<<"\t";
    }
    cout<<endl;
  }
  */
  int numAdjNodes, rootAdjNodes, rootNode;
  rootNode=-1;
  rootAdjNodes=-1;
  for(int i=0;i<numNodes;i++) {
    numAdjNodes=adjList[i].size();
    if(numAdjNodes>rootAdjNodes) {
      rootNode=i;
      rootAdjNodes=numAdjNodes;
    }
  }


  //cout<<"Selected "<<rootNode<<" as the root node"<<endl;
  //Now use the selected root to start a recursive DFS procedure which returns the length of the longest path
  pair<int,int>maxPath;
  maxPath=DFS(rootNode,adjList,status,numNodes);
  for(int i=0;i<numNodes;i++) {
    status[i]=0;
  }
  maxPath=DFS(maxPath.second,adjList,status,numNodes);
  cout<<maxPath.first<<endl;
  return 0;
}

pair<int,int> DFS(int node, vector< vector<int> >& adjList, vector<int> status, int numNodes) {
  pair<int,int> path;
  pair<int,int> maxPath=make_pair(-1,node);
  status[node]=1;
  for(vector<int>::iterator it=adjList[node].begin();it!=adjList[node].end();it++) {
    if(status[*it]==0) {
      path=DFS(*it,adjList,status,numNodes);
      if(path.first>maxPath.first)
	maxPath=path;
    }
  }
  maxPath.first+=1;
  return maxPath;
}
