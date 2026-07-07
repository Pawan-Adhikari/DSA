#include<iostream>
using namespace std;

class Stack{
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
        node* top;
        int stacksize;
        Stack() : top(nullptr), stacksize(0){}
        int push(int data){
            node* new_node = new node(data);
            if (new_node == nullptr) return -1;
            new_node->next = top;
            top = new_node;
            stacksize++;

            cout << "Successfully pushed a new node at top! The new node pushed is:" << endl;
            new_node->display();

            return 0;
        }
        int pop(){
            if (top==nullptr) {
                cout << ("Underflow!")<< endl;
                return -1;
            }
            int value = top->data;
            node* temp = top;
            top = top-> next;

            cout << "Successfully deleted a new node at top! The node deleted is:" << endl;
            temp->display();

            delete temp;
            stacksize--;
            return value;
        }

        int peek_top(){
            if (top==nullptr) {
                cout << ("Underflow!")<< endl;
                return -1;
            }
            else return top->data;
        }

};

int main(){
    Stack myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.pop();
    myStack.push(30);
    myStack.push(40);
    myStack.pop();

    myStack.peek_top();

    cout << "Current Queue Size: " << myStack.stacksize << endl;
    return 0;
}