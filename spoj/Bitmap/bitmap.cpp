#include<cstdio>
#include<algorithm>
#include<climits>
#include<queue>
#include<utility>

using namespace std;

void bfs(queue<pair<int,int> >& bfsQue, int (&dist)[182][182],bool (&color)[182][182], int n, int m) {
  pair<int,int> temp;
  int x,y;
  while(!bfsQue.empty()) {
    x=bfsQue.front().first;
    y=bfsQue.front().second;
    bfsQue.pop();
    if((x+1<n)&&(color[x+1][y]==1)) {
      temp.first=x+1;
      temp.second=y;
      bfsQue.push(temp);
      color[x+1][y]=0;
      dist[x+1][y]=dist[x][y]+1;
    }

    if((x-1>=0)&&(color[x-1][y]==1)) {
      temp.first=x-1;
      temp.second=y;
      bfsQue.push(temp);
      color[x-1][y]=0;
      dist[x-1][y]=dist[x][y]+1;
    }

    if((y+1<m)&&(color[x][y+1]==1)) {
      temp.first=x;
      temp.second=y+1;
      bfsQue.push(temp);
      color[x][y+1]=0;
      dist[x][y+1]=dist[x][y]+1;
    }

    if((y-1>=0)&&(color[x][y-1]==1)) {
      temp.first=x;
      temp.second=y-1;
      bfsQue.push(temp);
      color[x][y-1]=0;
      dist[x][y-1]=dist[x][y]+1;       
    }
  }
}

int main() {
  int n,m,nTest,sz;
  char ch,str[183];
  int dist[182][182];
  bool color[182][182];

  pair<int,int> temp;
  queue<pair<int,int> > bfsQue;

  scanf("%d",&nTest);

  for(int i=0;i<nTest;i++) {
    scanf("%d%d",&n,&m);

    for(int j=0;j<n;j++) {
      //      scanf("%s",str);
      scanf(" %s",str);
      
      for(int k=0;k<m;k++) {	
	ch=str[k]-48;
	if(!ch) {
	  dist[j][k]=INT_MAX;
	  color[j][k]=1;
	}
	else {
	  dist[j][k]=0;
	  color[j][k]=0;
	  temp.first=j;
	  temp.second=k;
	  bfsQue.push(temp);
	}
      }

      
    }

    bfs(bfsQue,dist,color,n,m);

    for(int j=0;j<n;j++) {
      for(int k=0;k<m;k++) {
	printf("%d",dist[j][k]);
	if(k!=(m-1))
	  printf(" ");
      }
      printf("\n");
    }
    
  }
  return 0;
}

