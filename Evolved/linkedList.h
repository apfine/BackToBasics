//In this file I have defined doubly linked list which are a bit advanced than singly linked lists but almost similar
//If you cover these you will not need to do them seprately.

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

struct Node              //There is no specefic need to use typedef before struct in c++ but if in c you should.
{                        //You would also need to replace the iostream with stdio.h
    int key;
    Node* prev;
    Node* next ;
    Node(int val) : key(val) , prev(nullptr) , next(nullptr){}
};

class linked{
    private:
        Node* head ;
        Node* tail ;

        void  del (Node* target){
          if(!target)return;
          if(target==head){
              head==target->next;
          }
          else if(target==tail){
              target->prev->next = nullptr;
          }
          else{
              target->next->prev = target->prev;
              target->prev->next = target->next;
          }
          delete target;
        }        

    public :
        //Constructor that generated head and tail of a linked list with null value
        linked(): head(nullptr) , tail(nullptr){}
            
            //Destructor to clean up memory
         ~linked() {
             Node* current = head;
             while (current != nullptr) {
                 Node* nextNode = current->next;
                 delete current;
                 current = nextNode;
             }
         }


        /**
         @brief This method adds the provided value as head of the list.
         @param val The value to be added as a head.
         */
         void addhead(int val){
            Node* newN = new Node(val);
            head->prev = newN;
            newN->next = head ;
            head = newN;
         }


        /**
         @brief This methods adds the value as the tail of the list.
         @param value This value to be added as a tail.
         */
        void addLast(int value){      //This method helps adding a member at the last of the list.
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* current = head;
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = newNode;
            }
        }

        /**
         @brief This methdod is used to add a value in the mid .
         @param count This is the position of the insetion.
         @param num This is the value to be inserted.
          */        
        void addMid(int count , int num){       //This method helps inserting a number at a specefic position in the list
            Node* current = head;
            while(count-->2){
                current = current->next;
            }
            Node* ins = new Node(num);          //One mistake we often do is that we do not want to dynamically initialize the node .
            ins->prev = current;                 
            ins->next = current->next;
            
            current->next->prev = ins;
            current->next = ins;

            
        } 

        //This shows the complete list of objects
        /**
        @brief This method shows the list from starting to end.
         */
        void show(){
            Node* current = head;
            while(current!=nullptr){
               
                std::cout<<current->key<<"->";
                current = current->next;
    
            }
            std::cout<<"Null \n";
        }

        /**
         @brief This method returns the head if called.
         */
        Node* getHead(){
            return head;
        }

        /**
         @brief This method returns the tail if called.
         */
        Node* getTail(){
            return tail;
        }



        /**
         @brief This method gives deletes a number from specefic position
         @param position This parameter is used to delete an object from position.
         */
        void delet(int position){
            Node* current = head;
            while(position>1){
                current= current->next;
                position--;
            }
            if(current!=nullptr){
                del(current);
            }
            else{
            std::cout<<"\nThe position "<<position<<" was not found in the list.";
            }
        }
        


        /**
         @brief You can add multiple values to the list with this method
         @param count This is the count of number of elements to be added.
         */
        void addMultiple(int count){
            //This method adds multiple values to the list;
            std::cout<<"\nPlease enter the numbers one by one : ";
            while(count-->0){
                int n;
                std::cin>>n;
                addLast(n);
            }
        }

        /**
         @brief This method is used to reach at a number at a specefic place in the list
         @param at This is the position of where you want to reach in the list (Don't confuse this with array zero indexing.)
         */
        int at(int at){
            Node* n = new Node(NULL);         //This function/method opens up the way for you to sort the linked-list.
            n = head;
            while(at-->1){
                n = n->next;
            }
            return n->key;

        }


    
};

#endif
