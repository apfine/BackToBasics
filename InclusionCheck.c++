//I wrote a program to check wether the string is contained in the other string or not.
#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

string inCheck(string s1 , string s2){
    if( s2.find(s1) >=0 && s2.find(s1) < s1.length()){
        return "True";
    }
    else{
        return "False";
    }
}

int main(){
    clock_t start, end;
    string s1 , s2;
    cout<<"\nPlease enter the string you want to find out  : ";
    cin>>s1;
    cout<<"\nPlease enter the string you want to find from : ";
    cin>>s2;
    start = clock();
    string x = inCheck(s1 ,s2);
    end = clock();
    cout<<"\nThe result is : "<<x;
    cout<<"\n\nThe time taken to run the program is : "<<end - start <<" ms.\n\n";
    return 0;
}