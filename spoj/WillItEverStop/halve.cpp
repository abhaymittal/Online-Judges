string halve(string num) {
  int rem=0;
  int n;
  int dividend;
  string quot="";
  for(int index=0;index<num.length();index++) {
    n=num.at(index)-48;
    dividend=rem*10+n;
    rem=dividend%2;
    quot=quot+string(1,(dividend/2)+48);
  }

  while((quot.length()!=1)&&(quot.at(0)=='0'))
    quot.erase(0,1);
  return quot;
}
