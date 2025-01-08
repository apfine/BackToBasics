/*                      github.com/apfine                                                   */
/**
 * In this header file we define the abstract data structure binary search trees.
 * The property of this ADT is that the smallest element is the leftmost of the tree and greates is the right one.
 * The more generalised format of this is heaps which we will discuss in the next header file.
 * Heaps is a structure which do have a heap condition on the parent whichb is a bit differrent from BSTs hence kept different.
 * In this header file I have introduced the concept of inheritence.
 */

#ifndef BST_HPP
#define BST_HPP
#include <iostream>
#include "Tree.h++"
using namespace std;

class bst : protected tree{                 /*The class bst is a child of class tree.                                         */
    private:
        nnode* root;

        void dele(int n){
            nnode* current = root;
            stack* s = new stack();
            queue* q = new queue();
            int c = 0 ;
            while(1){
                while(current){   
                    if(current->data!=n){
                        q->enqueue(current);
                    }
                    else c++;
                    s->push(current);
                    current = current->left;
                }
                if(s->isEmpty())break;
                current = s->pop();
                current = current->right;
            }
            if(c==0){
                cout<<"\nThe value do not exist in the list.";
                return;
            }
            clear();
            root =new nnode( q->dequeue()->data);
            while(!q->isEmpty()){
                int p = q->dequeue()->data;
                add(p);
            }
        }
    
        void addb(int n , nnode*& current){
            if(!root){
                root = new nnode(n);
            }
            else{
                if(!current){
                    current = new nnode(n);
                    return;
                }
                if (current->data<n){
                     return addb(n , current->right);
                }
                else if(current->data>n) {
                    return addb(n , current->left);
                }
                else return;
            }
        }
    
    public: 
        bst():root(){}

        void add(int n){                   /*This function adds the given value if unique to the right place in the tree.   */
            nnode* current = root;
            addb(n , current);
        }
        
        void print(){                      /*This function prints out whole tree.                                          */
            tree::root = bst::root;
            tree::print();
        }

        void clear(){                      /*This function clears the binary search tree by freeing memory space.         */
            tree::root = bst::root;
            tree::clear();
            root = nullptr;
        }

        int max(){                          /*Returns the maximum of the list which is the right most element of the tree.*/
            if(!root){
                cout<<"\nThe list is empty.";
                return -1;
            }
            nnode* current = root;
            while(1){
                if(!current->right){
                    cout<<"\nThe maximum value is : "<<current->data;
                    return current->data;
                }
                current = current->right;
            }
        }
        
        int min(){                          /*Returns the minimum of the list which is the left most element of the tree.*/
            if(!root){
                cout<<"\nThe list is empty.";
                return -1;
            }
            nnode* current = root;
            while(1){
                if(!current->left){
                    cout<<"\nThe minimum value is : "<<current->data;
                    return current->data;
                }
                current = current->left;
            }
        }

        void del(){                         /*Deletes the value provided.*/
            int n;
            cout<<"\nPlease enter the value to delete : ";
            cin>>n;
            dele(n);
        }
};

#endif
/*                      github.com/apfine                                                    */