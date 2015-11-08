#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int computeLCS(string a, string b) {
  int **table;
  table=new int*[a.length()+1];
  for(int i=0;i<=a.length();i++) {
    table[i]=new int[b.length()+1];
  }

  for(int i=0;i<=a.length();i++)
    table[i][0]=0;
  for(int j=0;j<=b.length();j++)
    table[0][j]=0;

  for(int i=1;i<=a.length();i++) {
    for(int j=1;j<=b.length();j++) {
      if(a[i-1]==b[j-1])
	table[i][j]=table[i-1][j-1]+1;
      else
	table[i][j]=max(table[i-1][j],table[i][j-1]);
    }
  }
  int result =table[a.length()][b.length()];
  for(int i=0;i<=a.length();i++)
    delete[] table[i];
  delete[] table;
  return result;
}

int main() {
  int nTest;
  string str,strRev;
  cin>>nTest;
  for(int i=0;i<nTest;i++) {
    cin>>str;
    strRev="";
    for(int i=str.length()-1;i>=0;i--) {
      strRev+=str[i];
    }
    cout<<str.length()-computeLCS(str,strRev)<<endl;
  }
  return 0;
}
