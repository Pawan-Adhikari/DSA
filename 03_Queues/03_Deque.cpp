#include <iostream>
using namespace std;

class CircDeque{
    public:
        int* arr;
        int FRONT;
        int REAR;
        int MAX;
        CircDeque(int MAX_){
            arr = new int[MAX_];
            FRONT = -1;
            REAR = -1;
            MAX = MAX_;
        }
        int EnqueueRear(int ITEM){
            if ((FRONT==0 && REAR==MAX-1) || (FRONT==REAR+1)) {
                cout << "Queue Overflow!!" << endl;
                return 1;
            }
            if (FRONT == -1){
                FRONT = 0;
                REAR = 0;
            }
            else if (REAR==MAX-1) REAR=0;
            else REAR += 1;
            arr[REAR] = ITEM;
            return 0;
        }
        int DequeueFront(){
            if (FRONT == -1){
                cout << "Queue Underflow!!" << endl;
                return 1;
            }
            int ITEM = arr[FRONT];
            arr[FRONT]=0;
            if (FRONT == REAR){
                FRONT = -1;
                REAR = -1;
            }
            else if (FRONT==MAX-1) FRONT=0;
            else FRONT += 1;
            return ITEM;
        }
        int EnqueueFront(int ITEM){
            if ((FRONT==0 && REAR == MAX -1) || (FRONT>REAR)){
                cout << "Queue Overflow!!" << endl;
                return 1;
            }
            if (FRONT == -1){
                FRONT = 0;
                REAR = 0;
            }
            else if (FRONT==0) FRONT = MAX - 1;
            else FRONT -= 1;
            arr[FRONT] = ITEM;
            return 0;
        }
        int DequeueRear(){
            if (FRONT == -1){
                cout << "Queue Underflow!!" << endl;
                return 1;
            }
            int ITEM = arr[REAR];
            arr[REAR]=0;
            if (FRONT == REAR){
                FRONT = -1;
                REAR = -1;
            }
            else if (REAR == 0) REAR = MAX - 1;
            else REAR = REAR - 1;
            return ITEM;
        }
        void showQueue(){
            cout << "Printing Queue Status: " << endl;
            for (int i = 0; i < MAX; i++){
                cout << arr[i] << ", ";
            }
            cout << endl;
            cout << "Front at " << FRONT << "\t REAR at " << REAR << endl;
        }
};

int main(){
    int max;
    cout << "Enter Queue Size: "; cin>>max;
    CircDeque myQueue(max);

    cout << "Attempting to Dequeue empty deque from front." << endl;
    myQueue.DequeueFront();

    int item, n;
    cout << "Enter a number to enqueue from rear: "; cin >> item;
    cout << "Enter number of times to enqueue this: "; cin >> n;
    for (int i=0; i<n; i++) myQueue.EnqueueRear(item);

    myQueue.showQueue();

    cout << "Now Dequeueing from front; Enter number of times to dequeue: "; cin >> n;

    for (int i=0; i<n; i++){
        cout << "Dequeued: " << myQueue.DequeueFront() << endl;
    }

    myQueue.showQueue();

    cout << "Enter a number to enqueue from front: "; cin >> item;
    cout << "Enter number of times to enqueue this: "; cin >> n;
    for (int i=0; i<n; i++) myQueue.EnqueueFront(item);

    myQueue.showQueue();

    cout << "Now Dequeueing from rear; Enter number of times to dequeue: "; cin >> n;

    for (int i=0; i<n; i++){
        cout << "Dequeued: " << myQueue.DequeueRear() << endl;
    }

    myQueue.showQueue();

    return 0;
}