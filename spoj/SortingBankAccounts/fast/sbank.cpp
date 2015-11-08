#include<iostream>
#include<string>
#include<map>

using namespace std;

int main() {
  map<string,int> accList;
  string accn;
  int nTest,n;
  cin>>nTest;
  for(int test=1;test<=nTest;test++) {
    cin>>n;
    getline(cin,accn);
    accList.clear();
    for(int i=0;i<n;i++) {
      getline(cin,accn);
      accn.resize(31);
      accList[accn]=accList[accn]+1;
    }
    for(map<string,int>::iterator itr=accList.begin();itr!=accList.end();itr++) {
      cout<<itr->first<<" "<<itr->second<<endl;
    }
  }
  return 0;

}
