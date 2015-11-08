#include<iostream>
#include<vector>

using namespace std;

int main() {
  int N,temp,revenue;
  vector<int> value;
  vector<vector<int> > dqTable;

  cin>>N;
  for(int i=0;i<N;i++) {
    cin>>temp;
    value.push_back(temp);
  }
  dqTable.resize(N);
  for(int i=0;i<N;i++) {
    dqTable[i].resize(N);
  }
  for(int j=0;j<N;j++) {
    dqTable[0][j]=N*value[j];
  }
  for(int i=1;i<N;i++) {
    for(int j=0;j<N-i;j++) {
      dqTable[i][j]=max(dqTable[i-1][j]+(N-i)*value[j+i],dqTable[i-1][j+1]+(N-i)*value[j]);
    }
  }

  cout<<dqTable[N-1][0]<<endl;
  for(int i=0;i<N;i++) {
    dqTable[i].clear();
  }
  dqTable.clear();
  value.clear();
  return 0;
}
