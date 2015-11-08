#include<iostream>
#include<string>
#include<cstdlib>
#define rep(n) for(int i=0;i<n;i++)


using namespace std;

int main() {
  int nTest,op1,op2,out;
  string temp;

  cin>>nTest;
  for(int test=1;test<=nTest;test++) {
    cin>>temp;
    if(temp.find("machula")==string::npos)
      op1=atoi(temp.c_str());
    else
      op1=-1;
    cin.ignore(10,'+');
    cin>>temp;
    if(temp.find("machula")==string::npos)
      op2=atoi(temp.c_str());
    else
      op2=-1;
    cin.ignore(10,'=');
    cin>>temp;
    if(temp.find("machula")==string::npos)
      out=atoi(temp.c_str());
    else
      out=-1;

    if(op1==-1) {
      op1=out-op2;
    }
    if(op2==-1)
      op2=out-op1;
    if(out==-1)
      out=op1+op2;

    cout<<op1<<" + "<<op2<<" = "<<out<<endl;
  }
  return 0;
}
