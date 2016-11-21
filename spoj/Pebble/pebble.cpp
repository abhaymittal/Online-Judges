#include<cstdio>
#include<iostream>
#include<string>
#include<bitset>

using namespace std;

int main() {
  string input;
  int gCount=0;
  while(getline(cin,input)) {
    gCount++;
    bool nFlips=false;
    int nSteps=0;
    for(int i=0;i<input.length();i++) {
      if(nFlips && input[i]=='0') {
	nFlips=false;
	nSteps++;
      }
      else if (input[i]=='1') {
	if(!nFlips) {
	  nFlips=true;
	  input[i]='0';
	  nSteps++;
	}
	else {
	  input[i]='0';
	}
      }

    }
    printf("Game #%d: %d\n",gCount,nSteps);
    
  }
}
