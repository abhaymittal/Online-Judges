//PROBLEM CODE: PT07Y

#include<iostream>
using namespace std;

void mergeSet(int a,int b, int V,int* representative, int* length);
int main() {
  int V,E,u,v;

  cin>>V>>E;

  int representative[V];
  int length[V];

  for(int i=0;i<V;i++) {
    representative[i]=i;
    length[i]=1;
  }

  for(int i=0;i<E;i++) {
    cin>>u>>v;

    if(representative[u-1]==representative[v-1]) {
      cout<<"NO";
      return 0;
    }

    mergeSet(u-1,v-1,V,representative,length);
  }
  //counting number of connected components; it should be one
  int count=0;
  for(int i=0;i<V;i++) {
    if(length[i]!=0)
      count++;
  }
  if(count>1)
    cout<<"NO";
  else  
    cout<<"YES";
  return 0;
}


void mergeSet(int a,int b, int V,int* representative, int* length) {
  if(length[representative[a]]>length[representative[b]]) {
    length[representative[a]]+=length[representative[b]];

    int old_rep=representative[b];
    for(int i=0;i<V;i++) {
      if(representative[i]==old_rep) {
	representative[i]=representative[a];
      }
    }
    length[old_rep]=0;
  }
  else {
    length[representative[b]]+=length[representative[a]];

    int old_rep=representative[a];
    for(int i=0;i<V;i++) {
      if(representative[i]==old_rep) {
	representative[i]=representative[b];
      }
    }
    length[old_rep]=0;   
  }
}
