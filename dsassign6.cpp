/*
 * Coffee Shop Line (Simple Queue):
 * Arrival: Customers arrive at the coffee shop and stand in line.
 * Order Processing: The first customer in line gets their order taken,
 * and the barista starts making the coffee.
 * Serving: Once the first customer is served, they leave the queue,
 * and the next customer in line moves forward to be served.
 * Write a program to implement a simple queue
*/
#include <iostream>

#define MAXSIZE 10
#define MIN 0

using namespace std;

class Coffee_shop {
    int token[MAXSIZE];
public:
    int rear;
    int front;
    
    Coffee_shop () {
        rear = -1;
        front = -1;
    }
        
    bool isFull();
    bool isEmpty();
    void enQueue(int t);
    int deQueue();
};

bool Coffee_shop::isFull () {
    if (rear == MAXSIZE-1) {
        return 1;
    } else {
        return 0;
    }
}

bool Coffee_shop::isEmpty () {
    if (front == -1 || front == MAXSIZE || rear < front) {
        return 1;
    } else {
        return 0;
    }
}

void Coffee_shop::enQueue (int t) {
    if (isFull()) {
        cout << "Sorry! The order can't be placed\nThe queue is full!" << endl;
    } else {
        if (rear == -1) {
            front = 0;
        }
        rear = rear + 1;
        token[rear] = t;
    }
}

int Coffee_shop::deQueue () {
    if (isEmpty()) {
        cout << "The queue is empty." << endl;
        return 0;
    } else {
        int t = token[front];
        cout << "Order processed for: " << token[front] << endl;
        front += 1;
        return t;
    }
}

int main() {
    Coffee_shop customer;
    int choice = 0, order;
    
    do {
        cout << "Coffee shop menu:" << endl;
        cout << "  1. Add an order\n  2. Delete an order (received)\n  3. Exit\nChoice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                cout << "\nEnter value to be inserted as order: ";
                cin >> order;
                customer.enQueue(order);
                cout << endl;
                break;
            }
            case 2: {
                cout << "\nDeleting:" << endl;
                customer.deQueue();
                cout << endl;
                break;
            }
            case 3: {
                cout << "Thank you!" << endl;
                break;
            }
            default: {
                cout << "\nIncorrect choice! Try again" << endl;
            }
        }
    } while (choice != 3);
    
	return 0;
}

/*
 * Printer Spooler (Circular Queue):
 *In a multi-user environment, printers often use a circular queue to manage print jobs. 
 *Each print job is added to the queue, and the printer processes them in the order they arrive. 
 *Once a print job is completed, it moves out of the queue, 
 *and the next job is processed, efficiently managing the flow of print tasks. 
 *Implement the Printer Spooler system using a circular queue without using built-in queues.
*/

#include <iostream> 

#define MAXSIZE 5
#define MIN 0

using namespace std;

class Printer_spooler {
    int token[MAXSIZE];
public:
    int rear;
    int front;
    
    Printer_spooler () {
        rear = -1;
        front = -1;
    }
        
    bool isFull();
    bool isEmpty();
    void enQueue(int t);
    int deQueue();
    void display();
};

bool Printer_spooler::isFull () {
    if (((rear + 1) % MAXSIZE) == front) {
        return 1;
    } else {
        return 0;
    }
}

bool Printer_spooler::isEmpty () {
    if (front == -1) {
        return 1;
    } else {
        return 0;
    }
}

void Printer_spooler::enQueue (int t) {
    if (isFull()) {
        cout << "Sorry! The printer can't proceed.\nThe queue is full!" << endl;
    } else {
        if (rear == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAXSIZE;
        token[rear] = t;
    }
}

int Printer_spooler::deQueue () {
    if (isEmpty()) {
        cout << "The queue is empty." << endl;
        return 0;
    } else if (front == rear) {
        int t = token[front];
        cout << "Printing job completed for: " << t << endl;
        front = -1;
        rear = -1;
        return t;
    } else {
        int t = token[front];
        cout << "Printing job completed for: " << t << endl;
        front = (front + 1) % MAXSIZE;
        return t;
    }
}


void Printer_spooler::display () {
	cout << "\nDisplaying the queue in printer spooler:" << endl;
	for (int i=0; i < MAXSIZE; i++) {
		cout << "Printing job at " << i << " is: " << token[i] << endl;
	}
}

int main () {
	Printer_spooler customer;
    int choice = 0, order;
    
    do {
        cout << "Printer job menu:" << endl;
        cout << "  1. Add a job\n  2. Delete a job (print received)\n  3. Display\n  4. Exit\nChoice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                cout << "\nEnter value to be inserted as order: ";
                cin >> order;
                customer.enQueue(order);
                cout << endl;
                break;
            }
            case 2: {
                cout << "\nPrinting:" << endl;
                customer.deQueue();
                cout << "\nPrinting job is completed." << endl;
                break;
            }
            case 3: {
				customer.display();
				cout << endl;
				break;
			}
            case 4: {
                cout << "Thank you!" << endl;
                break;
            }
            default: {
                cout << "\nIncorrect choice! Try again" << endl;
            }
        }
    } while (choice != 4);
    
	return 0;
}
