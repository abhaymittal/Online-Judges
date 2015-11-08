#include<cstdio>
#include<iterator>
#include<set>
using namespace std;

int abs(int x) {
  if(x>0)
    return x;
  return -x;
}

int main() {
  int nTest,n1,n2,a1[1000],a2[1000],min=1<<30;
  set<int> myset;
  set<int>::iterator it,it2;
  scanf("%d",&nTest);

  for(int t=1;t<=nTest;t++) {
    min=1<<30;
    myset.clear();
    scanf("%d",&n1);
    for(int i=0;i<n1;i++)
      scanf("%d",&a1[i]);
    scanf("%d",&n2);
    for(int i=0;i<n2;i++)
      scanf("%d",&a2[i]);
    if(n1>n2) {
      for(int i=0;i<n1;i++)
	myset.insert(a1[i]);
      for(int i=0;i<n2;i++) {
	it=myset.upper_bound(a2[i]);
	if((it!=myset.end())&(abs((*it)-a2[i])<min))
	  min=abs((*it)-a2[i]);
	it2=it;
	it2--;
	if((it!=myset.begin())&&(abs((*(it2))-a2[i])<min))
	  min=abs((*(it2))-a2[i]);
      }
    }
    else {
      for(int i=0;i<n2;i++)
	myset.insert(a2[i]);
      for(int i=0;i<n1;i++) {
	it=myset.upper_bound(a1[i]);
	if((it!=myset.end())&&(abs((*it)-a1[i])<min))
	  min=abs((*it)-a1[i]);
	it2=it;
	it2--;
	if((it!=myset.begin())&&(abs((*(it2))-a1[i])<min))
	  min=abs((*(it2))-a1[i]);
      }
    }
    printf("%d\n",min);
  }
  return 0;
}
