/*                                                  github.com/apfine                                                                       */


/**
 * The code below is an implementation of the ADT heaps.
 * Heaps are of two types 
 * 1. MAX heaps
 * 2. MIN heaps
 * I have implemented the add , delete , clear , print and find function on the max and min heaps.
 * The type of the heap i.e. max or min is decided by the user through terminal input.
 * Later on the complete heap object behaves as accordingly.
 */

#ifndef heaps
#define heaps

#include "Tree.h++"
#include <iostream>
using namespace std;

class heap : protected tree{

    private:
        nnode* root;
        nnode* root_dad ;
        int max , min , c;

        void qu(queue*& q , nnode* current){
            if(current->right)q->enqueue(current->right);
            if(current->left)q->enqueue(current->left);
        }
        void addmin(int n , nnode*& current ,queue*& q , nnode*& prev){
            if(!current) return;
            if(q->isEmpty()){
                if(prev->left){
                    if(!prev->right)prev->right=new nnode(n);
                    else if(!current->left){
                        current->left = new nnode(n);
                    }
                    else if(!current->right){
                    current->right = new nnode(n);
                    }
                }
                else{
                    prev->left = new nnode(n);
                }
                return;
            }
            prev = current;
            current = q->dequeue();
           
            if(current->data>n){
                int b = current->data;
                current->data = n;
                n = b;
            }
            qu(q , current);
            return addmin(n , current , q, prev);
        }
        void addmax(int n , nnode*& current ,queue*& q , nnode*& prev){
            if(!current) return;
            if(q->isEmpty()){
                if(prev->left){
                    if(!prev->right)prev->right=new nnode(n);
                    else if(!current->left){
                        current->left = new nnode(n);
                    }
                    else if(!current->right){
                    current->right = new nnode(n);
                    }
                }
                else{
                    prev->left = new nnode(n);
                }
                return;
            }
            prev = current;
            current = q->dequeue();
           
            if(current->data<n){
                int b = current->data;
                current->data = n;
                n = b;
            }
            qu(q , current);
            return addmax(n , current , q, prev);
        }
    
    public:
        heap():root(),max(0),min(0), c(0) {
            cout<<"\nPlease enter heapMax(1) or heapMin(0) : ";
            int button;
            root_dad =  new nnode(-1 , root , root);
            cin>>button;
            if(button==1)max = 1;
            else if(button==0) min= 1;
            else heap();

        }

        /**
         * @brief The function adds the provided value to the heap.
         * @brief The heap property is fixed from the object construction by the user.
         * @param n This is the data that is to be stored in to the tree.
         */
        void add(int n){
            if(!root){
               
                root = new nnode(n);
                return;
            }

            nnode* root_dad = new nnode(-1 , root , root);
            nnode* current = root;
            nnode* prev = new nnode();
            queue* q = new queue() ;
            stack* s = new stack() ;
            qu(q , root);
            if(max==1){
                
                if(n>root->data){
                    root_dad->right = root_dad->left = new nnode(n , root , root->right);
                    root->right = nullptr;
                    root = root_dad->left;
                    return;
                }
                prev = root;
                addmax(n , current , q , prev);
            }
            else if(min==1){
                if(n<root->data){
                    root_dad->right = root_dad->left = new nnode(n , root , root->right);
                    root->right = nullptr;
                    root = root_dad->left;
                    return;
                }
                prev =root;
                addmin(n , current ,  q  , prev);
            }
        }

        /**
         * @brief This function deletes all the nnodes of the tree and nullifies the root.
         */
        void clear(){
            tree::root = heap::root;
            tree::clear();
            root = nullptr;
        }        
        
        /**
         * @brief This fucntion deletes the provided value from the tree .
         * @param n This is the key/data to be deleted from the tree.
         */
        void del(int n){
            /*here we go through the tree keep all the elements and ignore the specefic element and then reconstruct the tree .*/
            nnode* current = root;
            queue* q = new queue();
            stack* s = new stack();
            while(1){
                while(current){
                    q->enqueue(current);
                    s->push(current);
                    current= current->left;
                }
                if(s->isEmpty())break;
                current = s->pop();
                current = current->right;
            }
            clear();
            
            while(!q->isEmpty()){
                int current = q->dequeue()->data;
                if(!(current==n) )add(current);
            }
        }
        
        /**
         * @brief This function prints the complete tree through pre , in , post or level order traversal.
         * @brief The traversal type can be chosen by the user.
         */
        void print(){
            tree::root = heap::root;
            tree::print();
        }

        /**
         * @brief This function helps the user find wether a key exists in the tree or not.
         * @brief If the value exists the memory address gets printed or else null.
         */
        void find(int n){
            tree::root = root;
            tree::find(n);
        }
};

#endif


/*                                                      github.com/apfine                                                               */