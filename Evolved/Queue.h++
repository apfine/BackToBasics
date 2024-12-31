/*                      github.com/apfine                   */

#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>

struct node{
    int data;
    node* next;
    node():data(0),next(nullptr){}
    node(int d, node* n):data(d) , next(n){}
    node(int d):data(d) , next(nullptr){}
};

class queue{
    private:
        node* front ;
        node* rear;
    public:
    //constructor
    queue():front() , rear(){}
    ~queue(){
        node* current = front;
        node* next = front->next;
        while(current){
            delete current;
            current = next;
            next = current->next;
        }
        delete front;
        delete rear;
    }

    /**
     * @brief function adds a member to the queue
     * @param a This is the value to be added to the queue.
     */
    void enqueue(int a){
        node* p = new node(a);
        if(rear){
            rear->next = p;
            if(!front){
                front = rear;
            }
            rear = p;
        }
        rear = p;
    }

    /**
     * @brief This function removes memeber from the front.
     */
    void dequeue(){
        node* temp = new node();
        temp = front;
        front = front->next;
        std::cout<<"\nThe member dequeued is : "<<temp->data<<".\n";
        delete temp;
    }

    /**
     * @brief This function checks wether the queue is empty or not.
     */
    bool isEmpty(){
        if(!front&&!rear){
            std::cout<<"\nThe Queue is empty.";
            return true;
        }
        std::cout<<"\nThe stack is not empty.";
        return false;
    }

    /**
     * @brief The function prints the whole queue.
     */
    void print(){
        if(!front){
            std::cout<<"\nThe queue is empty.";
            return;
        }
        std::cout<<"\n";
        node* current  = front;
        while(current){
            std::cout<<current->data;
            current = current->next;
            if(current)std::cout<<" -> ";
        }
        std::cout<<"\n";
    }


    /**
     * @brief This function clears the compelte queue.
     */
    void clear(){
        std::cout<<"\nThe clear function have been called.";
        while(front){
            dequeue();
        }
    }

    /**
     * @brief This function helps enqueuing multiple memebers at a time.
     * @param n This is the number of members to be enqueued.
     */
    void multiple(int n){
        int a;
        std::cout<<"\nPlease enter the members to be enqueued : ";
        while(n--){
            std::cin>>a;
            enqueue(a);
        }
    }

};
#endif

/*                      github.com/apfine                   */

/**
 * This is implementation of queue using linked lists.
 * I have given all the basic functions of this ADT.
 * The ADT can also be implemented using circular arrays but the above implementation is more simpler according to me.
 */