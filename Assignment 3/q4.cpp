//4. Write a program to convert an Infix expression into a Postfix expression.
#include<iostream>
using namespace std;

int priority(char op){
  if(op == '^'){
    return 3;
  }
  if(op == '*' || op == '/'){
    return 2;
  }
  if(op == '+' || op == '-'){
    return 1;
  }
  return 0;
}

string infixToPostfix(string s){
  string ans = "";
  int n = s.size();
  int i = 0;
  stack<char> st;

  while(i < n){
    if((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
      ans = ans + s[i];
    }
    else if(s[i] == '('){
      st.push(s[i]);
    }
    else if(s[i] == ')'){
      while(!st.empty() && st.top() != '('){
        ans += st.top();
        st.pop();
      }
      st.pop(); //to pop (
    }
    else{//operators
      while(!st.empty() && priority(s[i]) <= priority(st.top())){
        ans += st.top();
        st.pop();
      }
      st.push(s[i]);
    }
    i++;
  }

  while(!st.empty()){
    s = s + st.top();
    st.pop();
  }
  return ans;
}

int main(){
  string s = "a+b*(c^d-e)";
  cout<<"Postfix expression of "<<s<<" is "<<infixToPostfix(s);
  return 0;
}