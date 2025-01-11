#include <iostream>
#include "heaps.h++"

using namespace std;

int main(){
    heap h;
    int n;
    cout<<"\nPlease enter the numbers to be added to the heap (-1 at the end of the array) : ";
    while(cin>>n&&n!=-1){
        h.add(n);
    };
    h.print();
    h.del(1);
    h.print();
    cout<<"\nPlease enter the value you want to find : ";
    cin>>n;
    h.find(n);
    cout<<"\nDone";
}