#include<bits/stdc++.h>
using namespace std;
string removek(string s,int k){
    
    
    deque<char>st;
    for(int i=0;i<s.length()-1 && st.size()!=s.length()-k;i++){
        
        if(s[i]-'0'<=s[i+1]-'0'){
            st.push_back(s[i]);
        }
        else{
            
        }
    }
    string ans="";
    for(int i=0;i<s.length()-k;i++){
        ans+=st.front();
        
        st.pop_front();
    }
    return ans;

}

int main(){
        string s;
        cin>>s;
        int k;
        cin>>k;
        cout<<removek(s,k);


  return 0;
}