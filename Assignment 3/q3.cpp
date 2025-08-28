//Write a program that checks if an expression has balanced parentheses.

#include<iostream>
using namespace std;

int main(){
  string s;
  cout<<"Enter matematical expression : ";
  getline(cin,s);
  stack<char> st;
  int len = s.length();
  bool  b = true;
  for(int i=0; i<len; i++){
    if(s[i] == '(' || s[i] == '[' || s[i] == '{' ){
      st.push(s[i]);
    }
    else if(s[i] == ')'){
      if(!st.empty() && st.top() == '('){
        st.pop();
      }
      else{
        b = false;
        break;
      }
    }
    else if(s[i] == '}'){
      if(!st.empty() && st.top() == '{'){
        st.pop();
      }
      else{
        b = false;
        break;
      }
    }
    else if(s[i] == ']'){
      if(!st.empty() && st.top() == '['){
        st.pop();
      }
      else{
        b = false;
        break;
      }
    }
  }
  if(!st.empty()){
    b = false;
  }
  if(b){ 
    cout<<"It is valid ! ";
  }
  else{
    cout<<"It is invalid ! ";
  }
  return 0;
}