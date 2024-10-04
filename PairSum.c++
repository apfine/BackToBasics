//A number is given also an array . Find out pairs from the array whose sum can be equal to the number ?

//Solving this question using brute force method with O(n^2)

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

int DEF = INT32_MAX;

using namespace std ;

void arrayInput ( vector <int> &array){
    int s, ti ;
    cout<<"\nPlease enter the number of members in the array : ";
    cin>>ti;
    
    //Taking in the inputs and appending them to the array
    for(int i = 0 ; i<ti ; i++){
            
            cout<<"\nPlease enter the "<<i+1 <<" number : ";
            cin>>s;
            array.push_back(s);
            
    }
}

void arrayPrinter(vector <string> array){  // A function for printing a string vector or here it is used to implement an array .
    cout<<endl<<endl;
    for(int i = 0 ;i< array.size();i++){
        cout<<"\t"<<array[i];
    }
}

vector <string> ar(vector <int> array  , int num){ // The function used to return the pairs in an string array.
    vector <string> math;
        for(int i = 0 ; i<array.size(); i++){
            stringstream ss1 , ss2 ;              //Using stringstream in order to convert the obtained integers to strings .
            int cu = array[i];
            for(int j = 1 ; j < array.size(); j++){
                if(array[i]+array[j]==num && i != j ){
                    ss1<<array[i];                          
                    ss2<<array[j];
                    math.push_back("( "+ss1.str()+" , "+ss2.str()+" )\t");
                    array[i] = DEF;
                    array[j] = DEF;
                }   
            }
}
    return math ;
}

int main(){
    clock_t start , end ;
    vector <int> array ;
    int num ;
    
    cout<<endl<<"Please enter the number you want pairs for : ";
    cin>>num;
    arrayInput(array);

    start = clock();
    vector <string> res  =  ar(array,num);
    arrayPrinter(res);

    end = clock();
    cout<<"\nThe time taken to run the program is : "<<end-start<<" ms."; //Only measuring the time taken in processing the array .
    return 0 ;
}

//You can also create a class and put all the funtions above in order to keep it all under one umbrella and then use it under main function.