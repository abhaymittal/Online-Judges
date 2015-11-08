#include<cstdio>
#include<climits>

int main() {
  int A, D, atkMin=INT_MAX, defMin1=INT_MAX, defMin2=INT_MAX,temp;

  scanf("%d%d",&A,&D);
  while(A!=0) {
    atkMin=INT_MAX;
    defMin1=INT_MAX;
    defMin2=INT_MAX;
    
    for(int i=0;i<A;i++) {
      scanf("%d",&temp);
      if(temp<atkMin)
	atkMin=temp;
    }

    for(int i=0;i<D;i++) {
      scanf("%d",&temp);
      if(temp<=defMin1) {
	defMin2=defMin1;
	defMin1=temp;
      }
      else if (temp<defMin2) {
	defMin2=temp;
      }
    }

    if((atkMin<defMin1)||(atkMin<defMin2))
      printf("Y\n");
    else
      printf("N\n");
    scanf("%d%d",&A,&D);
  }
  return 0;
}
