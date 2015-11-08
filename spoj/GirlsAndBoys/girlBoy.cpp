//PROBLEM CODE: GIRLSNBS

#include<iostream>

using namespace std;

int main() {
  int nGirls,nBoys;
  cin>>nGirls>>nBoys;

  while(nGirls!=-1) {
    if(nGirls>nBoys) {
      nBoys++;
      if((nGirls%nBoys)==0)
	cout<<(nGirls/nBoys)<<endl;
      else
	cout<<(nGirls/nBoys)+1<<endl;
    }
    else {
      nGirls++;
      if((nBoys%nGirls)==0)
	cout<<(nBoys/nGirls)<<endl;
      else
	cout<<(nBoys/nGirls)+1<<endl;
    }
    cin>>nGirls>>nBoys;
  }

  return 0;
}
