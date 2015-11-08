#include<cstdio>
#include<map>

using namespace std;

int main() {
  int nTest,n,temp;
  bool flag;
  map<int,int> freqMap;
  map<int,int>::iterator it;
  scanf("%d",&nTest);

  for(int t=1;t<=nTest;t++) {
    flag=false;
    freqMap.clear();
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
      scanf("%d",&temp);
      freqMap[temp]++;
    }
    for(it= freqMap.begin();it!=freqMap.end();it++) {
      if(it->second>n/2) {
	flag=true;
	printf("YES %d\n",it->first);
	break;
      }
    }

    if(!flag)
      printf("NO\n");
  }
  return 0;
}
