//5. Write a program for the evaluation of a Postfix expression.
//for single digit numbers
#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

bool isOperator(char c){
  if(c == '^' || c == '+' || c == '-' || c == '*' || c == '/'){
    return true;
  }
  else{
    return false;
  }
}

int applyCal(int a, int b, char op){
  switch(op){
    case '+' : return a+b;
    case '-' : return a-b;
    case '*' : return a*b;
    case '^' : return pow(a,b);
    case '/' : if( b == 0){
      cout<<"Invalid Expression!";
      return INT_MAX;
    }
    else{
      return a/b;
    }
  }
}

void evaluatePostfix(string s){
  bool flag = true;
  int n = s.size();
  int i=0;
  stack<int> st;
  while(i < n){
    if(isOperator(s[i])){
      if (st.size() < 2) {
        cout << "Error: Invalid postfix expression (not enough operands)\n"; 
        flag = false;
        break;
      }
      else{
        if(st.top() == INT_MAX){
          flag = false;
          break;
        }
        int b = st.top(); st.pop();
        int a = st.top(); st.pop();
        st.push(applyCal(a,b,s[i]));
      }
      
    }
    else if(isdigit(s[i])){
      st.push(s[i] - '0');
    }
    else if(s[i] == ' '){
      continue;
    }
    else{
      cout<<"Invalid expression";
      flag = false;
      break;
    }
    i++;
  }
  if(flag && st.size() == 1){
    cout<<st.top();
  }
}

int main(){
  string s = "1234^5-*+";
  evaluatePostfix(s);
  return 0;
}