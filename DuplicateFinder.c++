/*Question - There is an array of n numbers from 1 to n-1 in which one is repeated . SO find out that repeated element?*/

#include <iostream>
#include <cmath>

using namespace std;

void DuplicateFinder(int array[] , int size){
    int ans = 0 ;
    for(int i = 0 ; i<size ; i++){
        ans = ans^array[i];                     //Taking thr XOR of value of ans with the current array element .
    }
    cout<<endl<<"The answer is : "<<ans<<endl<<endl;
}

int main(){
    int array[4]={1,2,3,3};
    int size = sizeof(array)/4;
    DuplicateFinder(array , size);
    return 0;
}