//I wrote a program which is used to check if the sorted array is rotated or not and to check the rotation axis .
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
int DEF = INT32_MAX;

using namespace std ;

void arrayPrinter(vector <int> a){
    cout<<endl;
    for (int i : a){
        cout<<"  "<<i;
    }
    cout<<endl;
}

void  Check(vector <int> a) {
    vector <int> array(a.size());
    array = a;
    sort(array.begin() , array.end());
    for(int i = 0 ; i<array.size(); i++){
        for(int j =0 ; j<array.size(); j++){
            if(i==j && array[j]==a[i]&&array[j+1]==a[i+1]){
                a[i] = DEF;
            }
        }
    }

    //Checking for wherer was the axis of rotation.
    vector <int> temp  = a;
    sort(a.begin(), a.end());
    int count = 0;
    for(int i =0 ; i<a.size()-1 ; i++){
        for(int j = 0 ; j <temp.size()-1 ; j++){
            if(temp[i]==a[i]&& temp[j+1] != a[i+1]){
                cout<<"\nThe axis of rotation is : "<<a[i]<<" which is the index "<<i<<" element.\n";
                count++;
                break;
            }
        }
        if(count>0){
            break;
        }
    }

}

int main(){
    vector <int> a = {5,4,3,2,1,6,7,8,9};
    Check(a);

    return 0;
}
