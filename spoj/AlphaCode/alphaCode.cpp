#include<iostream>
#include<string>

using namespace std;

int main() {
  string msg;
  int *diffDecoding;
  cin>>msg;
  while(msg.compare("0")!=0) {
    diffDecoding=new int[msg.length()];
    
    if(msg.at(msg.length()-1)!='0')
      diffDecoding[0]=1;
    else
      diffDecoding[0]=0;

    if(msg.length()>1) {
      if(msg.at(msg.length()-2)=='0')
	diffDecoding[1]=0;
      else {
	if((((msg.at(msg.length()-2)-48)*10)+msg.at(msg.length()-1)-48)<=26)
	  diffDecoding[1]=diffDecoding[0]+1;
	else
	  diffDecoding[1]=diffDecoding[0];
      }
    }

    for(int i=2;i<msg.length();i++) {
      if(msg.at(msg.length()-1-i)=='0')
	diffDecoding[i]=0;
      else {
	if((((msg.at(msg.length()-1-i)-48)*10)+msg.at(msg.length()-i)-48)<=26)
	  diffDecoding[i]=diffDecoding[i-1]+diffDecoding[i-2];
	else
	  diffDecoding[i]=diffDecoding[i-1];
      }
    }

    cout<<diffDecoding[msg.length()-1]<<endl;
    delete[] diffDecoding;

    cin>>msg;
  }
}
