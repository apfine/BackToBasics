/*                   github.com/apfine                              */
#ifndef STACKS_HPP
#define STACKS_HPP
#include <iostream>

struct node{        /*Defining the node or the member of the stack.*/
    int data;                                                            /*              |           |               */
    node* next;                                                          /*              -------------               */
    node(int x , node* ptr) : data(x) , next(ptr){}                      /*              |           |               */
    node(int x) : data(x) , next(nullptr){}                              /*              -------------               */
    node():data(0), next(nullptr){}                                      /*              |           |               */
};                                                                       /*              -------------               */
                                                                         /*              |           |               */
class stack{                                                             /*              -------------               */

private:
    node* top ;
public:
    //constructor
    stack():top(){}
    //destructor
    ~stack(){
        node* current = top;
        node* next = top->next;
        while(current){
            delete current;
            current = next;
            next = current->next;
        }
        delete top;
    }

    /**
     * @brief This function which puts a new value in the stack.
     * @param a This is the value being pushed in to the stack.
     */
    void push(int a){
        node* x = new node(a);
       if(top){
            node* prev = top;
            top = x;
            top->next = prev;
        }
        else{
            top = x;
        }
    }

    /**
     * @brief This function returns the top value of the stack.
     */
    void pop(){
        std::cout<<"\nThe popped value is : "<<top->data;
        top = top->next;
    }

    /**
     * @brief This function checks wether the stack is empty.
     */

    bool isEmpty(){
        if(top){
            std::cout<<"\nThe stack is not empty.";
            return false;
        }
        std::cout<<"\nThe stack is empty.";
        return true;
    }

    /**
     * @brief This function prints the stack from top to bottom.
     */
    void print(){
        if(top){
            std::cout<<"\nThe stack is :\n";
        }
        else{
            std::cout<<"\nThe stack is empty.";
        }
        node* current = top;
        while(current){
            std::cout<<current->data;
            current = current->next;
            if(current)std::cout<<"\n|\n";
        }
        std::cout<<"\n";
    }

    /**
     * @brief This function helps to push multiple values to the stack.
     * @param n This is the number of elements being pushed in the stack.
     */
    void pushMultiple(int n){
        int b;
        std::cout<<"\nPlease enter the values to be pushed : ";
        while(n--){
            std::cin>>b;
            push(b);
        }
    }

    /**
     * @brief This function helps in deleting all the elements of the stack.
     */
    void clear(){
        node* current = top;
        node* prev = current->next;
        while(prev){
            delete current;
            current = prev;
             prev = prev->next;
        }
        top = NULL;
    }


};
#endif


/**
 * This is a linked list implementation of the stacks which is pretty much straight forward.
 * There can be another methods to implement the stack using dynamic arrays , but I find this one a bit simpler .
 * Stacks are used in browsers for navigating the prevoiously visited page in which the most recent website is visited on hitting the back button.
 * In the arrays version of the stack there is a need for definition of another variable called capacity which adds other complexities with it .
 */


/*                   github.com/apfine                              */