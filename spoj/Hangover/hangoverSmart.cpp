#include<iostream>
#include<cmath>

using namespace std;

//Took help from the following URL: http://math.stackexchange.com/questions/101371/finding-how-many-terms-of-the-harmonic-series-must-be-summed-to-exceed-x

//This method produces wrong answer for 0.5 as it always produces the value greater than sum not greater than equal to sum.

int main() {
  double sum;
  double gamma=0.577215664901532860L;
  cin>>sum;
  while(sum!=0.00L) {
    sum+=1;
    cout<<static_cast<int>(exp(sum-gamma)-0.5L)<<endl;
    cin>>sum;
  }
  return 0;
}
