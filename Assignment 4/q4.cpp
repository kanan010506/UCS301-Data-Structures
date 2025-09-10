//Write a program to find first non-repeating character in a string using Queue. Sample I/P: a ab c Sample O/P: a -1 b b

#include<iostream>
using namespace std;

class nonRepeating{
  private :
  string s;
  string ans;
  int freq[26] = {0};
  queue<char> q;
  public :
  nonRepeating(){
    cout<<"Enter string which comprises of only small english alphabets : ";
    cin>>s;
  }
  void check(){
    for(int i=0; i<s.length(); i++){
      freq[s[i] - 'a'] ++;
      q.push(s[i]);
      while(!q.empty() && freq[q.front() - 'a'] >1){
        q.pop();
      }
      if(q.empty()){
        ans += "-1";
      }
      else{
        ans += q.front();
      }
    }
    cout<<"Answer : "<<ans<<endl;
  }
};

int main(){
  nonRepeating obj;
  obj.check();

  return 0;
}