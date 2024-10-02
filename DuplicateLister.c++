/*Question - There is an array of integers given . Find out the list of repeated elements and number of times they are repeated?*/
#include <iostream>
#include <vector>
#include <time.h>
int MIN = INT32_MIN;

using namespace std;

//USE OF VECTOR ARRAYS IS NOT COMPULSORY AT ALL.YOU CAN USE ARRAYS . BELOW FUNCTIONS ARE HELPFUL . YOU JUST NEED TO REPLACE VECTOR INPUT TO FUNCTION BY ARRAY AS INPUT AND MAKE SOME ADJUSTMENTS.

void arrayCopy(vector <int> array,int copyArray[] ,int size ){
        for(int i = 0 ; i<size ; i++){
                copyArray[i] = array[i];
        }
}

void  duplicate(vector <int> array , int size){

        //Declaring the variables and a copied array.
        int ans = 0 ;
        int counter = 0 ;
        int sol[size] = {};
        arrayCopy(array , sol , size);

        //Travesing the for loop in order to go for each element
        for(int i = 0 ; i< size ; i++){
                ans = array[i];
                
                //Traversing through the second loop in order to compare the above selected element with each element of the array.
                for(int j = 0 ; j<size ; j++){
                        
                        if(ans==array[j] && ans != MIN){
                                 counter++;
                                 //Setting the variable which is counted to MIN so that it do not gets counted again.
                                 //If You want to store those numbers which are occuring more than 1 time or repeating you can make make a vector and use vector.push_back(array[i]) here and store the array.
                                 array[j]=MIN;
                        }

                }

                //Printing out the element with the number of counts if the number comes more than 1 times .
                if(counter>1 && sol[i]!=MIN){
                                
                                cout<<endl<<"The element "<<sol[i]<<" comes"<<"--> "<<counter<<" times in the array.";
                                
                        }

                //Resetting the counter again to 0 for the next(i+1) element.
                counter=0;

                //Setting the sol array elemenet to MIN  . The sole purpose of this array was to be able to print the count number .
                sol[i]= MIN;

        }

}

int main(){
    clock_t start, end;


    start = clock();
    vector <int> arr = {0,2,5,2,5,9,8,8,0,7,7,3,5,8,9};  
    
    //This can be taken as an array also but you will have to change at the size variable as the arrays do not have the size attribute.
    
    int size = arr.size();
    duplicate(arr,size);


    end = clock();
    cout<<endl<<endl<<"Time taken is : "<<end-start<<" ms"<<endl<<endl;
    return 0 ; 
}