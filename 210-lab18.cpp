#include <iostream>

using namespace std;

struct Node {
    double rating;
    string comment;
    Node* next;
};

void addToTail(Node *&, Node *);

int main() {
    int choice = 0;
    Node *head = nullptr;
    Node *current = new Node;

    cout << "Which linked list method should we use?" << endl;
    cout << "\t[1] New nodes are added at the head of the linked list." << endl;
    cout << "\t[2] New nodes are added at the tail of the linked list." << endl;
    cout << "Choice: ";
    cin >> choice;

    cout << "Enter review rating 0-5: ";
    cin >> current->rating;
    cin.ignore();
    cout << "Enter review comments: ";
    getline(cin, current->comment);
    current->next = nullptr;

    addToTail(head, current);

    current = head; 
    cout << "Review #1:" << current->rating << ", " << current->comment;
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