//PROBLEM CODE: STPAR

#include<iostream>
#include<stack>

using namespace std;

int main() {
  stack<int> side;
  int nMob,index,car;
  //index represents the expected car number
  bool flag;
  cin>>nMob;
  while(nMob!=0) {
    
    while(!side.empty())
      side.pop();
    
    index=1;
    flag=true;
    
    
    for(int i=0;i<nMob;i++) {
      cin>>car;

      if(!flag)
	continue;
      
      if(car!=index) {
	if(side.empty())
	  side.push(car);
	
	else if(side.top()==index) {
	  while((!side.empty())&&(side.top()==index)) {
	    side.pop();
	    index++;
	  }
	  side.push(car);
	}
	
	else if(side.top()<car) {
	  flag=false;
	}
	
	else {
	  side.push(car);
	}
      }
      else
	index++;

      
    }
    if(flag)
      cout<<"yes"<<endl;
    else
      cout<<"no"<<endl;
    cin>>nMob;
  }

  return 0;
}
