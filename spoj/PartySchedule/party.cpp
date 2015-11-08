#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int,int>b) {
  if(a.first<b.first)
    return true;
  if(a.first==b.first)
    return (a.second>b.second);
  return false;
}

int main () {
  int partyBudget, nParties;
  vector< pair<int,int> >unqChart;
  pair<int,int> **maxFun;
  while(true) {
    cin>>partyBudget>>nParties;
    if((partyBudget==0)&&(nParties==0))
      break;
    if(partyBudget==0) {
      cout<<"0 0"<<endl;
      continue;
    }
    
    unqChart.resize(nParties);
    for(int i=0;i<nParties;i++) {
      cin>>unqChart[i].first>>unqChart[i].second;
    }
    
    sort(unqChart.begin(),unqChart.end(),compare);

    //    maxFun.resize(unqChart.size());
    maxFun=new pair<int,int>*[unqChart.size()+1];
    for(int i=0;i<=unqChart.size();i++) {
      maxFun[i]=new pair<int,int>[partyBudget+1];
    }

    for(int i=0;i<=unqChart.size();i++) {
      maxFun[i][0].first=0;
      maxFun[i][0].second=0;
    }
    for(int j=0;j<=partyBudget;j++) {
      maxFun[0][j].first=0;
      maxFun[0][j].second=0;
    }

    for(int i=1;i<=unqChart.size();i++) {
      for(int w=1;w<=partyBudget;w++) {
	if(unqChart[i-1].first<=w) {
	  if(unqChart[i-1].second+maxFun[i-1][w-unqChart[i-1].first].second>maxFun[i-1][w].second) {
	    maxFun[i][w].second=unqChart[i-1].second+maxFun[i-1][w-unqChart[i-1].first].second;
	    maxFun[i][w].first=unqChart[i-1].first+maxFun[i-1][w-unqChart[i-1].first].first;
	  }
	  else if(unqChart[i-1].second+maxFun[i-1][w-unqChart[i-1].first].second==maxFun[i-1][w].second) {
	    if(unqChart[i-1].first+maxFun[i-1][w-unqChart[i-1].first].first<=maxFun[i-1][w].first) {
	      maxFun[i][w].second=unqChart[i-1].second+maxFun[i-1][w-unqChart[i-1].first].second;
	      maxFun[i][w].first=unqChart[i-1].first+maxFun[i-1][w-unqChart[i-1].first].first;
	    }
	    else {
	      maxFun[i][w].second=maxFun[i-1][w].second;
	      maxFun[i][w].first=maxFun[i-1][w].first;
	    }
	  }
	  else {
	    maxFun[i][w].second=maxFun[i-1][w].second;
	    maxFun[i][w].first=maxFun[i-1][w].first;
	  }
	}
	else {
	  maxFun[i][w].second=maxFun[i-1][w].second;
	  maxFun[i][w].first=maxFun[i-1][w].first;
	}
      }
    }

    cout<<maxFun[unqChart.size()][partyBudget].first<<" "<<maxFun[unqChart.size()][partyBudget].second<<endl;

    for(int i=0;i<=unqChart.size();i++) {
      delete[] maxFun[i];
    }
    delete[] maxFun;
  }
  return 0;
}
