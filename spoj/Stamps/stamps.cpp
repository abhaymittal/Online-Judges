//PROBLEM CODE: STAMPS

#include<iostream>
#include<algorithm>

using namespace std;

int main() {
  int nTest,  borrow, nFriends;
  int *stamp,index;

  cin>>nTest;

  for(int test=1;test<=nTest;test++) {
    cin>>borrow;
    cin>>nFriends;

    stamp=new int[nFriends];

    for(int i=0;i<nFriends;i++) {
      cin>>stamp[i];
    }


    sort(stamp,stamp+nFriends);

    index=nFriends-1;
    while((borrow>0)&&(index>=0)) {
      borrow=borrow-stamp[index];
      index--;
    }

    cout<<"Scenario #"<<test<<":"<<endl;

    if(borrow>0)
      cout<<"impossible\n"<<endl;
    else
      cout<<nFriends-1-index<<"\n"<<endl;

    delete [] stamp;
  }
  return 0;
}
