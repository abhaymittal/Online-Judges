//PROBLEM CODE: COINS

#include<iostream>
#include<vector>

using namespace std;

struct packet {
  int val;
  int maxDollars;
};

unsigned int findMaxDollars(int n, vector<packet>& coins);
unsigned int getDollars(int value, vector<packet>& coins);

int main() {
  int n;
  vector<packet> coins;

  while(cin>>n) {
    coins.clear();
    cout<<findMaxDollars(n,coins)<<endl;
  }

  return 0;
}


unsigned int findMaxDollars(int n, vector<packet>& coins) {
  packet temp;
  if(n==0)
    return 0;
  if(getDollars(n,coins)!=0)
    return getDollars(n,coins);
  
  temp.val=n;
  unsigned int divCoin=findMaxDollars(n/2,coins)+findMaxDollars(n/3,coins)+findMaxDollars(n/4,coins);
  if(n<divCoin) {
    temp.maxDollars=divCoin;
    coins.push_back(temp);
    return divCoin;
  }
  else {
    temp.maxDollars=n;
    coins.push_back(temp);
    return n;
  }

}

unsigned int getDollars(int value, vector<packet>& coins) {
  for(vector<packet>::iterator itr=coins.begin();itr!=coins.end();itr++) {
    if((*itr).val==value)
      return (*itr).maxDollars;
  }
  return 0;
}
