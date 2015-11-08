#include<iostream>
#include<string>

using namespace std;

int main() {
  string sequence;
  int counter[8]={0};
  int beginIndex=0;
  int endIndex=2,arrayIndex;

  int nTest,dsNum;

  cin>>nTest;

  for(int i=0;i<nTest;i++) {
    cin>>dsNum;
    cin>>sequence;
    beginIndex=0;
    for(int j=0;j<8;j++) {
      counter[j]=0;
    }
    arrayIndex=0;
    if(sequence[beginIndex]=='H')
      arrayIndex+=4;
    if(sequence[beginIndex+1]=='H')
      arrayIndex+=2;
    if(sequence[beginIndex+2]=='H')
      arrayIndex+=1;
    counter[arrayIndex]++;
    for(beginIndex=1;beginIndex<=37;beginIndex++) {
      if(sequence[beginIndex-1]=='H')
	arrayIndex-=4;
      arrayIndex*=2;
      if(sequence[beginIndex+2]=='H')
	arrayIndex+=1;
      counter[arrayIndex]++;
    }

    cout<<dsNum;
    for(int j=0;j<8;j++) {
      cout<<" "<<counter[j];
    }
    cout<<endl;
  }

  return 0;  
}
