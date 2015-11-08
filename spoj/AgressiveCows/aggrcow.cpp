#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool check(int dist,vector<int>& pos, int nCows) {
  //  cout<<"DIST = "<<dist<<endl;
  int lastPos;
  lastPos=pos.front();
  // cout<<"Pos = "<<lastPos<<endl;
  nCows--;
  for(vector<int>::iterator itr=pos.begin()+1;itr!=pos.end();itr++) {
    if(*itr-lastPos>=dist) {
      lastPos=*itr;
      nCows--;
      //  cout<<"Pos = "<<lastPos<<endl;
      if(nCows==0)
	return true;
    }
  }
  return false;
}


int main() {
  int nTest,N,C,temp,dist;
  int start,end,mid;
  cin>>nTest;
  vector<int> stall;
  for(int t=1;t<=nTest;t++) {
    cin>>N>>C;
    stall.clear();
    for(int i=0;i<N;i++) {
      cin>>temp;
      stall.push_back(temp);
    }
    sort(stall.begin(),stall.end());
    start=0;
    end=stall.back()-stall.front()+1;
    while(end-start>1) {
      mid=(start+end)/2;
      if(check(mid,stall,C))
	start=mid;
      else
	end=mid;
      //      cout<<"Start = "<<start <<" and end  = "<<end<<endl;
    }
    cout<<start<<endl;
  }
  return 0;
}
