#include <iostream>
using namespace std;

class CircQueue{
    public:
        int* arr;
        int FRONT;
        int REAR;
        int MAX;
        CircQueue(int MAX_){
            arr = new int[MAX_];
            FRONT = -1;
            REAR = -1;
            MAX = MAX_;
        }
        int Enqueue(int ITEM){
            if ((REAR + 1)%MAX == FRONT) {
                cout << "Queue Overflow!!" << endl;
                return 1;
            }
            if (FRONT == -1){
                FRONT = 0;
                REAR = 0;
            }
            else REAR = (REAR+1)%MAX;
            arr[REAR] = ITEM;
            return 0;
        }
        int Dequeue(){
            if (FRONT == -1){
                cout << "Queue Underflow!!" << endl;
                return 1;
            }
            int ITEM = arr[FRONT];
            if (FRONT == REAR){
                FRONT = -1;
                REAR = -1;
            }
            else FRONT = (FRONT+1)%MAX;
            return ITEM;
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
    int max;
    cout << "Enter Queue Size: "; cin>>max;
    CircQueue myQueue(max);

    cout << "Attempting to Dequeue empty Queue." << endl;
    myQueue.Dequeue();

    int item, n;
    cout << "Enter a number to enqueue. "; cin >> item;
    cout << "Enter number of times to enqueue this: "; cin >> n;
    for (int i=0; i<n; i++) myQueue.Enqueue(item);

    myQueue.showQueue();

    cout << "Now Dequeueing; Enter number of times to dequeue: "; cin >> n;

    for (int i=0; i<n; i++){
        cout << "Dequeued: " << myQueue.Dequeue() << endl;
    }

    myQueue.showQueue();
    return 0;
}