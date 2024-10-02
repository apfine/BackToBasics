/*QUESTION - Find out a mathematically correct union of the two given sets ?*/

#include <iostream>
#include <ctime>
#include <vector>


int DEF = INT32_MIN;

using namespace std;



//Function to print an array.
void arrayPrinter(vector <int> array ){
    for(int i = 0 ; i< array.size() ; i++){
        if(!(array[i]==DEF)){               //Skipping the elements which are already taken in the the intersection set.
            cout<<"\t"<<array[i];
        }
    }
}


//Function to sort an array in ascending order.
void arraySort(vector <int> array ){
        vector <int> sortedArray ; 
        for(int i =0 ; i< array.size() ; i++){
            int p = array[i];           //Storing the values of i and i+1 elements in order to swap them if the condition is satisfied.
            int s = array[i+1];

            if(array[i+1]<array[i]){
                array[i+1]= s;
                array[i] = p ; 

            }

        }
}


//Removing the duplicate elements from the array.
void duplicateRemover(vector<int>& array) {
    for (int i = 0; i < array.size(); i++) {
        for (int j = i + 1; j < array.size(); j++) {
            if (array[i] == array[j]) {
                array.erase(array.begin() + j);
                j--; // Decrement j to check the new element at position j.
            }
        }
    }
}


//Doing the union of the sets .
void Union(vector<int> a1 , vector <int> a2 ){
    
    /*We will simpy take the intersection of the two sets simultaneously removing the common elemnets form both the sets and then 
    will print the intersection and the sets which will be mathematically true union of both the sets.*/

    arraySort(a1);
    arraySort(a2);
    duplicateRemover(a1);
    duplicateRemover(a2);
    vector <int> in;
        for(int i = 0 ; i<a1.size(); i++){
            for(int j = 0 ; j<a2.size() ; j++){
                if(a1[i]==a2[j] && a1[i] != DEF){ 
                    in.push_back(a1[i]);
                    a1[i] = DEF; //Setting the values of the elements taken in to intersection to DEF.
                    a2[j]= DEF;
                    break;
                }
                
            }
        }
    
    //The main functins end here. Now the printing work continues.

    cout<<"\n\nUnion of the sets entered is : ";
    arrayPrinter(in);
    arrayPrinter(a1);
    arrayPrinter(a2);
}



int main(){
    clock_t start , end ;       //Including the clock framework for measuring the time taken to measures the time taken to perform the task.
    start = clock();

    vector <int> SET1;
    vector <int> SET2;

    SET1 = {1,2,3,8,8,85,653,4,5,89};
    SET2 = {1,2,3,89,89,85,57};
    Union(SET1 , SET2);

    end = clock();
    cout<<endl<<endl<<"The time taken to run the program is : "<<end-start<<" ms"<<"\n\n";
    return 0 ;
}