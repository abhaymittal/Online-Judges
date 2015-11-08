#include<cstdio>
#include<algorithm>
#define F(x,z,y) for(x=z;x<y;x++)
#define SI(x) scanf("%d",&x)
int main() {int a[101][101],t,n,tp,mx,i,j,k;
SI(t);
F(i,0,t){SI(n);
F(j,0,n){if(!j){SI(a[0][0]);
continue;}
SI(tp);a[j][0]=a[j-1][0]+tp;
F(k,1,j){SI(tp);a[j][k]=std::max(a[j-1][k],a[j-1][k-1])+tp;}
SI(tp);a[j][j]=a[j-1][j-1]+tp;}
mx=0;F(j,0,n){mx=std::max(mx,a[n-1][j]);}
printf("%d\n",mx);}
return 0;
}
