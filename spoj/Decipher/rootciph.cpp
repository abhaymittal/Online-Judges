#include<cstdio>
typedef long long ll;

using namespace std;

int main() {
  int nTest,exp;
  ll a,b,c;
  scanf("%d",&nTest);
  for(int t=1;t<=nTest;t++) {
    scanf("%lld%lld%lld",&a,&b,&c);
    printf("%lld\n",a*a-2*b);
  }
  return 0;
}
