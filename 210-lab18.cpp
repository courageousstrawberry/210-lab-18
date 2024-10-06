#include <iostream>

using namespace std;

struct Node {
    double rating;
    string comment;
    Node* next;
};

void addToTail(Node *head, Node tail);

int main() {
    int choice = 0;

    cout << "Which linked list method should we use?" << endl;
    cout << "\t[1] New nodes are added at the head of the linked list." << endl;
    cout << "\t[2] New nodes are added at the tial of the linked list." << endl;
    cout << "Choice: ";
    cin >> choice;

    

    return 0;
}