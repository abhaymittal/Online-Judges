/**
 * Decrypt a message based on the encryption given in description
 * PROBLEM CODE: TOANDFRO
 */

#include<iostream>
#include<string>

using namespace std;

int main() {
  int col,row;
  string mesg;
  int index=0;
  char **msgAray;
  cin>>col;

  while(col!=0) {
    cin>>mesg;
    index=0;
    row=mesg.length()/col;
    msgAray=new char*[row];
    for(int i=0;i<row;i++) {
      msgAray[i]=new char[col];
    }


    for(int i=0;i<row;i++) {
      if((i%2)==0) {
	for(int j=0;j<col;j++) {
	  msgAray[i][j]=mesg.at(index);
	  index++;
	}
      }
      else {
	for(int j=col-1;j>=0;j--) {
	  msgAray[i][j]=mesg.at(index);
	  index++;
	}
      }
    }

    for(int j=0;j<col;j++) {
      for(int i=0;i<row;i++) {
	cout<<msgAray[i][j];
      }
    }
    cout<<endl;

    cin>>col;
  }
  return 0;
}
