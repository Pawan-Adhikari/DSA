#include<iostream>
using namespace std;

class Queue{
    struct node{
        int data;
        node* next;
        node(int val): data(val), next(nullptr){}
        void display(){
            cout << "At address: " << this << endl;
            cout << "Data: " << data << endl;
            cout << "Next Address: " << next << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        }
    };

    public:
        node* front;
        node* rear;
        int queuesize;
        Queue() : front(nullptr), rear(nullptr), queuesize(0){}

        int Enqueue(int data){
            node* new_node = new node(data);
            if (new_node == nullptr) return -1;
            if (rear!=nullptr){
                rear->next = new_node;
                rear = new_node;
            }
            else {
                rear = new_node;
                front = new_node;
            }
            queuesize++;
            cout << "Successfully enqueued a new node at rear! The new node enqueued is:" << endl;
            new_node->display();

            return 0;
        }
        int Dequeue(){
            if (front==nullptr) {
                cout << ("Underflow!")<< endl;
                return -1;
            }
            int value = front->data;
            node* temp = front;
            front = front-> next;

            cout << "Successfully dequeued a node at front! The node dequeued is:" << endl;
            temp->display();

            delete temp;
            queuesize--;
            return value;
        }
        void traverse_display(){
            cout << "Current List Status:" << endl;
            node* cptr = front;
            if (front==nullptr){
                cout << "|null | null|" << endl;
            }
            else{
                while (cptr != nullptr){
                    if (cptr->next == nullptr){
                        cout << "|" << cptr->data << "|" << "null" << "|"; 
                    }
                    else{
                        cout << "|" << cptr->data << "|" << cptr->next << "|" << "------->" ;
                    }
                    cptr = cptr->next;
                }
                cout << endl;
            }
            cout << "_________________________________________________________________________" << endl;
            cout << endl;
        }
};

int main(){
    Queue myQueue;
    myQueue.traverse_display();
    myQueue.Enqueue(10);
    myQueue.Enqueue(20);
    myQueue.traverse_display();
    myQueue.Enqueue(30);
    myQueue.Dequeue();
    myQueue.traverse_display();
    myQueue.Dequeue();
    myQueue.traverse_display();

    return 0;
}