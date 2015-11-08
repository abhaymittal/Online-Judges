#include<iostream>
#include<climits>
#include<utility>
#include<vector>

using namespace std;

pair<int,int> DFS(int node, vector< vector<int> >& adjMatrix, vector<int> status, int numNodes);

int main() {
  int numNodes;
  int v1,v2;

  cin>>numNodes;
  vector<int> status(numNodes,0);
  vector<vector<int> > adjMatrix(numNodes,vector<int>(numNodes,0));

  for(int i=0;i<numNodes-1;i++) {
    cin>>v1;
    cin>>v2;
    adjMatrix[v1-1][v2-1]=1;
    adjMatrix[v2-1][v1-1]=1;
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
    numAdjNodes=0;
    for(int j=0;j<numNodes;j++) {
      numAdjNodes+=adjMatrix[i][j];
    }
    if(numAdjNodes>rootAdjNodes) {
      rootNode=i;
      rootAdjNodes=numAdjNodes;
    }
  }
  //cout<<"Selected "<<rootNode<<" as the root node"<<endl;
  //Now use the selected root to start a recursive DFS procedure which returns the length of the longest path
  pair<int,int>maxPath;
  maxPath=DFS(rootNode,adjMatrix,status,numNodes);
  for(int i=0;i<numNodes;i++) {
    status[i]=0;
  }
  maxPath=DFS(maxPath.second,adjMatrix,status,numNodes);
  cout<<maxPath.first<<endl;
  return 0;
}

pair<int,int> DFS(int node, vector< vector<int> >& adjMatrix, vector<int> status, int numNodes) {
  pair<int,int> path;
  pair<int,int> maxPath=make_pair(-1,node);
  status[node]=1;
  for(int i=0;i<numNodes;i++) {
    if((adjMatrix[node][i]==1)&&(status[i]==0)) {
      path=DFS(i,adjMatrix,status,numNodes);
      if(path.first>maxPath.first)
	maxPath=path;
    }
  }
  maxPath.first+=1;
  return maxPath;
}
