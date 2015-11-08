#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int countBSearch(int key, vector<int>& aray) {
  int low=0,high=aray.size()-1,mid;
  bool flag=false;
  while(low<=high) {
    mid=(low+high)>>1;
    if(aray[mid]==key){
      flag=true;
      break;
    }
    if(key<aray[mid])
      high=mid-1;
    else
      low=mid+1;
  }
  int count=0;
  if(flag) {
    while((mid>=0)&&(aray[mid]==key))
      mid--;
    mid++;
    while(aray[mid]==key&&mid<aray.size()) {
      mid++;
      count++;
    }
    return count;
  }
  return 0;
}

int main() {
  vector<int> A,B,C,D;
  vector<int> sumAB;
  vector<int> sumCD;
  int n,a,b,c,d;
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%d%d%d%d",&a,&b,&c,&d);
    A.push_back(a);
    B.push_back(b);
    C.push_back(c);
    D.push_back(d);
  }

  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      sumAB.push_back(A[i]+B[j]);
      sumCD.push_back(C[i]+D[j]);
    }
  }

  unsigned long long int count=0;
  sort(sumCD.begin(),sumCD.end());
  for(int i=0;i<sumAB.size();i++) {
    count+=countBSearch(-1*sumAB[i],sumCD);
  }
  printf("%llu\n",count);
  return 0;
  
}
