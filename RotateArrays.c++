//I wrote a program to rotate a whole array about an axis . The time complexity is O(n).

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void ArrayPrinter(vector <int> array){
    cout<<endl;
    for(auto i : array){
        cout<<"  "<<i ;
    }
    cout<<endl;
}

vector <int> ArrayRotate(vector <int> a , int n){
    
    vector <int> array(a.size());
    array[n] = a[n];
    int c1 = 0 ;
    int c2 = 0;
    //Here n is the axis of rotation of the array.
    //Left hand side of the algorithms
    for(int i = n+1 ; i< a.size(); i++){
        int j = 2*n-i;
        if((i-n)>n){
            break;
        }
        if(j>=0){
            array[j] = a[i];
            c1++;
        }

    }

    //Right hand side of the array.
    for(int i = n-1 ; i>=0; i--){
        int k = 2*n-i;

        if(k<a.size()){
            array[k] = a[i];
            c2++;
        }
    }

    //Adding the non-symmetric elements of the left side of the array.
    if(n-c2>0){
        for(int i = 0  ; i<=n-c2 ; i++){
            array[i] = a[i];
        }
    }

    //Adding the non-symmetric elements of the right side of the array.
    if(n+c1<a.size()){
        for(int i = n+c1+1  ; i<a.size() ; i++){
            array[i] = a[i];
        }
    }

    //Checking if the array is symmetric about the axis.
    if(array == a){
        cout<<"\nThe array is symmetric about the axis.\n";
    }
    return array ;
}

int main(){
    clock_t start , end ;
    start = clock();
    vector <int> array = {5,6,8,9,9,6,4,32,4,6};
    cout<<"\nThe array before rotation : ";
    ArrayPrinter(array);
    array = ArrayRotate(array , 4);
    cout<<"\nThe array after rotation : ";
    ArrayPrinter(array);
    end = clock();
    cout<<"\nThe time taken to run the program is : "<<end-start<<" ms.\n\n";
    return 0 ;
}