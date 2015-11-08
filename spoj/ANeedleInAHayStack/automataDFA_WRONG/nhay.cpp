#include<iostream>
#include<string>

using namespace std;

class StrDFA {
  int nStates;
  int **transTable;
  int currentState;
public:
    void operate() {
    char ch;
    bool found=false;
    int pos=0;
    currentState=0;
    cin>>ch;
    while(ch!='\n') {
      currentState=transTable[currentState][ch-97];
      if(currentState==nStates-1) {
	cout<<pos-(nStates-2)<<endl;
	found=true;
      }
      pos++;
      cin>>ch;
      cout<<"ch = "<<ch<<endl;
    }
    if(!found)
      cout<<endl;
    
  }


  void init(string pattern) {
    currentState=0;
    nStates=pattern.length()+1;
    transTable=new int*[nStates];
    for(int i=0;i<nStates;i++) {
      transTable[i]=new int[26];
    }

    char fc=pattern.at(0);
    bool flag=true;
    int charIndex=1;

    transTable[0][fc-97]=1;
    for(int i=1;i<nStates-1;i++,charIndex++) {
      if(flag) {
	if(fc!=pattern[charIndex]) {
	  transTable[i][pattern[charIndex]-97]=i+1;
	  transTable[i][fc-97]=i;
	  flag=false;
	}
	else {
	  transTable[i][pattern[charIndex]-97]=i+1;
	}
      }
      else {
	transTable[i][pattern[charIndex]-97]=i+1;
	transTable[i][fc-97]=1;
      }
    }
    transTable[nStates-1][fc-97]=1;
    /*
    for(int i=0;i<nStates;i++) {
      cout<<i<<": ";
      for(int j=0;j<26;j++) {
	cout<<transTable[i][j]<<" ";
      }
      cout<<endl;
      }*/
  } 

  void del() {
    for(int i=0;i<=nStates;i++) {
      delete[] transTable[i];
    }
    delete[] transTable;
    nStates=-1;
    currentState=-1;
  }
};

int main () {
  int len;
  StrDFA automata;
  string needle;
  while(cin>>len) {
    cin>>needle;
    automata.init(needle);
    automata.operate();
    cout<<endl;
  }
  return 0;
}
