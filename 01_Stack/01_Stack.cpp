#include <iostream>
using namespace std;
  
class myStack {
    int max_size;
    int* arr;
    int top = -1;
    public:
        myStack(int _max_size = 10){
            max_size = _max_size;
            arr = new int[max_size];
        }
        bool push(int num_to_push){
            if (top == max_size - 1){
                std::cout << "Stack Overflow!!" << std::endl;
                return false;
            }
            top += 1;
            arr[top] = num_to_push;
            //cout << "Pushed an int." << endl;
            return true;
        }
        int pop(){
            if (top == -1){
                std::cout << "Stack Underflow!!" << std::endl;
                return 0;
            }
            top -= 1;
            //cout << "Popped an int." << endl;
            return arr[top+1];
        }
        int peek(){
            if (top == -1){
                std::cout << "Stack Empty!!" << std::endl;
                return 0;
            }
            return arr[top];
        }
};

int main(){
    myStack stac = myStack(15);
    bool check = stac.push(100);
    std::cout << "Popped: " << stac.pop() << std::endl;
    int test = stac.pop();
}