#include <iostream>
#include <cmath>


using namespace std;

void ArrayPrinter(int array[] , int size){
      for(int i = 0 ; i<size ; i++){
         cout<<array[i]<<" ";
      }
      cout<<endl;
}


void ArrayExchange(int array[] , int initial , int next , int size){
      int CopiedArray[size] ={};
      for(int i = 0 ; i <size ; i++){
         CopiedArray[i] = array[i];
      }
      
      array[initial] = CopiedArray[next];
      array[next]    = CopiedArray[initial];  
      
      /*These two lines could have been in one line in case of python 
      and we would have not been required to copy the array , Elements would have been exchanged 
      automatically in one statement ,
      but here if we do so no change is seen in the array. 
      
      -->IN python arrays are implemented through lists. */
      
      
      ArrayPrinter(array , size);
}

int main(){
    int array[5] = {54,78,34,43,23};
    int size = sizeof(array)/4;
    int initial;
    int next;
    cout<<"Please enter the indices you want to exchange each other with.  [ 0    t o    4    o n l y ]"<<endl;
    cin>>initial;
    cin>>next;
    cout<<"Initially your array is this -:";
    ArrayPrinter(array , size);
    cout<<endl<<"Finally , after exchange Your array is this -:";
    ArrayExchange(array , initial , next , size);cout<<endl;
    return 0 ;
}
