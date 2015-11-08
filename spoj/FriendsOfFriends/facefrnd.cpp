#include<cstdio>
#include<set>

using namespace std;

int main() {
  int N,M,id;
  scanf("%d",&N);
  set<int> frndOfFrnd;
  set<int> frnd;
  set<int>::iterator it,it2;
  for(int i=0;i<N;i++) {
    scanf("%d",&id);
    frnd.insert(id);
    scanf("%d",&M);
    for(int j=0;j<M;j++) {
      scanf("%d",&id);
      frndOfFrnd.insert(id);
    }
  }
  for(it=frnd.begin();it!=frnd.end();it++) {
    it2=frndOfFrnd.find(*it);
    if(it2!=frndOfFrnd.end())
      frndOfFrnd.erase(it2);
  }
  printf("%lu\n",frndOfFrnd.size());
  return 0;
}
