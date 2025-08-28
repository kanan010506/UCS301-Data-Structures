//Given a string, reverse it using STACK. For example “DataStructure” should be output as
//“erutcurtSataD.”

#include<iostream>
using namespace std;

int main(){
  string s = "DataStructure";
  stack<char> st;
  
  int len = s.length();
  for(int i=0; i<len;i++){
    st.push(s[i]);
  }
  string ans;
  while(!st.empty()){
    ans = ans + st.top();
    st.pop();
  }
  cout<<ans;
  return 0;
}