#include<cstdio>
#include<algorithm>
#define F(x,y) for(x=1;x<=y;x++)
#define S(x) scanf("%d",&x)
main(){int a[101][101],t,n,x,l,i,j,k;
S(t);F(i,t){S(n);l=0;
F(j,n)F(k,j){S(x);a[j][k]=std::max(a[j-1][k],a[j-1][k-1])+x;l=std::max(l,a[j][k]);}
printf("%d\n",l);}
}
