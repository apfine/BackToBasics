/*Question- Find out the intersection of two sets without eliminating the duplicate elements ?*/


#include <iostream>
#include <time.h>
#include <vector>
int DEF  = INT32_MIN;

using namespace std;

void inter(vector <int> SET1 , vector <int> SET2){
     vector <int> working_set ; 
     vector <int> sec_set ; 


     if(SET1.size()>SET2.size()){

        working_set = SET1;
        sec_set = SET2;

     }
     else{

        working_set = SET2;
        sec_set = SET1;

     }
    cout<<"\n\nThe intersection of the two sets is (duplicates not omitted): \n";
    cout<<"{\t";

    for(int i = 0 ; i<working_set.size(); i++){
                
                for(int j =0 ; j<sec_set.size() ; j++){
                        if (working_set[i] == sec_set[j]){
                            cout<<sec_set[j]<<"\t";
                            sec_set[j] = DEF;
                        }
                }
    }

    cout<<"}";

}

int main(){
    clock_t start, end ;
    start = clock();

    vector <int> SET1;
    vector <int> SET2;
    SET1 = {2,3,5,7,8,9,0,3,3,2,0,4};
    SET2 = {3,5,7,8,5,7,9,8};

    inter(SET1 , SET2 );

    end = clock();
    cout<<endl<<"\nThe time taken to run whole program is : "<<end - start <<" ms\n\n";
    return 0 ;
}