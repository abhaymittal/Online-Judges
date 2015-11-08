#include<iostream>
using namespace std;
#define F(x,y) for(x=1;x<=y;x++)
int main(){int a[101][101],t,n,x,l,i,j,k;cin>>t;F(i,t){cin>>n;l=0;F(j,n)F(k,j){cin>>x;a[j][k]=max(a[j-1][k],a[j-1][k-1])+x;l=max(l,a[j][k]);}cout<<l<<endl;} return 0;}
