//Question : Find an array from the given 1's and 0's where all the 1's are on the right and all the 0's are on the left?

//The highlight is that the time complexity of the program is : O(n).


#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void arrayPrinter(vector <int> array){
    for(int i = 0 ; i< array.size() ; i++){
        cout<<"  "<<array[i];
    }
}

void A (vector <int> array){                  //The function which performs all the operations and then prints the final array .
     cout<<"\nThe initial array is : ";
     arrayPrinter(array);
     int j = array.size()-1;
     for(int i =0 ; i<array.size() ; i++){
       if(i<array.size()/2){
            if(array[i]==1&& array[j]==0){
                swap(array[i], array[j]);
            }
            else if( array[j]==0){
                swap(array[j],array[j-1]);
            }
            else if( array[i]==1){
                swap(array[i],array[i+1]);
            }   
       }
       j--;
     }
     cout<<"\nThe changed array is : ";
     arrayPrinter(array);
}

int main(){
    clock_t start , end ;
    start = clock();

    vector <int> array = {0,0,1,1,0,0,0,1,1,0,1,1,1,0,0,0,1,1,0,1,1,0,1,0,1};

    A(array);

    end = clock();
    cout<<"\nThe time taken to run the program is : "<<end - start<<" ms";
    return 0 ;
}