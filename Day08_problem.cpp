//Reverse string word by word

#include<iostream>
#include<string>
using namespace std;
string reverse_str(string s){
    int n = s.size();
    int i=0;
    int j = 0;
    string result;
    while(i<n){
        while(i<n && s[i]==' ') i++;
        if(i>=n) break;
        j = i+1;
        while(j<n && s[j] != ' ') j++;
        string sub = s.substr(i, j-i);
        if(result.size()==0) result = sub;
        else result = sub+" "+result;
        i = j+1;
    }
    return result;
}

int main(){
    string s;
    getline(cin,s);
    cout<<reverse_str(s);
    return 0;
}
