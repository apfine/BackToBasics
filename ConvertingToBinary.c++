#include <iostream>
#include <math.h>

using namespace std;

int converter(int num){
    int i =0 ;
    int ans =0;
    int mul = 1;
    
    while(num!=0){
        int bit = num & 1;
        num = num >> 1;

        ans = ans + mul*bit;
        mul*=10;
    }
    // cout<<ans<<endl;   //I wrote these statements to test some bugs.
    return ans;
}

void converterNegative(int num){
    int ans = converter(num);
    int ab = 0;
    int j = 0;
    cout<<ans<<endl;
    
    
   while(ans!=0){
        int b = ans% 10;
        // cout <<b<<endl;
        if(b==1){
          ab =  pow(2,j)+ab;

        }else{
           ;
        }
        // cout<<j<<endl;
        ans = ans / 10;
        j++;
    }
    num = ab+1;
    converter(num);
}

int main(){
    cout<<"Please enter the number , I will convert it to binary for you->";
    int n;
    cin>>n;
    
    if(n>0){
        cout<<converter(n);
        
    }else{
        n= n*(-1);
        converterNegative(n);
    }
    return 0 ;
}
