#include<iostream>
using namespace std;

class Node{
  public: 
  int data;
  Node* next;
  Node(int val){
    data = val;
    next = nullptr;
  }
};

class LinkedList{
  private :
  Node * head;
  public : 
  LinkedList(){
    head = nullptr;
  }
  ~LinkedList() {
    Node* temp = head;
    while (temp) {
      Node* next = temp->next;
      delete temp;
      temp = next;
    }
  }

  void insertBeginning(){
    int x;
    cout<<"Enter the value you wanna insert : ";
    cin>>x;
    if(head == nullptr){
      head = new Node(x);
    }
    else{
      Node* temp = new Node(x);
      temp->next = head;
      head = temp;
    }
  }

  void insertEnd(){
    int x;
    cout<<"Enter the value you wanna insert : ";
    cin>>x;
    if(head == nullptr){
      head = new Node(x);
      return;
    }
    Node* temp = head;
    while(temp->next){
      temp = temp->next;
    }
    temp->next = new Node(x);
  }

  void insertBetween(){
    if(head == nullptr || head->next == nullptr){
      cout << "Number of nodes are less than two so insertion in between cannot occur" << endl;
      return;
    }
    int x, y, key;
    cout << "Enter the first key : ";
    cin >> x;
    cout << "Enter the second key : ";
    cin >> y;
    cout << "Enter the value you wanna insert : ";
    cin >> key;
    Node* temp = head;
    bool flag = false;
    while(temp->next){
      if(temp->data == x && temp->next->data == y){
        Node* forward = temp->next;
        temp->next = new Node(key);
        temp->next->next = forward;
        flag = true;
        break; 
      }
      temp = temp->next;
    }
    if(!flag){
      cout << "Can't find any adjacent nodes with first value "<< x << " and second value " << y << endl;
    }
  }


  void deleteBeginning(){
    if(head == nullptr){
      cout<<"Linked List is empty !"<<endl;
      return;
    }
    Node* todelete = head;
    head = head->next;
    cout << "Node at beginning deleted." << endl;
    delete todelete;
  }

  void deleteEnd(){
    if(head == nullptr){
      cout<<"Linked List is empty !"<<endl;
      return;
    }
    else if(head->next == nullptr){
      Node* todelete = head;
      head = nullptr;
      delete todelete;
      cout << "Node at end deleted." << endl;
      return;
    }
    Node * temp = head;
    while(temp->next->next){
      temp = temp->next;
    }
    Node* todelete = temp->next;
    temp->next = nullptr;
    delete todelete;
  }

  void deleteSpecific(){
    if(head == nullptr){
      cout<<"Linked List is empty !"<<endl;
      return;
    }
    int x;
    cout<<"Enter node you wanna delete : ";
    cin>>x;
    if(head->data == x){
      Node* toDelete = head;
      head = head->next;
      delete toDelete;
      cout << "Node with value " << x << " deleted." << endl;
      return;
    }
    Node* temp = head->next;
    Node* prev = head;
    while(temp){
      if(temp->data == x){
        prev->next = temp->next; // unlink the node
        delete temp;
        cout << "Node with value " << x << " deleted." << endl;
        return;
      }
      prev = temp;
      temp = temp->next;
    }
    cout<<"Node did not found "<<endl;
  }

  void searchNode(){
    if(head == nullptr){
      cout<<"Linked List is empty !"<<endl;
      return;
    }
    int x , index = 1;
    cout<<"Enter the value you wanna search : ";
    cin>>x;
    Node* temp = head;
    while(temp && temp->data != x){
      temp = temp->next;
      index++;
    }
    if(temp){
      cout<<"Node is found at index "<<index<<endl;
    }
    else{
      cout<<"Node doesn't exists!"<<endl;
    }
  }

  void display(){//done
    if(head == nullptr){
      cout<<"Linked List is empty ! "<<endl;
      return;
    }
    cout<<"Linked list : "<<endl;
    Node* temp = head;
    while(temp){
      cout<<temp->data<<" ";
      temp = temp->next;
    }
    cout<<endl;
  }
};


int main(){
  int choice;
  LinkedList obj;
  do{
    cout<<"-----Menu------"<<endl;
    cout<<"1. Insertion at the beginning."<<endl;
    cout<<"2. Insertion at the end."<<endl;
    cout<<"3. Insertion in between."<<endl;
    cout<<"4. Deletion from the beginning."<<endl;
    cout<<"5. Deletion from the end."<<endl;
    cout<<"6. Deletion of a specific node."<<endl;
    cout<<"7. Search for a node and display its position from head."<<endl;
    cout<<"8. Display all the node values."<<endl;
    cout<<"9. Exit"<<endl;
    cout<<endl;
    cout<<"Enter choice : ";
    cin>>choice;
    switch(choice){
      case 1 : obj.insertBeginning();
      break;
      case 2 : obj.insertEnd();
      break;
      case 3 : obj.insertBetween();
      break;
      case 4 : obj.deleteBeginning();
      break;
      case 5 : obj.deleteEnd();
      break;
      case 6 : obj.deleteSpecific();
      break;
      case 7 : obj.searchNode();
      break;
      case 8 : obj.display();
      break;
      case 9 : cout<<"Exiting code!"<<endl;
      break;
      default : cout<<"Reenter choice!"<<endl;
    }
  }
  while(choice != 9);

  return 0;
}