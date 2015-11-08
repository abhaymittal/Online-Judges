#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;

int main() {
  int nTest,N;
  scanf("%d",&nTest);
  for(int t=1;t<=nTest;t++) {
    scanf("%d",&N);
    printf("%d\n",N/2+N%2);
  }
  return 0;
}
