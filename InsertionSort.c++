#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void arrayPrinter(vector <int> array){
    for(int i =0 ; i<array.size() ; i++){
        cout<<"  "<<array[i];
    }
}

vector <int> insertionSort(vector <int> array){
    for(int i =1 ; i<array.size() ; i++){
        int key = array[i];
        int j = i-1;
        while(key<array[j] && j>=0){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
    return array;
}

int main(){
    clock_t start ,end ;
    start = clock();
    vector <int> array = {2,4,99,99,7,9,6,7,9,0,43,445,6,7};
    array = insertionSort(array);
    arrayPrinter(array);
    end   = clock();
    cout<<"\n\nThe time taken to run the complete program is : "<<end - start << " ms.\n\n";
    return 0;
}