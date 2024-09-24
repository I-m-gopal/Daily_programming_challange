//Calculate the LCM of two numbers

#include<iostream>
using namespace std;

int main(){
    long int a,b;
    cin>>a>>b;
    long int c = a;
    long int d = b;
    while(b!=0){
        long int tmp = b;
        b = a%b;
        a = tmp;
    }
    cout<<"LCM is: "<<(c*d)/a;
    return 0;
}
