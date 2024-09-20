//Valid Parentheses with Multiple Types
#include<iostream>
#include<stack>
using namespace std;
int main(){
    string str;
    cin>>str;
    stack<char> st;
    for(char a:str){
        if(a=='{' || a=='[' || a=='('){
            st.push(a);
        }
        else{
            if((st.top()=='[' && a==']')||(st.top()=='{' && a=='}')||(st.top()=='(' && a==')')){
                st.pop();
            }
            else break;
        }
        
    }
    
    if(st.empty()) cout<<"true";
    else cout<<"false";
    return 0;
}
