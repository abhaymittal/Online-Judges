#include<iostream>

using namespace std;

int main() {
  int nTest;
  int index,sum,row,col,nelem,elemIndex;
  cin>>nTest;
  for(int test=1;test<=nTest;test++) {
    cin>>index;

    sum=2;
    nelem=1;

    while(nelem<index) {
      sum++;
      nelem+=(sum-1);
    }

    if((sum%2)==0) {
      col=0;
      row=sum;

      elemIndex=index-(nelem-(sum-1));

      for(int i=1;i<=elemIndex;i++) {
	col++;
	row--;
      }
    }
    else {
      row=0;
      col=sum;

      elemIndex=index-(nelem-(sum-1));

      for(int i=1;i<=elemIndex;i++) {
	row++;
	col--;
      }
    }

    cout<<"TERM "<<index<<" IS "<<row<<"/"<<col<<endl;
  }
  return 0;
}
