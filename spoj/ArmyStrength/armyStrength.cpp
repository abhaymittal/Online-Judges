//PROBLEM CODE: ARMY

#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

int main() {
  int nTest;
  int nGod, nMech,temp;
  deque<int> godz, mech;
  cin>>nTest;

  for(int i=0;i<nTest;i++) {
    godz.clear();
    mech.clear();
    
    cin>>nGod;
    cin>>nMech;

    for(int i=0;i<nGod;i++) {
      cin>>temp;
      godz.push_back(temp);
    }

    for(int i=0;i<nMech;i++) {
      cin>>temp;
      mech.push_back(temp);
    }

    sort(godz.begin(),godz.end());
    sort(mech.begin(),mech.end());

    while((godz.size()!=0)&&(mech.size()!=0)) {
      if(godz.front()<mech.front())
	godz.pop_front();
      else
	mech.pop_front();
    }

    if(godz.size()==0)
      cout<<"MechaGodzilla"<<endl;
    else if(mech.size()==0)
      cout<<"Godzilla"<<endl;
    else
      cout<<"uncertain"<<endl;
    
  }
}
