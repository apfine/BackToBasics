/*                                                          github.com/apfine               */


#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>

struct nnode{
    int data;
    nnode *right;
    nnode *left;
    nnode():data(0),right(nullptr) , left(nullptr){}
    nnode(int d , nnode* r , nnode* l):data(d) , right(r) , left(l){}
    nnode(int d):data(d) , right(nullptr) , left(nullptr){}
};


struct node{        /*Defining the node or the member of the stack.*/
    nnode* data;                                                            /*              |           |               */
    node* next;                                                             /*              -------------               */
    node(nnode* x , node* ptr) : data(x) , next(ptr){}                      /*              |           |               */
    node(nnode* x) : data(x) , next(nullptr){}                              /*              -------------               */
    node():data(0), next(nullptr){}                                         /*              |           |               */
};                                                                          /*              -------------               */
                                                                            /*              |           |               */
class stack{                                                                /*              -------------               */

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
    void push(nnode* a){
       if(!a){
        std::cout<<"\nERROR ! Variable not initialized (@stack).";
       }
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
    nnode* pop(){
        nnode* temp = top->data;
        top = top->next;
        return temp;
    }

    /**
     * @brief This function checks wether the stack is empty.
     */

    bool isEmpty(){
        if(top){
            return false;
        }
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
            std::cout<<"\nThe stack is empty .";
        }
        node* current = top;
        while(current){
            std::cout<<current->data->data;
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
            nnode* k = new nnode(b);
            push(k);
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

    nnode* topi(){
       if(top) return top->data;
       else return nullptr;
    }


};


/*                                        Doubly Linked lists are being defined from here                                 */
struct Node              //There is no specefic need to use typedef before struct in c++ but if in c you should.
{                        //You would also need to replace the iostream with stdio.h
    nnode* data;
    Node* prev;
    Node* next ;
    Node(nnode* val) : data(val) , prev(nullptr) , next(nullptr){}
    Node():data(nullptr),prev(nullptr) ,next(nullptr){}
    Node(nnode* val , Node* p , Node* n ):data(val), prev(nullptr) , next(nullptr){}
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
         void addhead(nnode* val){
            Node* newN = new Node(val);
            head->prev = newN;
            newN->next = head ;
            head = newN;
         }


        /**
         @brief This methods adds the value as the tail of the list.
         @param value This value to be added as a tail.
         */
        void addLast(nnode* value){      //This method helps adding a member at the last of the list.
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
        void addMid(int count , nnode* num){       //This method helps inserting a number at a specefic position in the list
            Node* current = head;
            while(count-->2){
                current = current->next;
            }
            Node* ins = new Node(num);          //One mistake we often do is that we do not want to dynamically initialize the Node .
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
               
                std::cout<<current->data->data<<" {"<<current->data<<"} "<<"->";
                current = current->next;
    
            }
            std::cout<<"Null \n";
        }

        /**
         @brief This method returns the head if called.
         */
        nnode* getHead(){
            return head->data;
        }

        /**
         @brief This method returns the tail if called.
         */
        nnode* getTail(){
            return tail->data;
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
                nnode* m = new nnode();
                addLast(m);
            }
        }

        /**
         @brief This method is used to reach at a number at a specefic place in the list
         @param at This is the position of where you want to reach in the list (Don't confuse this with array zero indexing.)
         */
        nnode* at(int at){
            Node* n = new Node(NULL);         //This function/method opens up the way for you to sort the linked-list.
            n = head;
            while(at-->1){
                n = n->next;
            }
            return n->data;

        }


    
};
/*                                                  Up to here                                       */


/*                                     The Customised queue definition starts from here.                                 */
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
    void enqueue(nnode*a){
        if(!a)return;
        node* p = new node(a);
        if(!front)front = p;
        else{
            if(rear){
                rear->next = p;

            }
            else{
                front->next = p;
            }
            rear = p;
        }
    }

    /**
     * @brief This function removes memeber from the front.
     */
    nnode* dequeue(){
        if(!front)return nullptr;
        node* temp =new node();
       
        temp = front;
        front = front->next;
        nnode* data = temp->data;
        delete temp;
        return data;
    }

    /**
     * @brief This function checks wether the queue is empty or not.
     */
    bool isEmpty(){
        return front == nullptr;
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
            std::cout<<current->data->data;
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
            nnode* b = new nnode(a);
            enqueue(b);
        }
    }

    /**
     * @brief This function returns the front.
     */
    nnode* front_(){
        if(front)return front->data;
        return nullptr;
    }

    /**
     * @brief This function returns the rear.
     */
    nnode* rear_(){
        if(rear)return rear->data;
        return nullptr;
    }

};
/*                                     The custom Queue defintion ends here.                                             */

/*                                     The class tree starts below this.                                                 */

class tree{
    private:
        nnode* root;

        void count(int &countl , int &countr , nnode*& current , stack*& s){
            nnode* b = current;
            int c =0  ;
            while(1){
                while(current&&s){
                    s->push(current);
                    c++;
                    current = current->left;
                }
                if(s->isEmpty())break;
                current = s->pop();
                if(current==b){
                    countl = c-1;
                    c=0;
                }
                current = current->right;
            }
            countr = c;
        }



    public:
        tree():root(){/*This is the constructor.*/}


        /**
         * @brief This is the function which adds a nnode to the tree.
         * @param n This is the data stored in the respective node.
         */
        void add(int n){
            nnode* x = new nnode(n);
            if(!root){
                root = x;
                return;
            }

            /*  being passed in a nested function. */
            nnode* current = new nnode();
            int countl =0 , countr=0 ;
            stack *s = new stack();
            /*  being passed in a nested function. */



            /*  Variables being used in the function .*/
            nnode* c = root;
            nnode* b;
            /*  Variables being used in the function. */


            while(c){
                current = c;
                count(countl , countr , current , s);
                if(countl<=countr){ 
                    b =c ;
                    c=c->left;
                }
                else  {
                    b = c;
                    c = c->right;
                }
            }

            if(!b->left) b->left = x;
            else b->right = x ;

        }

        /**
        * @brief This function prints the complete tree by pre or in or post order traversal , as per user choice.
        */
        void print(){
            if(!root){
                std::cout<<"\nError ! The tree has no nodes to print.";
                return;
            }
            std::cout<<"\nPlease enter 'i'(in order) , 'p'(pre-order) , 'pa'(post-order) , 'l'(level-order) for respective traverserals : ";
            std::string i;
            std::cin>>i;
            
            if(i=="i"){
                std::cout<<"\nThe tree is (in-order traversal) : \n";
                stack *s  = new stack();
                nnode* current = root;
                while(1){
                    while(current){
                        s->push(current);
                        current = current->left;
                    }
                    if(s->isEmpty())break;
                    current = s->pop();
                    std::cout<<" "<<current->data;
                    if(current==root)std::cout<<("      (ROOT) ");
                    current = current->right;
                    std::cout<<"\n";
                }
            }

            else if(i=="p"){
                std::cout<<"\nThe tree is (pre-order traversal) : \n";
                stack *s  = new stack();
                nnode* current = root;
                while(1){
                    while(current){
                        s->push(current);
                        std::cout<<" "<<current->data;
                        if(current==root)std::cout<<("      (ROOT) ");
                        current = current->left;
                        std::cout<<"\n";
                    }
                    if(s->isEmpty())break;
                    current = s->pop();
                    current = current->right;

                }
            }
            
            else if(i=="pa"){
                nnode* y;
                std::cout<<"\nThe tree is (post-order traversal) : \n";
                stack *s  = new stack();
                stack *p = new stack();
                nnode* current = root;
                int h = 0;
                while(1){
                    while(current){
                        s->push(current);
                        current = current->left;
                        
                    }
                    if(s->isEmpty()){
                        break;
                    }
                    current = s->pop();


                    if(!current->right||!current->left){
                        std::cout<<" "<<current->data;
                        std::cout<<"\n";
                      
                    }
                    else{
                        p->push(current);
                    }
                   
                    if(p->topi()){
                    if(current==p->topi()->right){
                        nnode* temp = p->pop();
                        std::cout<<" "<<temp->data;
                        if(temp==root)std::cout<<("     (ROOT) ");
                        std::cout<<"\n";
                    }
                    }
                    h++;
                    current = current->right;
                    
                }
                while(p->topi()){
                    nnode* k = p->pop();
                    std::cout<<" "<<k->data;
                    if(k==root)std::cout<<("        (ROOT) ");
                    std::cout<<"\n";
                }
            }

            else if(i=="l"){
                //This is the level order traversal
                std::cout<<"\n";
                nnode* current = new nnode();
               
                queue* w = new queue();
                w->enqueue(root);

             /**/   while(!w->isEmpty()){
                    current = nullptr;
                    current = w->dequeue();
                    std::cout<<current->data;
                    if(current==root)std::cout<<"       (ROOT)  ";
                    std::cout<<"\n";
                    if(current->left)w->enqueue(current->left);
                    if(current->right)w->enqueue(current->right);
                }
                
            }

            else{
                std::cout<<"\nERROR ! Please enter a valid input .";
                print();

            }       
        }

        /**
         * @brief This function deletes a node from the tree even if its the root.
         * @param This is the value that is to be deleted from the tree.
         */
        void del(int n){
            //This deletes 
            //You can make BST out of the tree and then search easily
            nnode* current = new nnode();
            nnode* de = new nnode();;
            stack* s = new stack();
            queue* q = new queue();
            current =root;
            int c =0;

            //This code below till the stopper is for searching the element to be deleted
            while(1){
                while(current){
                    s->push(current);
                    if(current->data==n&&current) {
                        de = current;
                        c=1;
                        break;
                    }
                    current= current->left;
                }
                
                if(s->isEmpty()||c==1){
                    break;
                }
                
                current = s->pop();
                current = current->right;
            }
            if(!de){
                std::cout<<"\nThe value do not exists in the tree.";
                return;
            }
            //up to here.

            //The code from here till stopper is to copy the whole tree except the elelment to be deleted
            //Being implemented using pre-order traversal.
            current = root;
            
            
            s->clear();
            while(1){
                while(current){
                    s->push(current);
                    if(current!=de)q->enqueue(current);
                    current = current->left;
                }
                if(s->isEmpty())break;
                current = s->pop();
                current = current->right;

            }
            
            //till here.


            //we are rebuilding the tree from here to the way down.
            root = nullptr;
            add(q->dequeue()->data);
            while(!q->isEmpty()){
                current = q->dequeue();
                add(current->data);
            }
        }

        void clear(){
            if(!root)return;
            nnode* current =root;
            queue* q = new queue();
            stack* s = new stack();
            q->enqueue(current);
            while(!q->isEmpty()){
                current = q->dequeue();
                s->push(current);
                if(current->left)q->enqueue(current->left);
                if(current->right)q->enqueue(current->right);
            }
            nnode* c = new nnode();
            s->clear();
            while(!s->isEmpty()){
                c = s->pop();
                delete c;
            }
            root = nullptr;
        }
        
        linked* find(int n){
            linked* l = new linked();
            nnode* current = new nnode();
            nnode* de = new nnode();;
            stack* s = new stack();
            queue* q = new queue();
            current =root;
            int c =0;

            //This code below till the stopper is for searching the element to be deleted
            while(1){
                while(current){
                    s->push(current);
                    if(current->data==n&&current) {
                        de = current;
                        c++;
                        if(!l)l->addhead(current);                //This is the number of times the value have occured in the tree.
                        else l->addLast(current);
                    }
                    current= current->left;
                }
                
                if(s->isEmpty()){
                    break;
                }
                
                current = s->pop();
                current = current->right;
            }
            if(!de){
                std::cout<<"\nThe value do not exists in the tree.";
                return nullptr;
            }
            //up to here.
            l->show();
            return l;
        }

};

#endif

/**
 * Here I have implemented a binary tree which when have total even members balances itself.
 * If there are odd number of elements then the tree is one less numbered on the right side than left one.
 * This if practiced will help you improve your problem solving skills.
 * This is a self balancing tree.
 */


/*                                  github.com/apfine                   */