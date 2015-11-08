/**
 * Program to find prime numbers between two given numbers
 * Problem Code PRIME1
 */

//Took help from : http://turjachaudhuri.wordpress.com/2013/12/14/spoj-prime-1-segmented-sieve-of-eratosthenes/

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main() {
  int nTest;
  int range1, range2;
  bool *sieve;
  int max;
  cin>>nTest;
  vector<int> primeList;

  for(int test=1;test<=nTest;test++) {
    cin>>range1;
    cin>>range2;

    primeList.clear();

    max=(range1>range2)?range1:range2;
    int nelem=sqrt(max);
    if((max%nelem)!=0)
      nelem=sqrt(max)+1;
    
    sieve=new bool[nelem-1];
    for(int i=0;i<nelem-1;i++)
      sieve[i]=false;

    for(int i=0;i<nelem-1;i++) {
      if(sieve[i])
	continue;

      primeList.push_back(i+2);
      for(int j=2*(i+2);j<=nelem;j+=(i+2)) {
	sieve[j-2]=true;
      }
    }
    delete sieve;
    sieve=new bool[range2-range1+1];

    for(int i=0;i<range2-range1+1;i++)
      sieve[i]=false;

    if(range1==1)
      sieve[0]=true;
    
    for(vector<int>::iterator itr=primeList.begin();itr!=primeList.end();itr++) {
      for(int j=range1-(range1%(*itr));j<=range2;j+=(*itr)) {
	if(j<range1)
	  continue;
	if(j!=*itr)
	  sieve[j-range1]=true;
      }
    }

    for(int i=0;i<range2-range1+1;i++) {
      if((!sieve[i]))
	cout<<i+range1<<endl;
    }
    cout<<endl;
				      
    delete sieve;
  }
}
