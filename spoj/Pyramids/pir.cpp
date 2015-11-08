#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int main() {
  int nTest;
  double u,v,w,U,V,W;
  long long x,y,z,X,Y,Z;
  double a,b,c,d,vol;

  scanf("%d",&nTest);
  for(int i=0;i<nTest;i++) {
    scanf("%lf%lf%lf%lf%lf%lf",&u,&v,&w,&W,&V,&U);
    X=(w-U+v)*(U+v+w);
    x=(U-v+w)*(v-w+U);
    Y=(u-V+w)*(u+V+w);
    y=(V-w+u)*(w-u+V);
    Z=(v-W+u)*(W+u+v);
    z=(W-u+v)*(u-v+W);
    a=sqrt(x*Y*Z);
    b=sqrt(y*Z*X);
    c=sqrt(z*X*Y);
    d=sqrt(x*y*z);
    vol=(sqrt(-a+b+c+d)*sqrt(a-b+c+d)*sqrt(a+b-c+d)*sqrt(a+b+c-d))/(192*u*v*w);
    printf("%.4lf\n",vol);
  }
}


