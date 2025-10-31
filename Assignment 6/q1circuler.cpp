#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node* next;
  Node(int val) {
    data = val;
    next = nullptr;
  }
};

class CircularLL {
  Node* head;
public:
  CircularLL() {
    head = nullptr;
  }

  void insertPosition() {
    int pos, val;
    cout << "Enter the position where you wanna insert : ";
    cin >> pos;
    cout << "Enter the value you wanna insert : ";
    cin >> val;
    Node* newNode = new Node(val);

    if (head == nullptr) {
      if (pos != 1) {
        cout << "List is empty, you can insert only at position 1." << endl;
        delete newNode;
        return;
      }
      head = newNode;
      head->next = head;
      cout << "Value inserted at position 1." << endl;
      return;
    }

    if (pos == 1) {
      Node* temp = head;
      while (temp->next != head)
        temp = temp->next;
      temp->next = newNode;
      newNode->next = head;
      head = newNode;
      cout << "Value inserted at head position." << endl;
      return;
    }

      Node* temp = head;
      int cnt = 1;
      while (temp->next != head && cnt < pos - 1) {
        temp = temp->next;
        cnt++;
      }

      if (cnt != pos - 1) {
        cout << "Invalid position!" << endl;
        delete newNode;
        return;
      }

      newNode->next = temp->next;
      temp->next = newNode;
      cout << "Value inserted at position " << pos << "." << endl;
    }

  void insertAfter() {
    if (head == nullptr) {
      cout << "Linked list is empty." << endl;
      return;
    }
    int node, val;
    cout << "Enter the node after which you wanna insert : ";
    cin >> node;
    cout << "Enter the value you wanna insert : ";
    cin >> val;
    Node* temp = head;
    Node* newNode = new Node(val);
    while (temp->next != head && temp->data != node)
      temp = temp->next;

    if (temp->data != node) {
      cout << node << " not found in linked list." << endl;
      delete newNode;
      return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Value inserted after node " << node << "." << endl;
  }
  void insertBefore() {
    if (head == nullptr) {
      cout << "Linked list is empty." << endl;
      return;
    }
    int node, val;
    cout << "Enter the node before which you wanna insert : ";
    cin >> node;
    cout << "Enter the value you wanna insert : ";
    cin >> val;
    Node* temp = head;
    Node* prev = nullptr;
    Node* newNode = new Node(val);
    if (head->data == node) {
      while (temp->next != head)
        temp = temp->next;
      newNode->next = head;
      temp->next = newNode;
      head = newNode;
      cout << "Value inserted before node " << node << "." << endl;
      return;
    }
    do {
      prev = temp;
      temp = temp->next;
    } while (temp != head && temp->data != node);
    if (temp == head) {
      cout << node << " does not exist in linked list." << endl;
      delete newNode;
      return;
    }
    prev->next = newNode;
    newNode->next = temp;
    cout << "Value inserted before node " << node << "." << endl;
  }

  void deleteNode() {
    if (head == nullptr) {
      cout << "List is empty!" << endl;
      return;
    }
    int val;
    cout << "Enter a value you wanna delete from linked list : ";
    cin >> val;
    if (head->data == val) {
      if (head->next == head) {
        cout << head->data << " was deleted from linked list." << endl;
        delete head;
        head = nullptr;
        return;
      }
      Node* curr = head;
      while (curr->next != head)
        curr = curr->next;
      Node* forward = head->next;
      cout << head->data << " was deleted from linked list." << endl;
      delete head;
      curr->next = forward;
      head = forward;
      return;
    }
    Node* curr = head->next;
    Node* prev = head;
    while (curr != head && curr->data != val) {
      prev = curr;
      curr = curr->next;
    }
    if (curr == head) {
      cout << "Value does not exist." << endl;
      return;
    }
    prev->next = curr->next;
    cout << curr->data << " was deleted from linked list." << endl;
    delete curr;
  }
  void search() {
    if (head == nullptr) {
      cout << "List is empty!" << endl;
      return;
    }
    int val;
    cout << "Enter value you wanna search : ";
    cin >> val;
    Node* curr = head;
    do {
      if (curr->data == val) {
        cout << "Value exists in linked list." << endl;
        return;
      }
      curr = curr->next;
    } while (curr != head);
    cout << "Value doesn't exist." << endl;
  }
  void display() {
    if (head == nullptr) {
      cout << "List is empty!" << endl;
      return;
    }
    Node* temp = head;
    cout << "Circular Linked List: ";
    do {
      cout << temp->data << " -> ";
      temp = temp->next;
    } while (temp != head);
    cout << "(back to head)" << endl;
  }
};

int main() {
  CircularLL list;
  int choice;
  do {
    cout << "\n---Menu---" << endl;
    cout << "1. Insert at a specific position" << endl;
    cout << "2. Insert after specific node" << endl;
    cout << "3. Insert before specific node" << endl;
    cout << "4. Delete a specific node" << endl;
    cout << "5. Search for a node" << endl;
    cout << "6. Display list" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter choice : ";
    cin >> choice;

    switch (choice) {
      case 1: list.insertPosition(); break;
      case 2: list.insertAfter(); break;
      case 3: list.insertBefore(); break;
      case 4: list.deleteNode(); break;
      case 5: list.search(); break;
      case 6: list.display(); break;
      case 7: cout << "Exiting the program..." << endl; break;
      default: cout << "Invalid choice! Try again." << endl;
    }
  } while (choice != 7);

  return 0;
}
