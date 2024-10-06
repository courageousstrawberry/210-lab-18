#include <iostream>

using namespace std;

struct Node {
    double rating;
    string comment;
    Node* next;
};

void addToTail(Node *, Node);

int main() {
    int choice = 0;
    Node *head = nullptr;
    Node *current = nullptr;

    cout << "Which linked list method should we use?" << endl;
    cout << "\t[1] New nodes are added at the head of the linked list." << endl;
    cout << "\t[2] New nodes are added at the tial of the linked list." << endl;
    cout << "Choice: ";
    cin >> choice;

    cout << "Enter review rating 0-5: ";
    cin >> current->rating;
    cout << "Enter review comments: ";
    cin >> current->comment;


    return 0;
}

void addToTail(Node *head, Node *add){
    if (!head){
        head->rating = add->rating;
        head->comment = add->comment;
        head->next = nullptr;
    }
    else {
        
    }
}