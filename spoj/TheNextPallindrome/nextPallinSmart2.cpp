#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int compare(string num1,string num2) {
  // -1 if num1<num2, 1 if num1>num2, 0 if num1=num2
  if(num1.length()<num2.length())
    return -1;
  else if(num1.length()>num2.length())
    return 1;
  else {
    for(int i=0;i<num1.length();i++) {
      if(num1.at(i)<num2.at(i))
	return -1;
      else if(num1.at(i)>num2.at(i))
	return 1;
    }
  }
  return 0;
}

string findNextPallin(string num) {
  int mid1,mid2;
  string one="1";
  mid2=num.length()/2;
  if(num.length()%2==0)
    mid1=mid2-1;
  else
    mid1=mid2;
  string pallin=num;
  string left=num.substr(0,mid2);//mid2 specifies number of characters
  pallin.resize(num.length()-num.length()/2);
  reverse(left.begin(),left.end());
  pallin=pallin+left;
  //cout<<"original: "<<pallin<<endl;
  while(compare(pallin,num)!=1) {
    bool carry=false;
    pallin.at(mid1)=((pallin.at(mid1)+1-48)%10)+48;
    if(pallin.at(mid1)=='0')
      carry=true;
    pallin.at(mid2)=pallin.at(mid1);
    //cout<<"Pallin: "<<pallin<<" carry: "<<carry<<endl;
    int index=1;
    while(carry) {
      if((mid1-index)<0) {
	pallin=one+pallin;
	pallin.at(pallin.length()-1)='1';
	break;
      }
      pallin.at(mid1-index)=((pallin.at(mid1-index)+1-48)%10)+48;
      if(pallin.at(mid1-index)=='0')
	carry=true;
      else
	carry=false;
      pallin.at(mid2+index)=pallin.at(mid1-index);
      //cout<<"Pallin: "<<pallin<<" carry: "<<carry<<endl;
      index++;
    }
  }
  return pallin;
}

int main() {
  int nTest;
  string num;
  cin>>nTest;

  for(int test=1;test<=nTest;test++) {
    cin>>num;

    string pallin=findNextPallin(num);
    cout<<pallin<<endl;
  }  
}
