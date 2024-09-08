#include <iostream>
#include <cmath>

using namespace std;

void arrayPrinter(int arr[] , int size ){
  for(int j = 0; j <size ; j++){
    cout<<arr[j]<<' ';
  }
  cout<<"Done";
}

int ArrayReverse(int arre[], int size){
  int ReversedArray[size]={0};
  int j = 0;
  
  for(int i = (size-1) ; i>=0 ; i--){
     ReversedArray[j] = arre[i];
     j = j+1;
  }
  arrayPrinter(ReversedArray,size);
  
  return 0 ;
}



int main(){
 int array[5] = {89,56,78,56,23};
 int size = (sizeof(array)/4);
 ArrayReverse (array , size);
 return 0 ;
}