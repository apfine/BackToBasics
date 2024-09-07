#include <iostream>
#include <cmath>

using namespace std;

class solution{
    public:
        int reverseX(int num){
            int j = 0;
            int newNum = 0;
            int numLoop2 = num;
            int numLoop = num;
            
            
            while(numLoop!=0){
                
                numLoop = numLoop /10;
                
                j = j+1;
                
            }
            
            int i = 1; 
            
            for(int p=1 ; p<j ; p++){
                i = i*10;
            }
            
            while(i != 0){
            
                int b = numLoop2%10;
                
                newNum = (i * b) +newNum;
                
                i = i/10 ;
                numLoop2 /= 10;
                
 
            }

            cout<<"Going to write the reversed number"<<"\t"<<newNum;
            return 0 ;
        }
};

int main(){
    int n ;
    cout<<"Please enter the number you want to reverse -:";
    cin>>n;
    solution a ;
    a.reverseX(n);
    return 0 ;
}