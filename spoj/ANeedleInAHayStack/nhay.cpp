#include<cstdio>

void computePreTable(char *pat, int patLen, int *pTable) {
  int len=0;
  pTable[0]=0;
  for(int i=1;i<patLen;) {
    if(pat[len]==pat[i]) {
      len++;
      pTable[i]=len;
      i++;
    }
    else {
      if(len!=0) {
	len=pTable[len-1];
      }
      else {
	pTable[i]=len;
	i++;
      }
    }
  }
}

int main() {
  char *pat, ch;
  int *pTable;
  int patLen,pos,index,temp;
  bool flag;
  while(!feof(stdin)) {
    scanf("%d",&patLen);
    pat=new char[patLen+1];
    pTable=new int[patLen+1];
    scanf("%s",pat);
    getchar();
    computePreTable(pat,patLen,pTable);
    pos=0;index=0;
    ch=getchar();
    while((ch!='\n')&&(ch!=EOF)) {
      if(ch==pat[pos]) {
	pos++;
	ch=getchar();
	index++;
	if(pos==patLen) {
	  printf("%d\n",index-pos);
	  pos=pTable[pos-1];
	}
      }
      else {
	if(pos!=0)
	  pos=pTable[pos-1];
	else {
	  ch=getchar();
	  index++;
	}
      }
    }
    delete[] pat;
    delete[] pTable;
     if(ch!=EOF)
      printf("\n");
  }
  return 0;
}
