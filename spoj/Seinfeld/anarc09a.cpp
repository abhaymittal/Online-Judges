#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
  vector<int> ubLeft, ubRight; //ub = unbalanced
  string line;
  int k;
  k=0;
  while(true) {
    cin>>line;
    if(line[0]=='-')
      break;
    k++;
    ubLeft.clear();
    ubRight.clear();
    for(int i=0;i<line.length();i++) {
      if(line[i]=='{') {
	ubLeft.push_back(i);
      }
      else {
	if(!ubLeft.empty())
	  ubLeft.pop_back();
	else
	  ubRight.push_back(i);
      }
    }
    cout<<k<<". "<<ubRight.size()/2+ubRight.size()%2+ubLeft.size()/2+ubLeft.size()%2<<endl;
  }
  return 0;
}
