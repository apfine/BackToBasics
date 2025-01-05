#include <iostream>
#include "Tree.h++"

using namespace std;

int main(){
  tree t;
  t.add(6);
  t.add(8);
  t.add(89);
  t.add(67);
  t.add(783);
  t.add(123);
  t.add(6);
  t.add(34);
  t.add(4);
  t.print();
  t.del(89);
  t.print();
  t.find(6);
}