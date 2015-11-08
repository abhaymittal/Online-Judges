#include<cstdio>
#include<set>

using namespace std;

int main() {

  int N;
  int pyaniId;
  int answer=0;
  scanf("%d",&N);
  for(int i=0;i<N;i++) {
    scanf("%d",&pyaniId);
    answer=answer^pyaniId;
  }
  printf("%d\n",answer);
  return 0;
}
