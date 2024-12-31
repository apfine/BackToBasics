#include<iostream>
#include"Queue.h++"

using namespace std;

int main(){
    queue q;
    q.isEmpty();
    q.enqueue(67);
    q.multiple(2);
    q.isEmpty();
    q.print();
    q.dequeue();
    q.print();
    q.clear();
    q.print();
}

