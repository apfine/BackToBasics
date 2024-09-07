#include <iostream>
#include <cmath>

using namespace std;

void primeCheck(int num){
    int count= 0;
    for(int i = 2 ; i< 8 ; i++ ){
        int q = num%i;
        count++;}
    if(count==0){cout<<"The number is a prime number.";}
    else{cout<<"The number is not a prime number.";}
}
int main(){
    int n ; 
    cout<<"Please enter the number you want to check ->";
    cin>>n;
    primeCheck(n);
    return 0 ; 

}