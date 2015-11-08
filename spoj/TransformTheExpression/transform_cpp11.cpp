/**
 * Transform the algebraic expression with brackets into RPN form (Reverse Polish Notation, Postfix).
 * Two-argument operators: +, -, *, /, ^ (priority from the lowest to the highest), brackets ( ).
 * Operands: only letters: a,b,...,z. Assume that there is only one RPN form (no expressions like a*b*c). 
 * PROBLEM CODE : ONP
 */


#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {

  stack<char,vector<char> > st; // stack to store the operators

  string expr; // the expression string
  string outExpr="";

  int nTest;
  char ch,temp;

  cin>>nTest;

  for(int test=1;test<=nTest;test++) {
    cin>>expr; //read the expression in infix form
    expr+=")";
    st.push('(');
    outExpr="";

    
    while(!st.empty()) {
      ch=expr.front();

      switch(ch) {
      case '+':
      case '-':
	while(st.top()!='(') {
	  outExpr.push_back(st.top());
	  st.pop();
	}
	st.push(ch);
	break;
	
      case '/':
      case '*':
	while((st.top()=='/') || (st.top()=='*') || (st.top()=='^')) {
	  outExpr.push_back(st.top());
	  st.pop();
	}
	st.push(ch);
	break;

      case '^':
	while(st.top()=='^') {
	  outExpr.push_back(st.top());
	  st.pop();
	}
	st.push(ch);
	break;

      case '(':
	st.push(ch);
	break;

      case ')':
	while(st.top()!='(') {
	  outExpr.push_back(st.top());
	  st.pop();
	}
	st.pop();
	break;

      default:
	outExpr.push_back(ch);
      }

      expr.erase(0,1);
    }

    
    cout<<outExpr<<endl;    
  }

  return 0;
}
