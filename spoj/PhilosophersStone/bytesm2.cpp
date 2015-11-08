#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
  int nTest,h,w,stn;
  vector<int> maxStones, prevMaxStones,stones;
  cin>>nTest;

  for(int i=0;i<nTest;i++) {
    cin>>h;
    cin>>w;
    stones.clear();
    prevMaxStones.clear();
    maxStones.clear();

    for(int i=0;i<w;i++) {
      cin>>stn;
      stones.push_back(stn);

    }
    prevMaxStones.assign(stones.begin(),stones.end());
    stones.clear();

    for(int i=1;i<h;i++) {
      stones.clear();
      maxStones.clear();
      for(int j=0;j<w;j++) {
	cin>>stn;
	stones.push_back(stn);
      }
      if(w>1) {
	stn=max(prevMaxStones[0],prevMaxStones[1]);
	maxStones.push_back(stones[0]+stn);
	for(int j=1;j<w-1;j++) {
	  stn=max(prevMaxStones[j-1],prevMaxStones[j]);
	  stn=max(stn,prevMaxStones[j+1]);
	  maxStones.push_back(stones[j]+stn);
	}
	stn=max(prevMaxStones[w-2],prevMaxStones[w-1]);
	maxStones.push_back(stones[w-1]+stn);

	prevMaxStones.assign(maxStones.begin(),maxStones.end());
      }
      else {
	maxStones.push_back(stones[0]+prevMaxStones[0]);
	prevMaxStones.assign(maxStones.begin(),maxStones.end());
      }

    }

    cout<<*max_element(prevMaxStones.begin(),prevMaxStones.end())<<endl;
  }
  return 0;
}
