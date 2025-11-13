#include <iostream>
using namespace std;
struct Node {
    string data;
    Node* next_ptr;
    
};
class Queue {
    private:
    Node* head;
    Node* tail;
    int size;
    int capacity;
    
    public:
    Queue(int maxCapacity) {
        head = nullptr;
        tail = nullptr;
        size = 0;
        capacity = maxCapacity;
    }

    void enqueue(string value) {
        if (isFull()) {
            cout << "Queue overflow! cannot enqueue\n";
            return;
        }
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next_ptr = nullptr;
        if (isEmpty()) {
            // If queue is empty, both head and tail point to new node
            head = newNode;
            tail = newNode;
        } else {
            // Add new node at the end and update tail
            tail->next_ptr = newNode;
            tail = newNode;
        }
        size++;
        cout << "\nEnqueued: " << value << endl;
    }

    void dequeue(){
        if (isEmpty()) {
            cout << "Queue underflow! Cannot dequeue\n";
            return;
        }
        string dequeued = head->data;
        head = head->next_ptr;
        
        if(head == nullptr){ //if stack becomes empty the tail will be null
            tail = nullptr;
        }
        size--;
        cout << "\nDequeued value: "<<dequeued<<endl;
    }

    void front(){
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "\nFront element: " << head->data << endl;
    }
    void rear(){
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "\nRear element: " << tail->data << endl;
    }
    bool isFull() {
        return size >= capacity;
    }
    bool isEmpty() {
        return head == nullptr;
    }

    void display() {
        if (isEmpty()) {
            cout << "\nQueue is empty!" << endl;
            return;
        }
        cout << "\nQueue elements (front to rear): \n";
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next_ptr;
        }
        cout << endl;
    }

    int getCurrentSize() {
        return size;
    }

    int getMaxSize() {
        return capacity;
    }
};

int main() {
    int queue_size;
    int option;
    string value;
    cout << "Enter Queue size: ";
    cin >> queue_size;
    Queue myQueue(queue_size);
    
    while(option!=8){
        cout << "\n1. Enqueue\n2. Dequeue\n3. Front\n4. Rear\n5. Check if queue is full\n6. Check if queue is empty\n7. Display Queue\n8. EXIT\nEnter option: ";
        cin >> option;
        if(option == 1) {
            cout << "Enter value to enqueue: ";
            cin >> value;
            myQueue.enqueue(value);
        } else if(option == 2) {
            myQueue.dequeue();
        } else if(option == 3) {
            myQueue.front();
        } else if(option == 4) {
            myQueue.rear();
        } else if(option == 5) {
            if(myQueue.isFull()) {
                cout << "\nQueue is FULL";
            } else {
                cout << "\nQueue is NOT FULL";
            }
            cout << "\nCurrent Size: " << myQueue.getCurrentSize() << " Max Capacity: " << myQueue.getMaxSize() << endl;
        } else if(option == 6) {
            if(myQueue.isEmpty()) {
                cout << "\nQueue is EMPTY";
            } else {
                cout << "\nQueue is NOT Empty";
            }
            cout << "\nCurrent Size: " << myQueue.getCurrentSize() << " Max Capacity: " << myQueue.getMaxSize() << endl;
        } else if(option == 7) {
            myQueue.display();
        } else if(option == 8) {
            break;
        } else {
            cout << "\nInvalid option\n";
        }
    }  
    return 0;
}