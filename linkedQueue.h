/*linkedQueue class declarations and implementation functions
    functions used:
        constructor
        destructor
        -isEmpty
        makeEmpty
        -enqueue
        -dequeue
*/

#ifndef HQUEUE
#define HQUEUE

#include <iostream>
using namespace std;

//list node ***********************************************
//each character of the work will be stored in the 'info' element
template <class type>
struct nodetype{
    type info;
    nodetype<type> *next;
    };

//class declarations **************************************
template <class type>
class linkedQueue{
    public:
        linkedQueue();
        ~linkedQueue();
        bool isEmpty() const;
        void makeEmpty();
        void enqueue(const type &newItem);
        type dequeue();
    private:
        nodetype<type> *front;
        nodetype<type> *back;
};

//implementation functions ********************************
//constructor
template <class type>
linkedQueue<type>::linkedQueue(){
    front = NULL;
    back = NULL;
}

//destructor, not really needed for this assignment
template <class type>
linkedQueue<type>::~linkedQueue(){
        makeEmpty();
}

//return true if queue is empty
template <class type>
bool linkedQueue<type>::isEmpty() const{
    return (front == NULL);
    }

//clear all nodes
template <class type>
void linkedQueue<type>::makeEmpty(){
    nodetype<type> *tmp;
    while(front != NULL){
        tmp = front;
        front = front->next;
        delete tmp;
        }
        back = NULL;
}

//add an item to the queue
template <class type>
void linkedQueue<type>::enqueue(const type &newItem){
    nodetype<type> *tmp;               //create tmp pointer, list and store values
    tmp = new nodetype<type>;
    tmp->info = newItem;
    tmp->next = NULL;

    if(front == NULL){
        front = tmp;
        back = tmp;
        }
    else if(front != NULL){
        back->next = tmp;
        back  = back->next;
    }
}

//remove frontmost node and return value
template <class type>
type linkedQueue<type>::dequeue(){
    nodetype<type> *tmp;
    type returnval;
    if(!isEmpty()){
        tmp = front;
        returnval = front->info;
        front = front->next;
        delete tmp;
        }
        if(front == NULL){
            back = NULL;
            }
        return returnval;
}

#endif











