#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
  int e,f,s,m,ec,fc,sc,mc,er,fr,sr,mr;
  int maxCakes,temp;

  scanf("%d%d%d%d%d%d%d%d",&e,&f,&s,&m,&ec,&fc,&sc,&mc);
  while(e!=-1) {
    maxCakes=e/ec;
    if(e%ec!=0)
      maxCakes++;
    temp=f/fc;
    if(f%fc!=0)
      temp++;
    if(temp>maxCakes)
      maxCakes=temp;
    temp=s/sc;
    if(s%sc!=0)
      temp++;
    if(temp>maxCakes)
      maxCakes=temp;
    temp=m/mc;
    if(m%mc!=0)
      temp++;
    if(temp>maxCakes)
      maxCakes=temp;
    er=fr=sr=mr=0;
    temp=e/ec;
    er=(maxCakes-temp)*ec-(e%ec);
    temp=f/fc;
    fr=(maxCakes-temp)*fc-(f%fc);
    temp=s/sc;
    sr=(maxCakes-temp)*sc-(s%sc);
    temp=m/mc;
    mr=(maxCakes-temp)*mc-(m%mc);
    printf("%d %d %d %d\n",er,fr,sr,mr);
    scanf("%d%d%d%d%d%d%d%d",&e,&f,&s,&m,&ec,&fc,&sc,&mc);
  }
  return 0;
}
