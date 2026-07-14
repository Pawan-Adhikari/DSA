#include <iostream>
using namespace std;

class PolynomialLL{
    public:
        struct node{
            int coeff;
            int pow;
            node* next;
            node(int _coeff, int _pow): coeff(_coeff), pow(_pow), next(nullptr){}
        };
        node *start;
        PolynomialLL() : start(nullptr){}

        void traverse_display(){
            cout << "Current List Status:" << endl;
            node* cptr = start;
            if (start==nullptr){
                cout << "|null | null|" << endl;
            }
            else{
                while (cptr != nullptr){
                    if (cptr->next == nullptr){
                        cout << "|" << cptr->coeff << "|" << cptr->pow << "|"  << "null" << "|"; 
                    }
                    else{
                        cout << "|" << cptr->coeff << "|" << cptr->pow << "|" << cptr->next << "|" << "------->" ;
                    }
                    cptr = cptr->next;
                }
                cout << endl;
            }
            cout << "_________________________________________________________________________" << endl;
            cout << endl;
        }

        int insert(int _coeff, int _pow){
            node* new_node = new node(_coeff, _pow);
            if (start == nullptr) start=new_node;
            else {
                node* ptr = start;
                node* preptr = start;
                while (ptr->pow >= _pow){
                    preptr = ptr;
                    ptr = ptr->next;
                    if (ptr == nullptr){
                        preptr->next = new_node;
                        ptr = new_node;
                        return -1;
                    }
                    if (ptr->pow == _pow){
                        ptr->coeff += _coeff;
                        delete new_node;
                        return -1;
                    }
                }
                if (ptr==start){
                    new_node -> next = start;
                    start = new_node;
                }
                else{
                    new_node->next = ptr;
                    preptr->next = new_node;
                }
            }
            return 0;
        }

        PolynomialLL add_polynomials(PolynomialLL other_pol){
            PolynomialLL result;
            node* self = start;
            node* other = other_pol.start;
            while (self!=nullptr or other != nullptr){
                if (self == nullptr or (other!=nullptr and other->pow>self->pow)){
                    result.insert(other->coeff, other->pow);
                    other = other->next;
                }
                else if (other == nullptr or self->pow > other->pow){
                    result.insert(self->coeff, self->pow);
                    self = self->next;
                }
                else {
                    result.insert(self->coeff + other->coeff, self->pow);
                    self = self->next;
                    other = other->next;
                }
            }
            return result;
        }
};

int main(){
    PolynomialLL pol1;
    PolynomialLL pol2;
    PolynomialLL pol3;
    PolynomialLL pol4;

    PolynomialLL result;
    cout << "Creating Polynomial 1 by insertion one by one: " << endl;
    pol1.insert(2,1);
    pol1.traverse_display();
    pol1.insert(3,2);
    pol1.traverse_display();
    pol1.insert(3,0);
    pol1.traverse_display();

    cout << "Creating Polynomial 2 by insertion one by one: " << endl;
    pol2.insert(2,1);
    pol2.traverse_display();
    pol2.insert(3,2);
    pol2.traverse_display();
    pol2.insert(3,0);
    pol2.traverse_display();

    cout << "Creating Polynomial 3 by insertion one by one: " << endl;
    pol3.insert(1,4);
    pol3.traverse_display();
    pol3.insert(5,2);
    pol3.traverse_display();
    pol3.insert(2,3);
    pol3.traverse_display();

    cout << "Adding Polynomial 1 and 2: " << endl;
    result = pol1.add_polynomials(pol2);
    cout << "Result is: " << endl;
    result.traverse_display();

    cout << "Adding result with Polynomial 3: " << endl;
    result = result.add_polynomials(pol3);
    cout << "Result is: " << endl;
    result.traverse_display();

    cout << "Adding result with Polynomial 4: " << endl;
    result = result.add_polynomials(pol4);
    cout << "Result is: " << endl;
    result.traverse_display();
}