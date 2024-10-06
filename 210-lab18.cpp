#include <iostream>
#include <limits>

using namespace std;

struct Node {
    double rating;
    string comment;
    Node* next;
};

void addToTail(Node *&, Node *);
void addToHead(Node *&, Node *);
double calcAverage(Node *&);

int main() {
    int choice = 0;
    char repeat = 'Y';
    Node *head = nullptr;
    Node *current = nullptr;

    cout << "Which linked list method should we use?" << endl;
    cout << "\t[1] New nodes are added at the head of the linked list." << endl;
    cout << "\t[2] New nodes are added at the tail of the linked list." << endl;
    cout << "Choice: ";
    while (!(cin >> choice)|| (choice != 1 && choice !=2)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Error Invalid input. Enter 1 or 2: ";
    }
    
    while (repeat == 'Y') {
        current = new Node;

        cout << "Enter review rating 0-5: ";
        while (!(cin >> current->rating)|| current->rating < 0 || current->rating > 5){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Error Invalid input. Enter 1 or 2: ";
        }

        cin.ignore();
        cout << "Enter review comments: ";
        getline(cin, current->comment);
        current->next = nullptr;

        if (choice == 1) {
            addToHead(head, current);
        }
        else if (choice == 2) {
            addToTail(head, current);
        }
        cout << "Enter another review? Y/N: ";
        cin >> repeat;
        repeat = toupper(repeat);
        while (repeat != 'Y' && repeat != 'N') {
            cout << "Error! Please enter Y or N." << endl;
            cin >> repeat;
            repeat = toupper(repeat);
        }
    }

    int count = 1;
    current = head;
    cout << "\nOutputting all reviews:" << endl;
    while(current) {
        cout << "\t> Review #" << count << ": " << current->rating << ": " << current->comment << endl;
        count++;
        current = current->next;
    }
    cout << "\t> Average: " << calcAverage(head);

    return 0;
}

void addToTail(Node *&head, Node *add){
    if (!head){
        head = add;
    }
    else {
        Node *temp = head;
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = add;
    }
    add->next = nullptr;
}

void addToHead(Node *&head, Node *add){
    if (!head){
        head = add;
    }
    else {
        add->next = head;
        head = add;
    }
}

double calcAverage(Node *&head) {
    Node *current = head;
    double total = 0;
    int count = 0;
    while(current) {
        total += current->rating;
        count++;
        current = current->next;
    }
    return (total/count);
}