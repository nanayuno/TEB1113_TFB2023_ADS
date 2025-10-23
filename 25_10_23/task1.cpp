#include <iostream>
#include <string> 
#include <limits> 

using namespace std;

struct Node {
    string data;
    Node* next_ptr;
};

class Stack {
private:
    Node* top; 

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        cout << "\nDestructor called: Cleaning up all nodes..." << endl;
        Node* current = top;
        Node* nextNode = nullptr;
        while (current != nullptr) {
            nextNode = current->next_ptr;
            cout << "Deleting " << current->data << endl;
            delete current;
            current = nextNode;
        }
    }

    /**
     * @brief Checks if the stack is empty.
     * @return true if the stack is empty, false otherwise.
     */
    bool isEmpty() {
        return (top == nullptr);
    }

    /**
     * @brief Checks if the stack is full.
     * @return false, as a linked-list stack is only limited by system memory.
     */
    bool isFull() {
        return false;
    }

    /**
     * @brief Adds an item to the top of the stack.
     * @param val The string value to push onto the stack.
     */
    void push(string val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next_ptr = top;
        top = newNode;
        cout << "'" << val << "' pushed to stack." << endl;
    }

    /**
     * @brief Removes the top item from the stack.
     */
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return;
        }
        
        Node* temp = top;
        string poppedValue = top->data;
        top = top->next_ptr;
        delete temp;
        
        cout << "'" << poppedValue << "' popped from stack." << endl;
    }

    /**
     * @brief Returns the value of the top item without removing it.
     * @return The string data from the top node.
     */
    string peek() {
        if (isEmpty()) {
            cout << "Stack is empty! Nothing to peek." << endl;
            return ""; // Return an empty string as an error/empty indicator
        }
        return top->data;
    }
};

// --- NEW MAIN FUNCTION ---
// This main() function provides a user menu
int main() {
    Stack s;
    int choice;
    string value;

    // std::boolalpha prints "true/false" instead of "1/0"
    cout << boolalpha; 

    do {
        cout << "\n--- Stack Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Check if Empty" << endl;
        cout << "5. Check if Full" << endl;
        cout << "0. Exit" << endl;
        cout << "------------------" << endl;
        cout << "Enter your choice: ";

        // Get user choice
        cin >> choice;

        // Check if the input failed (e.g., user entered 'a' instead of a number)
        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear(); // Clear the error flag
            // Discard the invalid input
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            choice = -1; // Set to an invalid choice to loop again
        } else {
            // This is crucial:
            // cin >> choice leaves a newline character (\n) in the input buffer.
            // We must clear it before using getline(), or getline() will
            // instantly read the empty newline and skip user input.
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }


        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                // Use getline to allow strings with spaces
                getline(cin, value); 
                s.push(value);
                break;
            
            case 2:
                s.pop();
                break;
            
            case 3:
                value = s.peek();
                if (!s.isEmpty()) {
                    cout << "Top element is: " << value << endl;
                }
                break;
            
            case 4:
                cout << "Is stack empty? " << s.isEmpty() << endl;
                break;
            
            case 5:
                cout << "Is stack full? " << s.isFull() << endl;
                break;
            
            case 0:
                cout << "Exiting program..." << endl;
                break;
            
            default:
                if (choice != -1) { // Don't print for cin.fail() cases
                   cout << "Invalid choice. Please try again." << endl;
                }
                break;
        }
    } while (choice != 0);

    return 0; // Destructor will automatically be called here
}