#include <iostream>
using namespace std;

class Node {
public:
    string task_name;
    int priority;
    int exe_time;
    Node* next;

    Node(string tn, int p, int e) {
        task_name = tn;
        priority = p;
        exe_time = e;
        next = NULL;
    }
    void display() {
      cout<<" The Task "<<task_name<<" Is Scheduled With Priority "<<priority<<" With The Following Execution Time "<<exe_time<<'s'<<endl;    }
};

int main() {
    Node* head = NULL;
    int n;
    string tn;
    int p, e;
    cout << "Enter No Of Tasks: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\n task name: ";
        cin >> tn;
        cout << "task priority : ";
        cin >> p;
        cout << " execution time (in seconds): ";
        cin >> e;

        Node* temp = new Node(tn, p, e);

        if (head == NULL || head->priority < temp->priority) {
            temp->next = head;
            head = temp;
        }
        else {
            Node* prev = head;
            Node* current = head->next;

            while (current != NULL && current->priority >= temp->priority) {
                prev = current;
                current = current->next;
            }

            prev->next = temp;
            temp->next = current;
        }
    }

    // Display the linked list
 
    cout << "The Priority List is as follows:\n\n";
    Node* t = head;
    while (t != NULL) {
        t->display();
        cout << endl;
        t = t->next;
    }

    return 0;
}


