#include<cstdio>
#include<string>
#include<set>
#define MAX 1001

using namespace std;

int main() {
  string str;
  int nTest,npos;
  char in[MAX];
  set<string> dist;

  scanf("%d",&nTest);
  for(int t=1;t<=nTest;t++) {
    dist.clear();

    scanf("%s",in);
    str.assign(in);

    for(int i=0;i<str.length();i++) {
      for(int j=i;j<str.length();j++) {
	npos=j-i+1;
	dist.insert(str.substr(i,npos));
      }
    }

    printf("%lu\n",dist.size());
  }
  return 0;
}
