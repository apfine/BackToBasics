#include <iostream>
#include "linkedList.h"


using namespace std;

int main(){
    linked list;
    list.addLast(5);
    list.addLast(7);
    list.addLast(8);
    list.addLast(12);
    list.addLast(90);
    list.show();
    list.addhead(23);
    list.addMid(4 , 89);
    list.delet(4);
    list.addMultiple(5);
    list.show();
    int n = list.at(6);
    cout<<"\n"<<n;
}

