#include <iostream>
#include "Stacks.h++"

using namespace std;

int main(){
    stack s;
    cout<<1;
    s.push(5);
    s.push(90);
    s.push(76);
    s.push(23);
    s.pushMultiple(2);
    s.pop();
    s.print(); 
    s.isEmpty();
    s.clear();
    s.print();
    s.isEmpty();
    return 0;
}

