#include <iostream>
#include "bst.h++"

using namespace std;

int main(){
    bst b;
    int n;
    
    cout<<"\nPlease enter the members of the tree :- ";
    while(cin>>n&& n!=-1){
        b.add(n);
    }
    b.bst::add(98);
    b.bst::add(8);
    b.print();
    b.max();
    b.min();
    b.del();
    b.max();
    b.print();
    b.clear();
    b.print();
    b.max();
    b.min();
    cout<<"\nDone.";
}