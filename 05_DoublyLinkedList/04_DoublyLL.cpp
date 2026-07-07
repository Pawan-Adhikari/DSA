#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* prev;
        node* next;
        node(int value=0, node* _next=nullptr, node* _prev=nullptr){
            this->data = value;
            this->next = _next;
            this->prev = _prev;
        }
        void display(){
            cout << "At address: " << this << endl;
            cout << "Previous Address: " << prev << endl;
            cout << "Data: " << data << endl;
            cout << "Next Address: " << next << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        }
};

class LinkedList{
    public:
        node* start;
        LinkedList(node* startptr = NULL){
            this->start = startptr;
        }
        
        void traverse_display(){
            cout << "Current List Status:" << endl;
            node* cptr = start;
            if (start==nullptr){
                cout << "|null|null|null|" << endl;
            }
            else{
                while (cptr != nullptr){
                    if (cptr->prev == nullptr && cptr->next == nullptr){
                        cout << "|null|" << cptr->data << "|" << "null" << "|"; 
                    }
                    else if (cptr->prev == nullptr){
                        cout << "|null|" << cptr->data << "|" << cptr->next << "|" << "------->" ; 
                    }
                    else if (cptr->next == nullptr){
                        cout << "|" << cptr->prev << "|" << cptr->data << "|" << "null" << "|"; 
                    }
                    else{
                        cout << "|" << cptr->prev << "|" << cptr->data << "|" << cptr->next << "|" << "------->" ;
                    }
                    cptr = cptr->next;
                }
                cout << endl;
            }
            cout << "_________________________________________________________________________" << endl;
            cout << endl;
        }

        bool ins_beginning(int value){
            node* new_ptr = new node;
            if (new_ptr==nullptr) {
                cout << "New Node creation failed. OOM" << endl;
                return 1;
            }
            new_ptr->data = value;
            if (start == nullptr){
                start = new_ptr;
            }
            else{
                start -> prev = new_ptr;
                new_ptr->next = start;
                start = new_ptr;
            }
            cout << "Successfully added a new node at beginning! The new node added is:" << endl;
            new_ptr->display();
            return 0;
        }
        bool ins_end(int value){
            node* new_ptr = new node(value);
            if (new_ptr==nullptr) {
                cout << "New Node creation failed. OOM" << endl;
                return 1;
            }
            if (start == nullptr){
                start = new_ptr;
            }
            else{
                node* ptr = start;
                while (ptr->next!=nullptr){
                    ptr = ptr->next;
                }
                new_ptr->prev = ptr;
                ptr->next = new_ptr;
            }
            cout << "Successfully added a new node at end! The new node added is:" << endl;
            new_ptr->display();
            return 0;
        }
        bool ins_after_specific(int value, int target){
            node* new_ptr = new node;
            if (new_ptr==nullptr) {
                cout << "New Node creation failed. OOM" << endl;
                return 1;
            }
            new_ptr->data = value;
                node* ptr = start;
                while (ptr!=nullptr && ptr->data!=target){
                    ptr = ptr->next;
                }
                if (ptr==nullptr) {
                    cout << "Target node not found!!" << endl;
                    return 1;
                }
                node* postptr = ptr->next;
                if (postptr != nullptr){
                    postptr->prev = new_ptr;
                    new_ptr->next = postptr;
                }
                    new_ptr->prev = ptr;
                    ptr->next = new_ptr;
            cout << "Successfully added a new node after specified node: "<< target<<" ! The new node added is:" << endl;
            new_ptr->display();
            return 0;
        }
        bool ins_before_specific(int value, int target){
            node* new_ptr = new node;
            if (new_ptr==nullptr) {
                cout << "New Node creation failed. OOM" << endl;
                return 1;
            }
            new_ptr->data = value;
            if (start == nullptr){
                start = new_ptr;
            }
            else{
                node* postptr = start;
                node* preptr = start;
                while (postptr!=nullptr && postptr->data!=target){
                    preptr = postptr;
                    postptr = postptr->next;
                }
                if (postptr==nullptr) {
                    cout << "Target node not found!!" << endl;
                    return 1;
                }
                postptr->prev = new_ptr;
                new_ptr->next = postptr;
                new_ptr->prev = preptr;
                preptr->next = new_ptr;
            }
            cout << "Successfully added a new node before specified node: "<< target<<" ! The new node added is:" << endl;
            new_ptr->display();
            return 0;
        }
        bool del_beginning(){
            if (start==nullptr){
                cout << "The list is empty: Underflow!!" << endl;
                return 1;
            }
            else{
                node* temp = start;
                node* posttemp = start->next;
                if (posttemp!=nullptr) posttemp->prev = nullptr;

                start = posttemp;
                cout << "Successfully deleted the node at beginning. The deleted node was:" << endl;
                temp->display();
                delete temp;
            }
            return 0;
        }
        bool del_end(){
            if (start==nullptr){
                cout << "The list is empty: Underflow!!" << endl;
                return 1;
            }
            else{
                node* temp = start;
                node* pretemp = start;
                while (temp->next != nullptr){
                    pretemp = temp;
                    temp = temp->next;
                }
                pretemp->next = nullptr;
                cout << "Successfully deleted the node at end. The deleted node was:" << endl;
                temp->display();
                delete temp;
            }
            return 0;
        }
        bool del_after_specific(int target){
            if (start==nullptr){
                cout << "The list is empty: Underflow!!" << endl;
                return 1;
            }
            else{
                node* pretemp = start;
                while (pretemp!=nullptr && pretemp->data != target){
                    pretemp = pretemp->next;
                }
                if (pretemp==nullptr){
                    cout << "Node "<< target <<" not found!!" << endl;
                    return 1;
                }
                if (pretemp->next != nullptr){
                    node* temp = pretemp->next;
                    node* posttemp = temp->next;
                    if (posttemp != nullptr) posttemp->prev = pretemp;
                    pretemp->next = posttemp;
                    cout << "Successfully deleted after specified node: "<< target <<" . The deleted node was:" << endl;
                    temp->display();
                    delete temp;
                }
                else{
                    cout << "No node after "<< target <<"! What shall I delete?" << endl;
                    return 1;
                }
            }
            return 0;
        }

         bool del_before_specific(int target){
            if (start==nullptr){
                cout << "The list is empty: Underflow!!" << endl;
                return 1;
            }
            else{
                node* posttemp = start;
                while (posttemp!=nullptr && posttemp->data != target){
                    posttemp = posttemp->next;
                }
                if (posttemp==nullptr){
                    cout << "Node "<< target <<" not found!!" << endl;
                    return 1;
                }
                    node* temp = posttemp->prev;
                    node* pretemp = temp->prev;
                    posttemp->prev = pretemp;
                    pretemp->next = posttemp;
                    cout << "Successfully deleted before specified node: "<< target <<" . The deleted node was:" << endl;
                    temp->display();
                    delete temp;
                }
            return 0;
            }
};

int main(){
    
    LinkedList myLL;

    myLL.traverse_display();

    cout << "Insertion at Beginning: " << endl;
    myLL.ins_beginning(2);
    myLL.traverse_display();

    cout << "Insertion at End: " << endl;
    myLL.ins_end(3);
    myLL.traverse_display();

    cout << "Insertion before element 3: " << endl;
    myLL.ins_before_specific(4, 3);
    myLL.traverse_display();

    cout << "Insertion after element 3: " << endl;
    myLL.ins_after_specific(5, 3);
    myLL.traverse_display();

    cout << "Deletion at Beginning: " << endl;
    myLL.del_beginning();
    myLL.traverse_display();

    cout << "Deletion at End: " << endl;
    myLL.del_end();
    myLL.traverse_display();

    cout << "Deletion after 4: " << endl;
    myLL.del_after_specific(4);
    myLL.traverse_display();

    cout << "Deletion after 20: " << endl;
    myLL.del_after_specific(20);
    myLL.traverse_display();

    cout << "Deletion at Beginning: " << endl;
    myLL.del_beginning();
    myLL.traverse_display();

    cout << "Deletion at End: " << endl;
    myLL.del_end();
    myLL.traverse_display();

    return 0;
}