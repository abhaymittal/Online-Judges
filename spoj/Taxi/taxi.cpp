#include<cstdio>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<bitset>
#include<cstring>


#define MAXP 410
#define MAXC 410

using namespace std;
int pMatch[MAXP];
bool seen[MAXP];
int dist(pair<int,int>& a, pair<int,int>& b) {
  return (abs(a.first-b.first)+abs(a.second-b.second));
}



bool findMatch(int cab,int nP, bool adjMat[MAXC][MAXP]) {
  for(int j=0;j<nP;j++) {
    if(adjMat[cab][j] && !seen[j]) {
      seen[j]=true;
      if(pMatch[j]<0 || findMatch(pMatch[j],nP,adjMat)) {
	pMatch[j]=cab;
	return true;
      }
    }
  }
  return false;
}



int main() {
  int nTest,nP,nC,speed,cTime;
  int x,y;
  vector<pair<int,int> > pList(MAXP);
  vector<pair<int,int> > cList(MAXC);
  bool adjMat[MAXC][MAXP];
  
  scanf("%d",&nTest);
  for (int t=1;t<=nTest;t++) {

    memset(seen,0,sizeof(seen));
    memset(pMatch,-1,sizeof(pMatch));
    memset(adjMat,0,sizeof(adjMat));
    scanf("%d %d %d %d", &nP,&nC,&speed,&cTime);
    for(int p=0;p<nP;p++) {
      scanf("%d %d",&x,&y);
      pList[p]=make_pair(x,y);
    }

    for(int c=0;c<nC;c++) {
      scanf("%d %d",&x,&y);
      cList[c]=make_pair(x,y);

      for(int j=0;j<nP;j++) {
	int ds=dist(cList[c],pList[j]);
	if(ds<=(cTime*speed)/200)
	  adjMat[c][j]=1;
      }
    }

    // for(int i=0;i<nC;i++) {
    //   for (int j=0;j<nP;j++) {
    // 	printf("%d ",adjMat[i][j]);
    //   }
    //   printf("\n");
    // }

    int result=0;
    for(int i=0;i<nC;i++) {
      memset(seen,0,sizeof(seen));
      result+=findMatch(i,nP,adjMat);
    }
    printf("%d\n",result);
  }
  return 0;
}
