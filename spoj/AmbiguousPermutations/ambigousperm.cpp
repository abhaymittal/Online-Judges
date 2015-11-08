#include<iostream>

using namespace std;

int main() {
  int nelem, *inper, *outper;
  bool flag=true;

  cin>>nelem;
  while(nelem!=0) {
    inper=new int[nelem];
    outper=new int[nelem];

    for(int i=0;i<nelem;i++) {
      cin>>inper[i];
    }

    for(int i=0;i<nelem;i++) {
      outper[inper[i]-1]=i+1;
    }
    flag=true;
    for(int i=0;i<nelem;i++) {
      if(inper[i]!=outper[i]) {
	flag=false;
	break;
      }
    }

    if(flag)
      cout<<"ambiguous"<<endl;
    else
      cout<<"not ambiguous"<<endl;

    delete[] inper;
    delete[] outper;
    cin>>nelem;
  }

  return 0;
}
