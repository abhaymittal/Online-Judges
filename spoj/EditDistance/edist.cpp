#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
  int nTest;
  string A,B;

  int **table;

  cin>>nTest;
  for(int i=0;i<nTest;i++) {
    cin>>A;
    cin>>B;

    table=new int*[A.length()+1];
    for(int i=0;i<=A.length();i++) {
      table[i]=new int[B.length()+1];
    }

    for(int i=0;i<=A.length();i++) {
      table[i][0]=i;
    }
    for(int j=0;j<=B.length();j++) {
      table[0][j]=j;
    }

    for(int i=1;i<=A.length();i++) {
      for(int j=1;j<=B.length();j++) {
	if(A.at(i-1)==B.at(j-1)) {
	  table[i][j]=min(min(table[i-1][j]+1,table[i][j-1]+1),table[i-1][j-1]);
	}
	else
	  table[i][j]=min(min(table[i-1][j]+1,table[i][j-1]+1),table[i-1][j-1]+1);
      }
    }

    cout<<table[A.length()][B.length()]<<endl;
    for(int i=0;i<=A.length();i++) {
      delete[] table[i];
    }
    delete[] table;
				 
  }
  return 0;
}
