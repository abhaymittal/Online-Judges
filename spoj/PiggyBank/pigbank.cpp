#include<iostream>
#include<utility>
#include<climits>
#include<vector>
#include<algorithm>

#define val first
#define weight second

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b) {
  if(a.weight<b.weight)
    return true;
  else if(a.weight==b.weight)
    if(a.val<b.val)
      return true;
  return false;
}


int main() {
  int nTest, wte,wtf,wt;
  int nCoins,minVl;
  vector< pair<int, int> > coins;
  vector<int> table;
  pair<int,int> temp;
  cin>>nTest;
  for(int test=1;test<=nTest;test++) {
    cin>>wte;
    cin>>wtf;
    coins.clear();
    table.clear();
    cin>>nCoins;
    for(int i=0;i<nCoins;i++) {
      cin>>temp.val;
      cin>>temp.weight;
      coins.push_back(temp);
    }
    sort(coins.begin(),coins.end(),compare);
    /*cout<<"The coins are "<<endl;
    for(int i=0;i<coins.size();i++) {
      cout<<coins[i].val<<" "<<coins[i].weight<<endl;
      }*/

    //create dp table;
    temp.val=-1;
    temp.weight=-1;
    int i;
    wt=wtf-wte;
    //  cout<<"wt = "<<wt<<endl;
    for(i=0;i<=coins[0].weight-1;i++) {
      table.push_back(-1);
    }
    vector<pair<int,int> >::iterator itr=coins.begin();

    for(;i<=wt;i++) {
      bool flag = false;
      minVl=INT_MAX;
      if((itr!=coins.end())&&(*itr).weight==i) {
	minVl=(*itr).val;
	flag=true;
      }
      while((itr!=coins.end())&&((*itr).weight==i))
	itr++;
      for(int j=1;j<=i/2;j++) {
	if((table[j]==-1)||(table[i-j]==-1))
	  continue;
	else if ((table[j]+table[i-j])<minVl) {
	  minVl=table[j]+table[i-j];
	  flag=true;
	}
      }
      if(!flag)
	minVl=-1;
      table.push_back(minVl);
    }
    /*    cout<<" The table is "<<endl;
    int k=0;
    for(vector<int>::iterator it=table.begin();it!=table.end();it++) {
      cout<<k<<" "<<*it<<endl;
      k++;
      }*/
    if(table[wt]!=-1)
      cout<<"The minimum amount of money in the piggy-bank is "<<table[wt]<<"."<<endl;
    else
      cout<<"This is impossible."<<endl;
  }
  return 0;
}
