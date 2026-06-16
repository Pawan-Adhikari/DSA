#include <iostream>
using namespace std;

class Queue{
    public:
        int* arr;
        int FRONT;
        int REAR;
        int MAX;
        Queue(int MAX_){
            arr = new int[MAX_];
            FRONT = -1;
            REAR = -1;
            MAX = MAX_;
        }
        int Enqueue(int ITEM){
            if (REAR == MAX -1) {
                cout << "Queue Overflow!!" << endl;
                return 1;
            }
            if (FRONT == -1){
                FRONT = 0;
                REAR = 0;
            }
            else REAR += 1;
            arr[REAR] = ITEM;
            return 0;
        }
        int Dequeue(){
            if (FRONT == -1 || FRONT > REAR){
                cout << "Queue Underflow!!" << endl;
                return 1;
            }
            return arr[FRONT];
            if (FRONT == REAR){
                FRONT = -1;
                REAR = -1;
            }
            else FRONT += 1;
            return 0;
        }
        void showQueue(){
            cout << "Printing Queue Status: " << endl;
            for (int i = 0; i < MAX; i++){
                cout << arr[i] << ", ";
            }
            cout << endl;
        }
};

int main(){
    Queue myQueue(5);
    cout << "Attempting to Dequeue empty Queue!" << endl;
    myQueue.Dequeue();
    int item;
    cout << "Enter a number to enqueue. "; cin >> item;
    myQueue.Enqueue(item);
    myQueue.showQueue();
    cout << "Now Dequeueing this number : " << myQueue.Dequeue() << endl;
    return 0;
}