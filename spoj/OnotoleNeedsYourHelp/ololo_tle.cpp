#include<iostream>
#include<set>

using namespace std;

int main() {

  int N;
  int pyaniId;
  set<int> pyani;
  cin>>N;
  for(int i=0;i<N;i++) {
    cin>>pyaniId;
    if(pyani.find(pyaniId)!=pyani.end()) {
      pyani.erase(pyaniId);
    }
    else
      pyani.insert(pyaniId);
  }

  cout<<*pyani.begin()<<endl;
  return 0;
}
