#include<iostream>
#include<vector>
#include<climits>
#include<cstdio>

using namespace std;

struct coordinate {
  int x;
  int y;
} ;

int abs (int x) {
  if(x<0)
    return -1*x;
  else return x;
}

int main() {

  coordinate coord;
  int n,m;
  bool bitmap[182][182];
  int distance[182][182];
  vector<coordinate> whiteList;

  int nTest;
  char ch;
  
  cin>>nTest;

  for(int i=0;i<nTest;i++) {
    scanf("%d%d",&n,&m);
    getchar();
    for(int j=0;j<n;j++) {
      for(int k=0;k<m;k++) {
	scanf("%c",&ch);
	//	printf("ch = %c\n",ch);
	ch=ch-48;
       
	if(ch==0)
	  bitmap[j][k]=false;
	else {
	  
	  bitmap[j][k]=true;
	  coord.x=j;
	  coord.y=k;
	  whiteList.push_back(coord);
	}
      }
      getchar();
    }
    //    printf("White pixels  = %d\n",whiteList.size());
    int dist;
    for(int i=0;i<n;i++) {
      for(int j=0;j<m;j++) {
	if(bitmap[i][j])
	  distance[i][j]=0;
	else {
	  distance[i][j]=INT_MAX;
	  for(int k=0;k<whiteList.size();k++) {
	    dist=abs(i-whiteList[k].x)+abs(j-whiteList[k].y);
	    if(dist<distance[i][j])
	      distance[i][j]=dist;
	  }
	}
      }
    }

    for(int i=0;i<n;i++) {
      for(int j=0;j<m;j++) {
	printf("%d",distance[i][j]);
	if(j!=(m-1))
	  printf(" ");
      }
      printf("\n");
    }
  }
  return 0;
}
