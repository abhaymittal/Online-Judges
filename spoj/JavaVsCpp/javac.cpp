#include<iostream>
#include<cstdio>

using namespace std;

int checkLang(char *id);
int convertJava(char *id, char *outId);
int convertCpp(char *id, char *outId);

int main() {

  char id[101],outId[202];
  int inLength,lang;
  char ch;

  while(scanf("%s",id)!=EOF) {
    lang=checkLang(id);
    if(lang==0)
      cout<<"Error!"<<endl;
    else if (lang==1)
      convertJava(id,outId);
    else
      convertCpp(id,outId);
    if(lang!=0)
      cout<<outId<<endl;
  }
  return 0;
}

int checkLang(char *id) {
  int i;
  int flag=3;
  if(!(((id[0]>='a')&&(id[0]<='z'))||(id[0]=='_')||((id[0]>='A')&&(id[0]<='Z'))))
    return 0;
  if((id[0]=='_')||(id[0]!=tolower(id[0])))
    return 0;
  for(i=0;id[i]!=0;i++) {
    if((id[i]>='a')&&(id[i]<='z'))
      continue;
    else if(id[i]=='_') {
      if(flag==2)
	return 0;
      if((id[i+1]=='\0')||(id[i+1]=='_'))
	return 0;
      else {
	flag=1;
      }
    }
    else if((id[i]>='A')&&(id[i]<='Z')) {
      if(flag==1)
	return 0;
      flag=2;
    }
    else
      return 0;
  }

  return flag;
}

int convertJava(char *id, char *outId) {
  int i=0,j=0;
  for(;id[i]!='\0';i++) {
    if(id[i]=='_') {
      i++;
      outId[j++]=toupper(id[i]);
    }
    else
      outId[j++]=id[i];
  }
  outId[j++]='\0';
  return j;
}

int convertCpp(char *id,char *outId) {
  int i=0,j=0;
  for(;id[i]!='\0';i++) {
    if(id[i]!=tolower(id[i])){
      outId[j++]='_';
      outId[j++]=tolower(id[i]);
    }
    else
      outId[j++]=tolower(id[i]);
  }
  outId[j++]='\0';
  return j;
}

